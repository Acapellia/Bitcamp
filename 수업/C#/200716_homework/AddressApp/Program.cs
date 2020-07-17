using System;
using System.Collections.Generic;

namespace AddressApp {
    enum CMD_NUM {
        INPUT,
        SEARCH,
        UPDATE,
        DELETE,
        PRINTALL,
        EXIT
    }
    class Address {
        public string name { get; set; }
        public int age { get; set; }
        public string address { get; set; }
    }
    class AddressView {
        AddressManager addrMgr;
        int selMenu;
        public AddressView() {
            addrMgr = new AddressManager();
            selMenu = 0;
        }
        public static void ClearScreen() {
            Console.Clear();
        }
        public void ShowMenu() {
            ClearScreen();
            Console.WriteLine("==================================");
            Console.WriteLine("0. 주소 입력");
            Console.WriteLine("1. 주소 검색");
            Console.WriteLine("2. 주소 수정");
            Console.WriteLine("3. 주소 삭제");
            Console.WriteLine("4. 주소 전체 출력");
            Console.WriteLine("5. 프로그램 종료");
            Console.WriteLine("==================================");
        }
        public int GetSelMenu() {
            Console.Write("메뉴 선택 : ");
            return Int32.Parse(Console.ReadLine());
        }
        public void DispachMenu() {
            selMenu = GetSelMenu();
        }
        public void PrintAddressInfo() {
            ClearScreen();
            switch((CMD_NUM)selMenu) {
                case CMD_NUM.INPUT:
                    addrMgr.InsertAddress(); break;
                case CMD_NUM.SEARCH:
                    addrMgr.SearchAdderss(); break;
                case CMD_NUM.UPDATE:
                    addrMgr.UpdateAddress(); break;
                case CMD_NUM.DELETE:
                    addrMgr.DeleteAddress(); break;
                case CMD_NUM.PRINTALL:
                    addrMgr.PrintAllAdderss(); break;
                case CMD_NUM.EXIT:
                    addrMgr.ProgramExit(); break;
                default:
                    Console.WriteLine("Invalid Number!!!"); break;
            }
        }      
    }
    class AddressManager {
        static List<Address> listAddress =
                        new List<Address>(10);
        int addressCnt=0;
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
