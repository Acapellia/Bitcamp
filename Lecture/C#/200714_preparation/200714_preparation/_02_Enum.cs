using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    class _02_Enum
    {
        enum SEASON { Spring, Summer, Fall, Winter}
        static void Main02(string[] args)
        {
            // enum형을 정수로 사용할 시 정수형이라고 명시해줘야 함
            SEASON season;
            season = SEASON.Fall;
            Console.WriteLine(season);
            int value = (int)season;
            Console.WriteLine(value);
            string name = season.ToString();
            Console.WriteLine(name);
            season = (SEASON)Enum.Parse(typeof(SEASON), "Summer");
            Console.WriteLine(season);
            Console.WriteLine((int)season);
        }
    }
}
