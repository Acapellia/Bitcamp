using System;
using System.Collections.Generic;
using System.Text;

namespace _200715_preparation
{
    delegate void Notice(string info);
    class Customer
    {
        private int id;
        public Customer(int aid) { id = aid; }
        public void SentCust(string info) { Console.WriteLine($"{id}번 고객에게 {info}를 전송한다."); }
    }
    class _13_Delegate
    {
        static void Main()
        {
            Customer[] arCust = new Customer[10];
            for (int i = 0; i < 10; i++) arCust[i] = new Customer(i);

            Notice AlramCust = null;
            AlramCust += arCust[1].SentCust;
            AlramCust += arCust[3].SentCust;
            AlramCust += arCust[5].SentCust;
            AlramCust += arCust[8].SentCust;
            AlramCust("증권 찌라시");
        }
    }
}
