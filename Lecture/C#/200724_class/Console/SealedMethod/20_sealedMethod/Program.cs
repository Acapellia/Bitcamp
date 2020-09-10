using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _20_sealedMethod
{
    class Base
    {
        public virtual void Message()
        { Console.WriteLine("Base Message"); }
    }
    class Derived : Base
    {
        // 주로 framework를 만들 때 사용
        public sealed override void Message()
        {
            Console.WriteLine("Derived Message");
        }
    }
    // sealed 키워드가 붙은 함수를 상속받는 class에서 override 할 수 없다.
    class Third : Derived
    {
        public new void Message()
        { Console.WriteLine("Third Message"); }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Base[] B = new Base[3];
            B[0] = new Base();
            B[1] = new Derived();
            B[2] = new Third(); // virtual로 인식하지 않기 때문에 Base타입으로 만들 경우 Base의 함수가 실행
            foreach (Base b in B)
            {
                b.Message();
            }
        }
    }
}
