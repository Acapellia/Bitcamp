using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    class Wrapper<T>
    {
        T value;
        public Wrapper() { value = default(T); }
        public Wrapper(T aValue) { value = aValue; }
        public T data { get; set; }
        public void OutValue() { Console.WriteLine(value); }
    }
    class _16_Generic
    {
        static void Main()
        {
            Wrapper<int> gi = new Wrapper<int>(1234);
            gi.OutValue();
            Wrapper<string> gs = new Wrapper<string>("문자열");
            gs.OutValue();
        }
    }
}
