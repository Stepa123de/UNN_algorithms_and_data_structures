#pragma warning disable CA1416 // Проверка совместимости платформы
using System;
using System.Collections.Generic;
using System.Drawing;

namespace Line
{
    class Program
    {
        private const string FilePath = @"Line(ex9).png";

        private static NoiseRemover _removeNoise;

        private static MyImage _startImage;
        private static MyImage _tempImage;

        private static Line _line;

        private static PointDrower _pointDrower;

        private static List<Tuple<int, int>> _anchorkPixelFirstMethod;
        private static List<Tuple<int, int>> _anchorPixelSecondMethod;


        static void Main(string[] args)
        {
            _anchorkPixelFirstMethod = new List<Tuple<int, int>>();

            _startImage = new MyImage(FilePath);

            _line = new Line(_startImage);

            _removeNoise = new NoiseRemover(_line.Width);

            _pointDrower = new PointDrower();

            _removeNoise.RemoveUnwantedColors(_startImage, ColorBorders.Default);

            Size newSize = new Size((_startImage.Width / _line.Width + 1), (_startImage.Height /_line.Width + 1));
            _tempImage = new MyImage(_startImage, newSize);

            _removeNoise.RemoveUnwantedColors(_tempImage, ColorBorders.Half);

            GetAnchorPoints(_tempImage, _line.Width, _anchorkPixelFirstMethod);

            _removeNoise.RemoveNoise(_startImage, _anchorkPixelFirstMethod, ColorBorders.Default);


            MyImage _copyStartImage = new MyImage(_startImage, new Size(_startImage.Width, _startImage.Height));

            //_anchorPixelSecondMethod = _pointDrower.DrawPointMethod2(_copyStartImage, _line);
            //RemoveTrash(_anchorPixelSecondMethod);


            _tempImage = new MyImage(_startImage, newSize);
            _removeNoise.RemoveUnwantedColors(_tempImage, ColorBorders.Half);

            List<Tuple<int, int>> lineSkeleton = new List<Tuple<int, int>>();
            GetAnchorPoints(_tempImage, 0, lineSkeleton);

            int pointCount = lineSkeleton.Count;
            List<MyPoint> points = new List<MyPoint>();
            points.Add(new MyPoint(lineSkeleton[0].Item1, lineSkeleton[0].Item2));
            lineSkeleton.Remove(lineSkeleton[0]);
            MyPoint lastPoint = new MyPoint(lineSkeleton[lineSkeleton.Count - 1].Item1, lineSkeleton[lineSkeleton.Count - 1].Item2);

            
            while (points.Count < pointCount * 0.95)
            {
                FillPoints(points, new ColorBorders(0, 0, 0));

                ReturnToLastСontroversialPoint(points, lineSkeleton);

                for (int i = points.Count - 1; i < points.Count && i > -1; i++)
                {
                    if (points[i].X == lastPoint.X && points[i].Y == lastPoint.Y)
                        break;

                    List<Tuple<int, int>> neighbours = points[i].GetNeighbours(lineSkeleton);

                    if (neighbours.Count == 1)
                    {
                        points.Add(new MyPoint(neighbours[0].Item1, neighbours[0].Item2));
                        lineSkeleton.Remove(neighbours[0]);
                    }
                    else
                    {
                        if (points[i].Direction != Direction.None)
                            points[i].IsControversialPoint = false;
                        else if (neighbours.Count > 1)
                            points[i].IsControversialPoint = true;

                        Tuple<Tuple<int, int>, Direction> nextPoint = GetNextPoint(points[i], neighbours, points[i].Direction);

                        if (nextPoint != null)
                        {
                            points.Add(new MyPoint(nextPoint.Item1.Item1, nextPoint.Item1.Item2));
                            lineSkeleton.Remove(nextPoint.Item1);
                            points[i].Direction = nextPoint.Item2;
                        }
                    }
                }
            }
          
            int k = 0;
            foreach (var item in points)
            {
                _tempImage[item.X, item.Y] = Color.FromArgb(255 - k, k, 0);
                k += 1;
            }

            _anchorkPixelFirstMethod.Clear();
            foreach (var item in points)
            {
                _anchorkPixelFirstMethod.Add(new Tuple<int, int>(item.X * _line.Width, item.Y * _line.Width ));
            }

            for (int i = 1; i < _anchorkPixelFirstMethod.Count; i++)
            {
                int x = _anchorkPixelFirstMethod[i - 1].Item1;
                int y = _anchorkPixelFirstMethod[i - 1].Item2;
                int deltaX = _anchorkPixelFirstMethod[i].Item1 - x;
                int deltaY = _anchorkPixelFirstMethod[i].Item2 - y;

                while (x != _anchorkPixelFirstMethod[i].Item1)
                {
                    _startImage[x, y] = Color.Red;
                    x += deltaX / Math.Abs(deltaX);
                }

                while (y != _anchorkPixelFirstMethod[i].Item2)
                {
                    _startImage[x, y] = Color.Red;
                    y += deltaY / Math.Abs(deltaY);
                }
            }

            //_pointDrower.DrawPointMethod1(_startImage, _line, _anchorkPixelFirstMethod);

            _tempImage.Save("TempImage/Temp" + FilePath);
            _startImage.Save("FinishImage/First" + FilePath);
            _copyStartImage.Save("FinishImage/Second" + FilePath);
        }

