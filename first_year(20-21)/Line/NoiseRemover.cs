using System;
using System.Collections.Generic;
using System.Drawing;

namespace Line
{
    public struct ColorBorders
    {
        public int Red;
        public int Green;
        public int Blue;

        public static ColorBorders Default = new ColorBorders(10, 10, 10);
        public static ColorBorders Half = new ColorBorders(128, 128, 128);
        public static ColorBorders СhineseSilver = new ColorBorders(200, 200, 200);

        public ColorBorders(int topBorderRed, int topBorderGreen, int topBorderBlue)
        {
            Red = topBorderRed;
            Green = topBorderGreen;
            Blue = topBorderBlue;
        }

        public static bool operator >(Color color, ColorBorders colorBorders) =>
            (color.R > colorBorders.Red && color.G > colorBorders.Green && color.B > colorBorders.Blue);
        public static bool operator <(Color color, ColorBorders colorBorders) =>
           (color.R < colorBorders.Red && color.G < colorBorders.Green && color.B < colorBorders.Blue);

    }
    class NoiseRemover
    {
        private int _widthLine;
        public NoiseRemover(int width)
        {
            _widthLine = width;
        }

        public void RemoveUnwantedColors(MyImage image, ColorBorders colorBorders)
        {
            for (int i = 0; i < image.Width; i++)
            {
                for (int j = 0; j < image.Height; j++)
                {
                    Color pixelColor = image[i, j];
                    Color newPixelColor;
                    
                    if (pixelColor < colorBorders)   
                        newPixelColor = Color.Black;
                    else
                        newPixelColor = Color.White;
                    image[i, j] = newPixelColor;
                }
            }
        }

        public void RemoveNoise(MyImage image, List<Tuple<int, int>> blackPixel, ColorBorders colorBorders)
        {
            for (int i = 0; i < image.Width; i++)
            {
                for (int j = 0; j < image.Height; j++)
                {
                    bool flag = false;
                    foreach (var item in blackPixel)
                    {
                        float coefficient = 1.25f;
                        if ((item.Item1 - _widthLine * coefficient < i && i < item.Item1 + _widthLine * coefficient) 
                            && (item.Item2 - _widthLine * coefficient < j && j < item.Item2 + _widthLine * coefficient))
                        {
                            flag = true;
                            break;
                        }
                    }

                    int radius = _widthLine / 2;
                    if (flag == false)
                        image[i, j] = Color.White;

                    SpotRemoveNoise(image, i, j, colorBorders);

                }
            }
        }

        public bool SpotRemoveNoise(MyImage image, int x, int y, ColorBorders colorBorders, float probability = 0.35f)
        {
            if (x < 0 || x > image.Width - 1 || y < 0 || y > image.Height - 1)
                return false;

            Color pixelColor = image[x, y];
            if (pixelColor < colorBorders)
            {
                int colorAroundCount = GetColorAroundCounts(image, x, y, _widthLine / 2, colorBorders);

                var temp = colorAroundCount / (float)((_widthLine) * (_widthLine));
                if (temp < probability)
                {
                    image[x, y] = Color.White;
                    return true;
                }
            }
            return false;
        }

        private static int GetColorAroundCounts(MyImage image, int x, int y, int radius, ColorBorders colorBorders)
        {
            int ans = 0;
            for (int i = x - radius; i < x + radius; i++)
            {
                for (int j = y - radius; j < y + radius; j++)
                {
                    if (i < 0 || j < 0 || i > image.Width - 1 || j > image.Height - 1)
                        continue;

                    Color pixelColor = image[i, j];
                    if (pixelColor < colorBorders) 
                        ans++;
                }
            }
            return ans;
        }
    }
}
