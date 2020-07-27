using System;

namespace ConsoleProblem {
    class Program {
        static void printProblem() {
            Console.WriteLine("1. 소문자인지 대문자인지 판별하는 프로그램");
            Console.WriteLine("2. 소문자는 대문자로, 대문자는 소문자로 변경해서 출력하는 프로그램");
            Console.WriteLine("3. 입금한 금액이 화폐 단위 별(50000~1)로 각각 몇개가 필요한지 출력하는 프로그램");
            Console.WriteLine("4. 1~99까지의 정수를 입력받고 3,6,9중 하나가 있으면 '박수짝'을 출력, 2개가 있으면 '박수짝짝'을 출력하는 프로그램");
            Console.WriteLine("5. 정수 3개를 입력받고 이 3개의 수로 삼각형을 만들 수 있는지를 판별하는 프로그램");
            Console.WriteLine("6. 연도를 입력하고 윤년인지 아닌지 판단하는 프로그램");
            Console.WriteLine("7. 입력한 점이 (50, 50)과(100, 100)의 두 점으로 이루어진 사각형안에 있는지 판단하는 프로그램");
            Console.WriteLine("8. 10개의 공간이 있는 int배열에 3의 배수를 차례대로 저장하고 거꾸로 출력하는 프로그램");
            Console.WriteLine("9. 사용자로부터 10개의 값을 입력받고 순서대로 출력하고 총합을 구하는 프로그램");
            Console.WriteLine("10. 1 ~ 10까지의 임의의 수를 저장하고 홀수만 골라서 출력하는 프로그램");
            Console.WriteLine("11. 정수 10개를 입력받아 배열에 저장하고, 2의 배수와 3의 배수를 출력하는 프로그램");
            Console.WriteLine("12. 1부터 10까지 곱해서 그 결과를 출력하는 프로그램");
        }
        //        1. 영문자를 입력받습니다
        //   소문자인지 대문자인지 판별하세요(조건 연산자를 사용하세요)
        static void problem1() {
            Console.Write("알파벳 하나를 입력하세요 : ");
            string sAlpha = Console.ReadLine();
            char alpha = sAlpha[0];
            if(sAlpha.Length > 1) {
                Console.WriteLine($"한글자만 입력하세요");
            }
            else if('A' <= alpha && alpha <= 'Z') {
                Console.WriteLine($"{alpha}은/는 대문자입니다");
            }
            else if('a' <= alpha && alpha <= 'z') {
                Console.WriteLine($"{alpha}은/는 소문자입니다");
            }
            else {
                Console.WriteLine($"{alpha}는 알파벳이 아닙니다");
            }
        }

