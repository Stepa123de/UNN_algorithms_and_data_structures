using System;
using System.Collections.Generic;
using System.Drawing;


namespace Line
{
    class Line
    {
        private int _widthLine;

        public int Width { get { return _widthLine; } }

        public Line(MyImage image)
        {
            _widthLine = FoundWidthLine(image, ColorBorders.Default);
        }

        private int FoundWidthLine(MyImage image, ColorBorders colorBorders)
        {
            List<int> widthsLine = new List<int>();
            for (int i = 0; i < image.Width; i++)
                widthsLine.Add(0);

            for (int y = 0; y < image.Width; y++)
            {
                int tempWidthLine = 0;
                for (int x = 0; x < image.Height; x++)
                {
                    Color pixelColor = image[y, x];
                    if (pixelColor < colorBorders)
                        tempWidthLine++;
                    else if (tempWidthLine > widthsLine[y])
                        widthsLine[y] = tempWidthLine;
                    else
                        tempWidthLine = 0;
                }
            }

            return FoundMaxFrequencyElement(image, widthsLine);

        }

        private int FoundMaxFrequencyElement(MyImage image, List<int> list)
        {
            List<int> frequencyWidthsLine = new List<int>();
            for (int i = 0; i < image.Width; i++)
                frequencyWidthsLine.Add(0);

            foreach (var item in list)
            {
                frequencyWidthsLine[item]++;
            }

            int indexMaxElement = 1;
            for (int i = 1; i < frequencyWidthsLine.Count; i++)
            {
                if (frequencyWidthsLine[i] > frequencyWidthsLine[indexMaxElement])
                    indexMaxElement = i;
            }

            return indexMaxElement;
        }
    }
}
