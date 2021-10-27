using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_6
    {
        public static double[] M4(double x, double h, double[] Y)
        {
            double[] F_medium = new double[2];
            double[] F = new double[2];

            F_medium[0] = (1 + h / 2) * Y[0] * Y[1] / (Math.Exp(x) * x);
            F_medium[1] = (1 + h / 2) * (2 * x / Y[0] + 2 * Y[1] - Math.Exp(x) - 1);

            x += h / 2;
            F[0] = F_medium[0] * F_medium[1] / (Math.Exp(x) * x);
            F[1] = (2 * x / F_medium[0] + 2 * F_medium[1] - Math.Exp(x) - 1);

            return F;
        }

        public static double[] FPR(double x, double x_minus, double[] Y, double[] Y_minus)
        {
            double[] F = new double[2];
            F[0] = 1.5 * Y[0] * Y[1] / (Math.Exp(x) * x) - 0.5 * Y_minus[0] * Y_minus[1] / (Math.Exp(x_minus) * x_minus);
            F[1] = 1.5 * (2 * x / Y[0] + 2 * Y[1] - Math.Exp(x) - 1) - 0.5 * (2 * x_minus / Y_minus[0] + 2 * Y_minus[1] - Math.Exp(x) - 1);
            return F;
        }

        public static void OUT(double x, double[] Y)
        {
            double y1 = Y[0];
            double u1 = 2 * x;
            double d1 = Math.Abs(u1 - y1);
            double y2 = Y[1];
            double u2 = Math.Exp(x);
            double d2 = Math.Abs(u2 - y2);

            Console.WriteLine($"X = {x}\nY_1 = {y1}\tU_1 = {u1}\td_1 = {d1}\nY_2 = {y2}\tU_2 = {u2}\td_2 = {d2}");
        }

        public static void Task()
        {
            //Console.Clear();

            const int a = 1, b = 3;
            int it = 0;
            double x, eps = 0.0001;
            double[] Y0 = new double[2];
            double[] Y = new double[2];
            double[] F;

            do
            {
                x = a;
                int nx = 10 * (int)Math.Pow(2, it);
                double h = (double)(b - a) / nx;
                Y0[0] = 2 * a;
                Y0[1] = Math.Exp(a);
                F = M4(x, h, Y0);
                Y[0] = Y0[0] + h * F[0];
                Y[1] = Y0[1] + h * F[1];

                for (int n = 0; n < nx; n++)
                {
                    x += h;
                    F = FPR(x, x - h, Y, Y0);
                    Y0 = Y;
                    Y[0] += h * F[0];
                    Y[1] += h * F[1];
                }
                it++;
                OUT(x, Y);
            } while (Math.Abs(Math.Exp(x) - Y[1]) > eps || Math.Abs(2 * x - Y[0]) > eps);

            Console.ReadLine();
            //Console.Clear();
        }
    }
}
