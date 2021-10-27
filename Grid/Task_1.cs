using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Text;

namespace Grid
{
    class Task_1
    {
        public static void Task()
        {
            Console.Clear();
            int n = 5, it, a = 0;
            double eps = 0.0001, w = 0.2, de, s, dif;

            var x = new double[n];
            var x0 = new double[n];

            double[][] Fi = new double[2][];
            Fi[0] = new double[10];
            Fi[1] = new double[10];

            double[,] matrix =
            {
                { -2.25, 1, 0, 0, 0},
                { 1, -2, 1, 0, 0},
                { 0, 1, -2, 1, 0},
                { 0, 0, 1, -2, 1},
                { 0, 0, 0, 1, -2.25}
            };

            double[] d = { 0, -4, -4, -4, 0 };

            Console.WriteLine("Your matrix:");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    Console.Write($"{matrix[i, j]} \t\t");
                Console.Write($"{d[i]} \n");
            }

            Console.WriteLine($"Epselen value: {eps}");
            while (w <= 2)
            {
                Console.WriteLine($"\nw = {w}");

                for (int i = 0; i < n; i++)
                {
                    x0[i] = 1;
                    x[i] = 1;
                }
                it = 0;

                do
                {
                    de = 0;
                    for (int i = 0; i < n; i++)
                    {
                        s = d[i];
                        for (int j = 0; j < n; j++)
                        {
                            if (i != j)
                                s -= matrix[i, j] * x0[j];
                            else continue;
                        }
                        s /= matrix[i, i];
                        s = w * s + (1 - w) * x[i];
                        dif = Math.Abs(x[i] - s);
                        x[i] = s;
                        if (dif > de) de = dif;
                        else continue;
                    }
                    it++;
                    /*cout << "Iteration: " << it << "\tDelta: " << dif << endl;*/
                    for (int i = 0; i < n; i++)
                    {
                        x0[i] = x[i];
                        /*cout << "x[" << i << "] -> " << x[i] << endl;*/
                    }
                } while (/*it <= 100 && */de > eps);
                Console.WriteLine($"\tIteration: {it}");

                Fi[0][a] = w;
                Fi[1][a] = it;

                for (int i = 0; i < n; i++)
                {
                    Console.WriteLine($"x[{i}] -> {x[i]}");
                }

                Console.WriteLine("\t\tCheck");
                for (int i = 0; i < n; i++)
                {
                    s = 0;
                    for (int j = 0; j < n; j++)
                    {
                        Console.Write($"{matrix[i, j]} * {x[i]}" + ((j == n - 1) ? " = " : " + "));
                        s += matrix[i, j] * x[j];
                    }
                    Console.Write($"{s} \t-->\t {d[i]}\n");
                }
                a++;
                w += 0.2;
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm_1(Fi));

            Console.ReadLine();
            Console.Clear();
        }
    }
}
