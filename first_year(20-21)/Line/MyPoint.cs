using System;
using System.Collections.Generic;

namespace Line
{
    public enum Direction {None, Right, Up, Down, Left, TopLeft, BottomLeft, TopRight, BottomRight };
    class MyPoint
    {
        public bool IsControversialPoint { get => _isControversialPoint; set { _isControversialPoint = value; } }

        public Direction Direction { get => _direction;  set { _direction = value; } }

        public int X => _x;

        public int Y => _y;

        private int _x, _y;

        private Direction _direction;

        private bool _isControversialPoint;

        public MyPoint(int x, int y)
        {
            _x = x;
            _y = y;
        }

        public List<Tuple<int, int>> GetNeighbours(List<Tuple<int, int>> points)
        {
            List<Tuple<int, int>> neighbours = new List<Tuple<int, int>>();
            double minDistance = this.GetMinDistance(points);

            foreach (var item in points)
            {
                double distance = Math.Sqrt(Math.Pow(this.X - item.Item1, 2) + Math.Pow(this.Y - item.Item2, 2));
                if (minDistance == distance)
                {
                    neighbours.Add(item);
                    if (minDistance > Math.Sqrt(2))
                        break;
                }
            }
            return neighbours;
        } 

        private  double GetMinDistance(List<Tuple<int, int>> points)
        {
            double minDistance = 9999;

            foreach (var item in points)
            {
                if (item.Item1 != this.X || item.Item2 != this.Y)
                {
                    double distance = Math.Sqrt(Math.Pow(this.X - item.Item1, 2) + Math.Pow(this.Y - item.Item2, 2));
                    if (minDistance > distance)
                        minDistance = distance;
                    if (minDistance == 1)
                        break;
                }
            }
            return minDistance;
        }
    }
}