        //2. 영문자를 입력받습니다
        //   소문자는 대문자로, 대문자는 소문자로 변경해서 출력하세요
        //   (조건 연산자를 사용하세요)
        //   (아스키테이블/유니코드테이블을 참조하면 됩니다)
        static void problem2() {
            Console.Write("영문자를 입력하세요 : ");
            string sAlpha = Console.ReadLine();
            if(sAlpha.Length > 1) {
                Console.WriteLine($"한글자만 입력하세요");
            }
            char alpha = sAlpha[0];
            if('A' <= alpha && alpha <= 'Z') {
                Console.WriteLine($"{alpha} -> {(char)(alpha + ('a' - 'A'))}");
            }
            else if('a' <= alpha && alpha <= 'z') {
                Console.WriteLine($"{alpha} -> {(char)(alpha - ('a' - 'A'))}");
            }
            else {
                Console.WriteLine($"{alpha}는 알파벳이 아닙니다");
            }
        }
        //3. 돈의 액수를 입금하세요
        //   입금한 돈을 오만원권, 만원권, 오천원권, 천원권, 500원동전, 100원동전, 50원동전, 10원동전, 1원동전 각 몇개로 변환되는지 출력하세요
        //   출력 개수는 단위가 큰 것 순서로 계산합니다
        //   예를 들어 78670원이면<오만원 1매, 만원 2매, 오천원 1매, 천원 3매, 500원 1개, 100원 1개, 50원 1개, 10원 2개> 입니다.
        static void problem3() {
            Console.Write("금액을 입력해주세요 : ");
            int money = Convert.ToInt32(Console.ReadLine());
            int[] moneyType = new int[] { 50000, 10000, 5000, 1000, 500, 100, 50, 10, 1 };
            int[] moneyCnt = new int[moneyType.Length];
            for(int i = 0; i < moneyType.Length; i++) {
                moneyCnt[i] = money / moneyType[i];
                money %= moneyType[i];
            }
            for(int i = 0; i < moneyCnt.Length; i++) {
                Console.Write($"{moneyType[i]}원 : {moneyCnt[i]}개 ");
            }
            Console.WriteLine();
        }
        //4. 369게임을 작성합니다.
        //   1~99까지의 정수를 입력받고
        //   3,6,9중 하나가 있으면 "박수짝"을 출력하고
        //   2개가 있으면 "박수짝짝"을 출력하세요
        //   예를 들어 13은 "박수짝"
        //   36인 경우는 "박수짝짝"을 출력하면 됩니다.
        static void problem4() {
            Console.WriteLine("369 게임을 시작합니다");
            while(true) {
                Console.Write("숫자를 입력하세요(1~99) : ");
                string num = Console.ReadLine();
                int cnt = 0;
                if((Convert.ToInt32(num[0])) % 3 == 0) { cnt++; }
                if((Convert.ToInt32(num[1])) % 3 == 0) { cnt++; }
                if(cnt == 1) { Console.WriteLine("박수짝"); }
                else if(cnt == 2) { Console.WriteLine("박수짝짝"); }
                else { Console.WriteLine("침묵..."); }
            }
        }
        //5. 정수 3개를 입력받고 이 3개의 수로 삼각형을 만들 수 있는지를 판별하세요
        //   삼각형이 가능하려면 두 변의 합이 다른 한 변의 합보다 반드시 커야 합니다. (조건 연산자를 사용하세요)
        static void problem5() {
            int[] side = new int[3];
            for(int i = 1; i <= side.Length; i++) {
                Console.Write($"{i}번 정수를 입력하세요 : ");
                side[i] = Convert.ToInt32(Console.ReadLine());
            }
            if(side[0] + side[1] > side[2])
                Console.WriteLine("가능");
            else
                Console.WriteLine("불가능");
        }
        //6. 연도를 입력받으세요
        //   윤년인지 아닌지를 판별하세요
        //   4로 나누어 떨어지는 해는 일단 윤년에 포함시킵니다
        //   하지만 윤년중에 100으로 나누어떨어지는 해는 평년으로 하되
        //   평년중에 400으로 나누어 떨어지는 해는 윤년에 해당합니다
        static void problem6() {
            Console.Write("정수를 입력하세요 : ");
            int year = Convert.ToInt32(Console.ReadLine());
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                Console.WriteLine($"{year}년은 윤년입니다");
            }
            else {
                Console.WriteLine($"{year}년은 윤년이 아닙니다");
            }
        }
        //7. 2차원 평면에서 하나의 직사각형은 두 점으로 표현된다.
        //   (50, 50)과(100, 100)의 두 점으로 이루어진 사각형이 있다고 하자.
        //  이 때 키보드로부터 한 점을 구성하는 정수 x와 y를 입력받고
        //   점(x, y)가 이 직사각형 안에 있는지 밖에 있는지 판별하는 프로그램을
        //   작성하세요
        static void problem7() {
            Console.Write("점의 x위치를 입력하세요 : ");
            int x = Convert.ToInt32(Console.ReadLine());
            Console.Write("점의 y위치를 입력하세요 : ");
            int y = Convert.ToInt32(Console.ReadLine());
            if((50 <= x && x <= 100) && (50 <= y && y <= 100))
                Console.WriteLine($"점({x},{y})는 사각형 안에 있습니다");
            else
                Console.WriteLine($"점({x},{y})는 사각형 밖에 있습니다");

        }
        //8.int배열을 10개 생성해라.
        // int배열에 3의 배수를 차례대로 저장해라.
        // 그리고 거꾸로 출력해라.
        static void problem8() {
            int[] num = new int[10];
            for(int i = 1; i <= 10; i++)
                num[i - 1] = i * 3;
            for(int i = 10; i >= 1; i--)
                Console.Write(num[i - 1] + " ");
        }
        //9.int배열을 10개 생성해라
        //  사용자로부터 10개의 값을 입력받고
        //  순서대로 출력하고
        //  총합을 구하세요
        static void problem9() {
            int[] num = new int[10];
            int sum = 0;
            for(int i = 0; i < 10; i++) {
                Console.Write($"{i + 1}번째 수를 입력하세요 : ");
                num[i] = Convert.ToInt32(Console.ReadLine());
                sum += num[i];
            }
            for(int i = 0; i < 10; i++)
                Console.Write(num[i] + " ");
            Console.WriteLine($"입력한 숫자들의 합 : {sum}");
        }
        //10.int 배열로 10개의 공간을 생성하라
        //  1 ~ 10까지의 임의의 수를 저장하고
        //  홀수만 골라서 출력하라
        static void problem10() {
            Random r = new Random();
            int[] num = new int[10];
            for(int i = 0; i < 10; i++)
                num[i] = r.Next(1, 10);

            for(int i = 0; i < 10; i++) {
                if(num[i] % 2 == 1)
                    Console.Write(num[i] + " ");
            }
        }
        //11. 정수 10개를 입력받아 배열에 저장하고,
        //이 정수중에서 2의 배수와 3의 배수를 출력하세요
        static void problem11() {
            int[] num = new int[10];
            for(int i = 0; i < 10; i++) {
                Console.Write($"{i + 1}번째 수를 입력하세요 : ");
                num[i] = Convert.ToInt32(Console.ReadLine());
            }
            for(int i = 0; i < 10; i++) {
                if(num[i] % 2 == 0 || num[i] % 3 == 0)
                    Console.Write(num[i] + " ");
            }
        }
        //12. 1부터 10까지 곱해서
        //그 결과를 출력하는 프로그램을 작성하세요
        static void problem12() {
            int mul = 1;
            for(int i = 1; i <= 10; i++)
                mul *= i;
            Console.WriteLine($"{1} ~ {10} mul : {mul}");
        }

        static void Main(string[] args) {
            while(true) {
                printProblem();
                Console.Write("문제 번호를 입력하세요(1~12/종료:0) : ");
                string pro = Console.ReadLine();
                if(pro == "1") { problem1(); }
                else if(pro == "2") { problem2(); }
                else if(pro == "3") { problem3(); }
                else if(pro == "4") { problem4(); }
                else if(pro == "5") { problem5(); }
                else if(pro == "6") { problem6(); }
                else if(pro == "7") { problem7(); }
                else if(pro == "8") { problem8(); }
                else if(pro == "9") { problem9(); }
                else if(pro == "10") { problem10(); }
                else if(pro == "11") { problem11(); }
                else if(pro == "12") { problem12(); }
                else if(pro == "0") { Console.WriteLine("프로그램을 종료합니다."); break; }
                else { Console.WriteLine("문제 번호를 다시 입력하세요"); }
                Console.WriteLine();
            }
        }
    }
}