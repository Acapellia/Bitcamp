using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    class Human
    {
        public string name { get; set; }
        public int age { get; set; }
    }
    class _19_InitClass
    {
        static void Main()
        {
            Human human = new Human { name = "장길산", age = 32 };
            Console.WriteLine($"이름 : {human.name} 나이 : {human.age}");
        }
    }
}
