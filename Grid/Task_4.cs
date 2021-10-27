using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_4
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        public static double Fun(double x)
        {
            return Math.Log(x) - 5 * Math.Pow(Math.Sin(x), 2);
        }

        public static int Sign(double x)
        {
            return (x < 0) ? -1 : 1;
        }

        public static double MD(Func<double, double> fun, double alpha, double beta, double eps, List<Dictionary<double, double>> d_list)
        {
            int i = 1;

            Dictionary<double, double> d = new Dictionary<double, double>();

            while (true)
            {
                var t = (alpha + beta) / 2;
                Console.WriteLine($"X_{i} = {t}");

                if (fun(t) == 0 || Math.Abs(beta - alpha) < Math.Abs(eps))
                {
                    d_list.Add(d);
                    return t;
                }

                if (Sign(fun(t)) == Sign(fun(alpha)))
                {
                    d.Add(t, t - alpha);
                    alpha = t;
                }
                else
                {
                    d.Add(t, t - beta);
                    beta = t;
                }
                i++;
            }
        }

        public static void Task()
        {
            Console.Clear();
            const int a = 2, b = 6;
            const double eps = 0.0001;
            int m = 21, i = 0;
            double x = a, y;
            double[,] F_xy = new double[2, m];
            List<Dictionary<double, double>> d_list = new List<Dictionary<double, double>>();
            List<double> roots = new List<double>();

            double h = (b - a) / (double)m;
            while (x < b)
            {
                y = Fun(x);
                F_xy[0, i] = x;
                F_xy[1, i] = y;
                Console.WriteLine($"X = {x}\tY = {y}");

                x += h;
                if (y * Fun(x) <= 0)
                {
                    roots.Add(MD(Fun, x - h, x, eps, d_list));
                }
                i++;
            }

            i = 1;
            Console.WriteLine("Roots:");
            foreach (var root in roots)
            {
                Console.WriteLine($"X0_{i++} = {root}");
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form_4(F_xy, d_list));

            Console.ReadLine();
            Console.Clear();
        }
    }
}
