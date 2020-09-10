using System;
using System.Collections.Generic;
using System.Text;

namespace Address {
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
                    addrMgr.InsertAddress();
                    break;
                case CMD_NUM.SEARCH:
                    addrMgr.SearchAdderss();
                    break;
                case CMD_NUM.UPDATE:
                    addrMgr.UpdateAddress();
                    break;
                case CMD_NUM.DELETE:
                    addrMgr.DeleteAddress();
                    break;
                case CMD_NUM.PRINTALL:
                    addrMgr.PrintAllAdderss();
                    break;
                case CMD_NUM.EXIT:
                    addrMgr.ProgramExit();
                    break;
                default:
                    Console.WriteLine("Invalid Number!!!");
                    break;
            }
        }
    }
}
