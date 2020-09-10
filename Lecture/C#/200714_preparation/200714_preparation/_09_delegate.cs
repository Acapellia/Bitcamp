using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    delegate void del(string s);
    class Outer
    {
        public static void m3(string s) { Console.WriteLine(s); }
        public void m4(string s) { Console.WriteLine(s); }
    } 
    class _09_delegate
    {
        public static void m1(string s) { Console.WriteLine(s); }
        public void m2(string s) { Console.WriteLine(s); }
        
        static void Main09(string[] args)
        {
            del d = m1;
            d("정적 메소드");
            _09_delegate cs = new _09_delegate();
            d = cs.m2;
            d("인스턴스 메소드");

            d = Outer.m3;
            d("외부 정적 메소드");
            Outer o = new Outer();
            d = o.m4;
            d("외부 인스턴스 메소드");
        }
    }
}
