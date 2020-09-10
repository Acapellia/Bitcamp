using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    delegate int del(int a, int b);
    class _15_AnoDelegate
    {
        static void Main()
        {
            del d = delegate (int a, int b) { return a + b; };
            int k = d(2, 3);
            Console.WriteLine(k);
        }
    }
}
