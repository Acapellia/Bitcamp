using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    // 새로운 클래스를 선언 후 기존 클래스를 멤버 변수로 받는 함수를 만든다.
    // 멤버 변수 선언 시 this 키워드로 생성
    // 기존의 클래스를 확장한 것 같은 효과
    public class Integer
    {
        public int a;
        public Integer(int aa) { a = aa; }
        public int Add(int b) { return a + b; }
    }
    public static class Temp{
        public static void Print(this Integer I) { Console.WriteLine("Temp : " + I.a); }
    }
    class _21_ExpansionMethod
    {
        static void Main()
        {
            Integer num = new Integer(10);
            num.Print();
        }
    }
}
