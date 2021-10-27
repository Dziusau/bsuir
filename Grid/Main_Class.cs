using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Grid
{
    delegate void Fun();

    class Main_Class
    {
        static void Main()
        {
            bool key = true;
            Fun fun = null;
            while (key)
            {
                Console.WriteLine("Choose task:\n1 - task_1\n2 - task_2\n3 - task_3\n4 - task_4\n5 - task_5\n6 - task_6\ndefault - exit");
                int number = Convert.ToInt32(Console.ReadKey());
                switch (number)
                {
                    case 1:
                        fun = Task_1.Task;
                        break;
                    case 2:
                        fun = Task_2.Task;
                        break;
                    case 3:
                        fun = Task_3.Task;
                        break;
                    case 4:
                        fun = Task_4.Task;
                        break;
                    case 5:
                        fun = Task_5.Task;
                        break;
                    case 6:
                        fun = Task_6.Task;
                        break;
                    default:
                        key = false;
                        break;
                }

                fun?.Invoke();
            }
        }
    }
}
