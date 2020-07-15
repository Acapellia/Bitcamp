using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    class Time
    {
        public int time { get { return time; } set { { if (value < 24) time = value; } } }
        private int hour { get { return hour; } set { if (value < 24) hour = value; } }
        private int min { get { return min; } set { if (value < 60) min = value;} }
        private int sec { get { return sec; } set { if (value < 60) sec = value; } }
        public void OutTime()
        {
            Console.WriteLine($"현재 시간은 {hour}시 {min}분 {sec}초");
        }
        public Time(int h, int m, int s)
        {
            hour = h; min = m; sec = s;
        }
    }
    class _08_Property
    {
        
        static void Main08(string[] args)
        {
            //Time now = new Time(12, 30, 45);
        }
    }
}