using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_2
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        public static double[][] GetData(int a, int b, int m)
        {
            double[][] XY = new double[2][];
            double x;
            XY[0] = new double[m];
            XY[1] = new double[m];
            for (int i = 0; i < m; i++)
            {
                x = a + i * (double)(b - a) / m;
                XY[0][i] = x;
                XY[1][i] = Math.Log(x) - 5 * Math.Sin(x) * Math.Sin(x);
                //Math.Sin(x) * Math.Sin(x) - x / 5;
            }

            Console.WriteLine("\nЗначения исходной функциии:\n");
            for (int i = 0; i < m; i++)
            {
                Console.Write($"X_{i + 1} = {XY[0][i]}");
                Console.WriteLine($"\tY_{i + 1} = {XY[1][i]}");
            }
            //  Console.ReadKey();
            return XY;
        }

        public static double Delta(double y_i, double y_i_plus, double x_i, double x_i_plus)
        {
            return (double)(y_i - y_i_plus) / (x_i - x_i_plus);
        }

        public static double N1(double x_t, double x_i, double y_i, double x_i_minus, double y_i_minus)
        {
            return y_i_minus + (x_t - x_i_minus) * Delta(y_i, y_i_minus, x_i, x_i_minus);
        }

        public static double[] PNL(double[] XT, double[][] XY, int m)
        {
            double[] YT = new double[21];
            int j = 0;
            foreach (var xt in XT)
            {
                if (xt >= XY[0][0] && xt <= XY[0][m - 1])
                {
                    int i = 1;

                    for (; xt > XY[0][i]; i++) ;

                    YT[j++] = N1(xt, XY[0][i], XY[1][i], XY[0][i - 1], XY[1][i - 1]);
                    /* + (xt - XY[0][i-1])*(xt - XY[0][i])*(Delta(XY[1][i-1], XY[1][i], XY[0][i - 1], XY[0][i]) - Delta(XY[1][i], XY[1][i + 1], XY[0][i], XY[0][i + 1]))/(XY[0][i - 1] - XY[0][i + 1])*/
                }
            }

            return YT;
        }

        public static void Task()
        {
            Console.Clear();
            const int a = 3, b = 6, m = 11;
            double[][] XY = null;
            double[][] F2 = null;
            double[][] Fi = new double[2][];

            XY = GetData(a, b, m);
            F2 = GetData(a, b, 21);

            Fi[0] = new double[21];
            for (int i = 0; i < 21; i++)
            {
                Fi[0][i] = F2[0][i];
            }
            Fi[1] = PNL(F2[0], XY, m);

            Console.WriteLine("\nЗначения погрешности:\n");
            for (int i = 0; i < 21; i++)
            {
                double dif = F2[1][i] - Fi[1][i];
                Console.WriteLine($"d(X_{i + 1}) = {dif}");
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm_2(Fi));

            Console.ReadLine();
            Console.Clear();
        }
    }
}
