using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    class _17_NullType
    {
        static void Main()
        {
            int? Age = null;
            if (Age.HasValue) Console.WriteLine(Age);
            else Console.WriteLine("알 수 없는 나이임");
        }
    }
}
