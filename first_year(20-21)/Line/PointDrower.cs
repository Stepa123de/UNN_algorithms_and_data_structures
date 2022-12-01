using System;
using System.Collections.Generic;
using System.Drawing;

namespace Line
{
    class PointDrower
    {
        private static NoiseRemover _removeNoise;
        private MyImage _image;

        public void DrawPointMethod1(MyImage image, Line line, List<Tuple<int, int>> points)
        {
            _removeNoise = new NoiseRemover(line.Width);
            _image = image;

            for (int k = 0; k < points.Count; k++)
            {
                int x = points[k].Item1;
                int y = points[k].Item2;

                if (x > image.Width - 1 || y > image.Height - 1)
                    continue;

                Color pixelColor = image[x, y];

                if (pixelColor > ColorBorders.Default)
                    points[k] = ErrorCorrection(line.Width, x, y);

                DrawRedPoints(points[k].Item1, points[k].Item2);

                if (RemoveErroneousRedPoint(points[k].Item1, points[k].Item2))
                        points[k] = new Tuple<int, int>(-1, -1);

            }
        }

        private Tuple<int, int> ErrorCorrection(int widthLine, int x, int y)
        {
            for (int i = x - widthLine; i < x + widthLine + 1; i += widthLine)
            {
                for (int j = y - widthLine; j < y + widthLine + 1; j += widthLine)
                {
                    if (i > _image.Width - 1 || i < 0 || j > _image.Height || j < 0)
                        continue;
                    Color pixelColor = _image[i, j];
                    if (pixelColor < ColorBorders.Default)
                        return new Tuple<int, int>(i, j);
                }
            }
            return new Tuple<int, int>(x, y);
        }

        private void DrawRedPoints(int x, int y)
        {
            for (int i = x - 1; i < x + 2; i++)
            {
                for (int j = y - 1; j < y + 2; j++)
                {
                    if (i > 0 && j > 0 && i < _image.Width && j < _image.Height)
                        _image[i, j] = Color.Red;
                }
            }
        }

        private bool RemoveErroneousRedPoint(int x, int y)
        {
            bool flag = false;
            for (int i = x - 1; i < x + 2; i++)
            {
                for (int j = y - 1; j < y + 2; j++)
                {
                    if (_removeNoise.SpotRemoveNoise(_image, i, j, new ColorBorders(256, 10, 10)))
                        flag = true;
                }
            }
            return flag;
        }

        public List<Tuple<int, int>> DrawPointMethod2(MyImage image, Line line, int step = 1)
        {
            _removeNoise = new NoiseRemover(line.Width);
            _image = image;
            List<Tuple<int, int>> points = new List<Tuple<int, int>>();

            for (int i = line.Width / 2; i < image.Width - line.Width / 2; i += step)
            {
                for (int j = line.Width / 2; j < image.Height - line.Width / 2; j += step)
                {
                    if (InsideLine(i, j, line.Width))
                    {
                        points.Add(new Tuple<int, int>(i, j));
                        _image[i, j] = Color.Red;
                    }
                }

            }

            for (int k = 0; k < points.Count; k++)
            {
                if (RemoveErroneousRedPoint(points[k].Item1, points[k].Item2))
                    points[k] = new Tuple<int, int>(-1, -1);
            }

            return points;
        }

        private bool InsideLine(int x, int y, int lineWidth)
        {
            List<Tuple<int, int>> points = Points(x, y, lineWidth);
            foreach (var item in points)
            {
                if (_image[item.Item1, item.Item2] > ColorBorders.Default)
                    return false;
            }
            return true;
        }

        private List<Tuple<int, int>> Points(int x, int y, int lineWidth)
        {
            List<Tuple<int, int>> point = new List<Tuple<int, int>>();
            for (int i = x - lineWidth / 2; i < x + lineWidth / 2; i++)
            {
                for (int j = y - lineWidth / 2; j < y + lineWidth / 2; j++)
                {
                    if (InsideAstroid(i, j, x, y, lineWidth / 2) == true)
                        point.Add(new Tuple<int, int>(i, j));
                }
            }
            return point;
        }

        private bool InsideAstroid(int x, int y, int x0, int y0, int radius) => 
            Math.Pow((x - x0), 2 / 3f) + Math.Pow((y - y0), 2 / 3f) <= Math.Pow(radius, 2 / 3f);
    }

}

