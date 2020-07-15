using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    // lamda(람다)
    // left => right 
    // left = 매개변수
    // right = return값
    delegate int del(int a);
    class _22_Lamda
    {
        static void Main()
        {
            del d = a => a + 1;
            int k = d(3);
            Console.WriteLine("k = " + k);
        }
    }
}
