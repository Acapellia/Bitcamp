using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _10_ClassGeneric
{
    class WrapperInt
    {
        int Value;
        public WrapperInt() { Value = 0; }
        public WrapperInt(int aValue)
        { Value = aValue; }
        public int Data
        {
            get { return Value; }
            set { Value = value; }
        }
        public void OutValue()
        {
            Console.WriteLine(Value);
        }
    }

    class WrapperString
    {
        string Value;
        public WrapperString() { Value = null; }
        public WrapperString(string aValue)
        { Value = aValue; }
        public string Data
        {
            get { return Value; }
            set { Value = value; }
        }
        public void OutValue()
        {
            Console.WriteLine(Value);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            WrapperInt gi = new WrapperInt(1234);
            gi.OutValue();
            WrapperString gs = new WrapperString("문자열");
            gs.OutValue();
        }
    }
}
