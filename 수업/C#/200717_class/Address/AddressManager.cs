using System;
using System.Collections.Generic;
using System.Text;

namespace Address {
    class AddressManager {
        static List<Address> listAddress =
                        new List<Address>(10);
        int addressCnt = 0;
        public void InsertAddress() {
            Address addr = new Address();
            Console.Write("이름 입력 : ");
            addr.name = Console.ReadLine();
            Console.Write("나이 입력 : ");
            addr.age = Int32.Parse(Console.ReadLine());
            Console.Write("주소 입력 : ");
            addr.address = Console.ReadLine();
            addressCnt++;
            listAddress.Add(addr);
            Console.ReadLine();
        }
        public void DeleteAddress() {
            Console.Write("이름 입력 : ");
            string name = Console.ReadLine();
            for(int i = 0; i < addressCnt; i++) {
                if(name == listAddress[i].name) {
                    listAddress.RemoveAt(i);
                    addressCnt--;
                    break;
                }
            }
            Console.ReadLine();
        }
        public void UpdateAddress() {
            Console.Clear();
            Console.Write("이름 입력 : ");
            string _name = Console.ReadLine();
            for(int i = 0; i < addressCnt; i++) {
                if(_name == listAddress[i].name) {
                    Console.Write("이름 입력 : ");
                    listAddress[i].name = Console.ReadLine();
                    Console.Write("나이 입력 : ");
                    listAddress[i].age = Int32.Parse(Console.ReadLine());
                    Console.Write("주소 입력 : ");
                    listAddress[i].address = Console.ReadLine();
                    break;
                }
            }
            Console.ReadLine();
        }
        public void SearchAdderss() {
            Console.Clear();
            Console.Write("이름 입력 : ");
            string name = Console.ReadLine();
            for(int i = 0; i < addressCnt; i++) {
                if(name == listAddress[i].name) {
                    Console.WriteLine("이름 : " + listAddress[i].name);
                    Console.WriteLine("나이 : " + listAddress[i].age);
                    Console.WriteLine("주소 : " + listAddress[i].address);
                    break;
                }
            }
            Console.ReadLine();
        }
        public void PrintAllAdderss() {
            Console.Clear();
            for(int i = 0; i < addressCnt; i++) {
                Console.WriteLine("-----------{0}-----------", i + 1);
                Console.WriteLine("이름 : " + listAddress[i].name);
                Console.WriteLine("나이 : " + listAddress[i].age);
                Console.WriteLine("주소 : " + listAddress[i].address);
                Console.WriteLine();
            }
            Console.ReadLine();
        }
        public void ProgramExit() {
            Environment.Exit(0);
        }
    }
}
