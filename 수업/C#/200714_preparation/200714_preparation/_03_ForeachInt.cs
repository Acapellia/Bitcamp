using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    class _03_ForeachInt
    {
        static void Main03(string[] args)
        {
            int[] ar = { 33, 22, 11, 99, 88 };
            int max = 0;
            foreach(int a in ar)
            {
                if (max < a) max = a;
            }
            Console.WriteLine($"가장 큰 값은 {max}");          
        }
    }
}
