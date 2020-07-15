using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    class _20_AnoType
    {
        static void Main()
        {
            var human = new { name = "사람", age = 25 };
            Console.WriteLine($"이름 : {human.name} 나이 : {human.age}");
        }
    }
}
