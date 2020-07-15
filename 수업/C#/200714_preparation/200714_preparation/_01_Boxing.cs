using System;

namespace _200714_preparation
{
    class _01_Boxing
    {
        static void Main01(string[] args)
        {
            int num = 1234;
            object box = num; // boxing
            Console.WriteLine(box);
            int num2 = (int)box; // unboxing
        }
    }
}
