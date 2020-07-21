using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*
 * C/C++ : 1. 입력
 *         2. 삭제
 *         3. 종료
 *         
 *    입력 >> 1
 *    1 => INPUT
 *    
 * C# 1) 숫자로 Enum형 매칭을 한다(원래 사용)
 *       1 => INPUT
 *    2) 문자열로 Enum형 매칭이 가능
 *       "INPUT" => INPUT
 */

namespace _4_EnumInt
{
    class Program
    {
        enum SEASON
        {
            Spring, Summer, Fall, Winter
        }
        static void Main(string[] args)
        {
            SEASON season;
            season = SEASON.Fall;
            string name = season.ToString();
            Console.WriteLine(name);
            season = (SEASON)Enum.Parse(
                        typeof(SEASON), "Spring");
            Console.WriteLine(season);
            Console.WriteLine((int)season);
        }
    }
}
