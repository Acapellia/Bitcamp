using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    // static 키워드가 붙을시 같은 클래스 내에서는 해당 클래스의 객체생성 없이 사용 가능
    // 다른 클래스에서 사용할 시에는 객체 생성 해야함
    class _07_StaticFunc
    {
        static private int TotalSum(int from, int to)
        {
            int sum = 0;
            for(int i=from; i <= to; i++) { sum += i; }
            return sum;
        }
        static void Main07(string[] args)
        {
            Console.WriteLine($"1~100의 합계 : {TotalSum(1, 100)}");
        }
    }
}
