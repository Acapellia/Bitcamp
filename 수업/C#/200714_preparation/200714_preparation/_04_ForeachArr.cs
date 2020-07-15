using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    class _04_ForeachArr
    {
        static void Main04(string[] args)
        {
            int[,] ar = { { 1, 2, 3 }, { 4, 5, 6 } };
            foreach(int a in ar)
            {
                Console.Write(a);
                Console.Write(", ");
            }
            Console.WriteLine();
        }
    }
}
