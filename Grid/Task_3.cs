using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_3
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        public static double Fun(double x)
        {
            return Math.Log(x) - 5 * Math.Pow(Math.Sin(x), 2);
        }

        public static double D1F(double x, Func<double, double> fun, double h)
        {
            return (fun(x + h) - fun(x - h)) / (2 * h);
        }

        public static double D2F(double x, Func<double, double> fun, double h)
        {
            return (fun(x + h) - 2 * fun(x) + fun(x - h)) / Math.Pow(h, 2);
        }

        public static double D1FT(double x)
        {
            return 1 / x - 5 * Math.Sin(2 * x);
        }

        public static double D2FT(double x)
        {
            return -1 / Math.Pow(x, 2) - 10 * Math.Cos(2 * x);
        }

        public static double Gauss3(double a, double b, int n, Func<double, double> fun)
        {
            double s = 0, h, x;
            h = (b - a) / n;
            x = a;
            for (int i = 0; i < n; i++)
            {
                s += (double)5 / 9 * fun(x + h / 2 * (1 - 0.7745966692)) + (double)8 / 9 * fun(x + h / 2) + (double)5 / 9 * fun(x + h / 2 * (1 + 0.7745966692));
                x += h;
            }
            return s * h / 2;
        }

        public static void Task()
        {
            Console.Clear();
            const int a = 3, b = 6;
            int[] M = { 10, 20, 40 };
            double[] h = { 0.2, 0.1, 0.05 };

            double x, y, d1 = 0, d2 = 0, d1t = 0, d2t = 0, delta_1 = 0, delta_2 = 0, sum;
            double[,] F_xy = new double[2, 21];
            double[] D1_y = new double[21];
            double[] D2_y = new double[21];
            double[] D1T_y = new double[21];
            double[] D2T_y = new double[21];
            double[] Delta_1_y = new double[21];
            double[] Delta_2_y = new double[21];

            for (int j = 0; j < 21; j++)
            {
                x = a + j * (b - a) / 20.0;
                y = Fun(x);

                F_xy[0, j] = x;
                F_xy[1, j] = y;

                Console.WriteLine($"X = {x}\tY = {y}");

                foreach (double hp in h)
                {
                    Console.WriteLine($"Hp = {hp}\n");

                    d1 = D1F(x, Fun, hp);
                    d2 = D2F(x, Fun, hp);
                    d1t = D1FT(x);
                    d2t = D2FT(x);
                    delta_1 = d1t - d1;
                    delta_2 = d2t - d2;

                    Console.WriteLine($"d1 = {d1}\td1t = {d1t}\t delta_1 = {delta_1}");
                    Console.WriteLine($"d2 = {d2}\td2t = {d2t}\t delta_2 = {delta_2}\n");
                }

                D1_y[j] = d1;
                D2_y[j] = d2;
                D1T_y[j] = d1t;
                D2T_y[j] = d2t;
                Delta_1_y[j] = delta_1;
                Delta_2_y[j] = delta_2;
            }

            foreach (int m in M)
            {
                sum = Gauss3(a, b, m, Fun);
                Console.WriteLine($"m = {m}\tSum = {sum}");
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form_3(F_xy, D1_y, D2_y, D1T_y, D2T_y, Delta_1_y, Delta_2_y));

            Console.ReadLine();
            Console.Clear();
        }
    }
}
