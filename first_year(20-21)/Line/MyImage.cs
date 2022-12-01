#pragma warning disable CA1416 // Проверка совместимости платформы
using System;
using System.Diagnostics;
using System.Drawing;


namespace Line
{
    class MyImage
    {
        private Bitmap _bitmap;

        public int Width => _bitmap.Width;

        public int Height => _bitmap.Height;

        public Color this[int x, int y]
        {
            set
            {
                _bitmap.SetPixel(x, y, value);
            }
            get
            {
                return _bitmap.GetPixel(x, y);
            }

        }

        public MyImage(string path)
        {
            try
            {
                Image image = Image.FromFile(path);
                _bitmap = CreateNonIndexedImage(image, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
            }
            catch
            {
                Console.WriteLine("There was an error. Check the path to the image file");
                Process.GetCurrentProcess().Kill();
            }
        }

        public MyImage(MyImage image, Size size) => 
            _bitmap = new Bitmap(image._bitmap, size);

        public void Save(String FilePath)
        {
            try
            {
                _bitmap.Save(FilePath);
            }
            catch
            {
                Console.WriteLine("File_Save_Mistacke");
            }

        }

        private Bitmap CreateNonIndexedImage(Image src, System.Drawing.Imaging.PixelFormat pixelFormat)
        {
            Bitmap newBmp = new Bitmap(src.Width, src.Height, pixelFormat);

            using (Graphics gfx = Graphics.FromImage(newBmp))
            {
                gfx.DrawImage(src, 0, 0);
            }

            return newBmp;
        }

    }
}
