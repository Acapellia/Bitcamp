using System;
using System.Collections.Generic;

namespace Address {
    enum CMD_NUM {
        INPUT, SEARCH, UPDATE, DELETE, PRINTALL, EXIT }
    class Program {
        static void Main(string[] args) {
            AddressView addrView = new AddressView();
            while(true) {
                addrView.ShowMenu();
                addrView.DispachMenu();
                addrView.PrintAddressInfo();
            }
        }
    }
}
