using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace _200714_preparation
{
    class _06_StopWatch
    {
        static void Main06(string[] args)
        {
            Stopwatch st = new Stopwatch();
            st.Start();
            for (int t = 0; t < 1000; t++)
            {
                for (int i = 0; i < 1000000; i++)
                {
                    //Console.Write(i + ",");
                }
            }
            st.Stop();
            Console.WriteLine($"\n총 경과시간 : {st.Elapsed}");
        }
    }
}
