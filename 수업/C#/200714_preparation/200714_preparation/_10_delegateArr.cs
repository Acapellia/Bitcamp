﻿using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    delegate int IntCalc(int a, int b);
    class _10_delegateArr
    {
        public static int Add(int a, int b) { return a + b; }
        public static int Sub(int a, int b) { return a - b; }
        public static int Mul(int a, int b) { return a * b; }
        public static int Div(int a, int b) { return a / b; }
        
        static void Main(string[] args)
        {
            IntCalc[] arCalc = { Add, Sub, Mul, Div };
            int num1, num2;
            int o;
            Console.Write("Input Num1 : ");
            num1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Input Num2 : ");
            num2 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Input Number (1:+ 2:- 3:* 4:/)");
            o = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"Result => {arCalc[o - 1](num1, num2)}");
        }
    }
}
