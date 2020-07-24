using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace OperatorPlusPlus
{
    class Time
    {
        private int hour, min, sec;
        public Time() { }
        public Time(int h, int m, int s)
        { hour = h; min = m; sec = s; }
        public void OutTime()
        {
            Console.WriteLine($"현재 시간은 {hour}시 {min}분 {sec}초이다");
        }
        // c++과 달리 전위와 후위를 구분하지 않고 작성, Intelligence의 발전
        public static Time operator ++(Time A)
        {
            Time T = new Time();
            T.hour = A.hour;
            T.min = A.min;
            T.sec = A.sec;

            T.sec++;
            T.min += T.sec / 60;
            T.sec %= 60;
            T.hour += T.min / 60;
            T.min %= 60;
            return T;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Time A = new Time(1, 1, 1);
            Time t1, t2;
            t1 = A++;
            t2 = ++A;

            t1.OutTime();
            t2.OutTime();
            A.OutTime();
        }
    }
}
