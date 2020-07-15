using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    class _18_Var
    {
        static void Main()
        {
            int[] ar = { 1, 2, 3, 4, 5, 6, 7 };
            foreach(var i in ar)
            {
                Console.Write(i + " ");
            }
        }
    }
}
