using System;
using System.Collections.Generic;
using System.Text;

namespace _200714_preparation
{
    // string은 string연산시 연산 후의 값을 새로운 메모리에 할당해야 함
    // 자주 하면 이전의 메모리를 계속 garbage collect해줘야 하고 속도 저하도 발생
    class _05_StringBuilder
    {
        static void Main05(string[] args)
        {
            // StringBuilder str = new StringBuilder("알파벳 : ", 40);
            StringBuilder str = new StringBuilder();
            for (char c = 'a'; c <= 'z'; c++){
                str.Append(c);
            }
            str[10] = '_';
            Console.WriteLine(str);
        }
    }
}
