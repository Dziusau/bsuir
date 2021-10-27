using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_5
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        public static double Fun(double x)
        {
            return Math.Pow(Math.Log(x), 2) - 10 * Math.Pow(Math.Cos(x), 2);
        }

        public static double D2(double x)
        {
            return 2 * Math.Log(x) / x + 10 * Math.Sin(2 * x);
        }

        public static double MDP(double alpha, double beta, double eps, Func<double, double> fun, out int it)
        {
            it = 0;
            while (beta - alpha > 2 * eps)
            {
                it++;
                double x1 = (alpha + beta - eps) / 2;
                double x2 = (alpha + beta + eps) / 2;
                if (fun(x1) > fun(x2))
                {
                    alpha = x1;
                }
                else
                {
                    beta = x2;
                }
            }
            return (alpha + beta) / 2;
        }

        public static void Task()
        {
            Console.Clear();
            const int a = 2, b = 10;
            double[] eps = { 0.01, 0.001, 0.0001, 0.00001 };
            int m = 31, i = 0;
            double x = a, y;
            double[,] F_xy = new double[2, m + 1];
            List<double> mins = new List<double>();
            List<Dictionary<double, int>> list_dict = new List<Dictionary<double, int>>();

            double h = (b - a) / (double)m;
            while (x < b)
            {
                y = Fun(x);
                F_xy[0, i] = x;
                F_xy[1, i] = y;

                x += h;
                if (D2(x - h) * D2(x) <= 0 && D2(x) > 0)
                {
                    double min = 0;
                    var dict = new Dictionary<double, int>();
                    foreach (var e in eps)
                    {
                        min = MDP(x - h, x, e, Fun, out int it);
                        dict.Add(e, it);
                    }
                    list_dict.Add(dict);
                    mins.Add(min);
                }
                i++;
            }

            for (i = 0; i < F_xy.Length / 2; i++)
            {
                Console.WriteLine($"X[{i + 1}] = {F_xy[0, i]}\t\tY[{i + 1}] = {F_xy[1, i]}");
            }

            i = 0;
            Console.WriteLine("\nMinimums:");
            foreach (var min in mins)
            {
                Console.WriteLine($"min_{i + 1} = {min}");
                foreach (var dict in list_dict[i++])
                {
                    Console.WriteLine($"\tEps = {dict.Key}\t\tIteration = {dict.Value}");
                }
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form_5(F_xy, list_dict));

            Console.ReadLine();
            Console.Clear();
        }
    }
}