        private static void FillPoints(List<MyPoint> points, ColorBorders color)
        {
            foreach (var item in points)
                _tempImage[item.X, item.Y] = Color.FromArgb(color.Red, color.Green, color.Blue);
        }

        private static void ReturnToLastСontroversialPoint(List<MyPoint> points, List<Tuple<int, int>> lineSkeleton)
        {
            for (int i = points.Count - 1; i > 0; i--)
            {
                if (points[i].IsControversialPoint)
                    break;
                lineSkeleton.Add(new Tuple<int, int>(points[i].X, points[i].Y));
                points.RemoveAt(i);
            }
        }

        private static Tuple<Tuple<int, int>, Direction> GetNextPoint(MyPoint mainPoint, List<Tuple<int, int>> neighbours, Direction direction = Direction.None)
        {
            if (direction != Direction.Right)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X + 1 == item.Item1 && mainPoint.Y == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.Right);
                }

            if (direction != Direction.Up)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X == item.Item1 && mainPoint.Y - 1 == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.Up);
                }

            if (direction != Direction.Down)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X == item.Item1 && mainPoint.Y + 1 == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.Down);
                }

            if (direction != Direction.Left)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X - 1 == item.Item1 && mainPoint.Y == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.Left);
                }

            if (direction != Direction.TopRight)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X + 1 == item.Item1 && mainPoint.Y - 1 == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.TopRight);
                }

            if (direction != Direction.BottomRight)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X + 1 == item.Item1 && mainPoint.Y - 1 == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.BottomRight);
                }

            if (direction != Direction.TopLeft)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X - 1 == item.Item1 && mainPoint.Y - 1 == item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.TopLeft);
                }

            if (direction != Direction.BottomLeft)
                foreach (var item in neighbours)
                {
                    if (mainPoint.X - 1 == item.Item1 && mainPoint.Y + 1== item.Item2)
                        return new Tuple<Tuple<int, int>, Direction>(item, Direction.BottomLeft);
                }

            return null;
        }

        private static void GetAnchorPoints(MyImage image, int coefficient, List<Tuple<int, int>> blackPixel)
        {
            for (int i = 0; i < image.Width; i++)
            {
                for (int j = 0; j < image.Height; j++)
                {
                    Color pixelColor = image[i, j];
                    if (pixelColor < ColorBorders.СhineseSilver)
                        if (coefficient != 0)
                            blackPixel.Add(new Tuple<int, int>(i * coefficient + 1, j * coefficient + 1));
                        else
                            blackPixel.Add(new Tuple<int, int>(i, j));
                }
            }
        }

        private static void RemoveTrash(List<Tuple<int, int>> anchorPixel) =>
            anchorPixel.RemoveAll(trash => (trash.Item1 == -1 || trash.Item1 == -1));
    }
}