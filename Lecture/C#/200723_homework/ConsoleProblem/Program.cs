using System;

namespace ConsoleProblem {
    class Program {
        // 1. 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
        // 예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
        private static void problem1() {
            Console.Write("3의 배수를 출력할 개수를 입력하세요 : ");
            int num = Convert.ToInt32(Console.ReadLine());
            for(int i = 1; i <= num; i++)
                Console.Write(3*i + " ");
            Console.WriteLine();
        }
        // 2. 사용자로부터 정수를 입력받습니다.
        // 입력 받은 값을 계속 더합니다
        // 사용자가 0을 입력하면 합을 출력합니다
        // 프로그램을 종료합니다.
        private static void problem2() {
            int sum = 0;
            while(true) {
                Console.Write("더하고 싶은 숫자를 입력하세요 : ");
                int num = Convert.ToInt32(Console.ReadLine());
                if(num == 0)
                    break;
                sum += num;
            }
            Console.WriteLine($"Sum : {sum}");
        }//1*1 3*1 5*1
        // 3. 구구단을 출력하되 1을 입력하면 홀수단만
        // 2를 입력하면 짝수단만 출력하라
        private static void problem3() {
            Console.Write("구구단 출력을 위한 숫자를 입력하세요(홀수:1/짝수:2) : ");
            int num = Convert.ToInt32(Console.ReadLine());
            for(int i = 1; i <= 9; i++) {
                for(int j = 1; j <= 9;  j++) {
                    if(num==1 && j % 2 == 1) {
                        Console.Write($"{j} * {i} = {j * i}  ");
                    }
                    if(num == 2 && j % 2 == 0) {
                        Console.Write($"{j} * {i} = {j * i}  ");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        //4. 0부터 1씩 증가한 값을 누적하여 더합니다.
        //모두 더한값이 1000이 넘을 때 의 총합과
        //더한 값을 구하세요.
        private static void problem4() {
            int num = 0;
            int sum = 0;
            while(true) {
                sum += (num++);
                if(sum > 1000)
                    break;
            }
            Console.WriteLine($"num : {num} / sum : {sum}\n");
        }
        //19 7 7 5 5 2 2 1 1 0
        //5. 두 수를 입력받고 최소공배수를 구하세요.
        private static void problem5() {
            Console.Write("정수1을 입력하세요 : ");
            int num1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("정수2을 입력하세요 : ");
            int num2 = Convert.ToInt32(Console.ReadLine());
            int n1 = num1, n2 = num2;
            if(n1 < n2) { int temp = n1; n1 = n2; n2 = temp; }
            while(n2 != 0) {
                //Console.WriteLine($"{n1} {n2}");
                int temp = n1;
                n1 = n2;
                n2 = temp % n2;
            }
            Console.WriteLine($"{num1}과 {num2}의 최대공약수는 {n1} 최소공배수는 {num1 * num2 / n1}");
        }
        //6. 입력받은 숫자의 구구단을 출력하는데 역순으로 출력.
        private static void problem6() {
            Console.Write("구구단 출력을 위한 숫자를 입력하세요 : ");
            int num = Convert.ToInt32(Console.ReadLine());
            for(int i = 9; i > 0; i--) {
                Console.WriteLine($"{num} * {i} = {i * num}");
            }Console.WriteLine();
        }
        //7. 정수 n을 입력받고 n!을 구하세요.(factorial)
        //5를 입력한경우 1*2*3*4*5를 구하세요.
        private static void problem7() {
            Console.Write("factorial 출력을 위한 숫자를 입력하세요 : ");
            int num = Convert.ToInt32(Console.ReadLine());
            int factorial = 1;
            for(int i = 1; i <= num; i++) {
                factorial *= i;
            }
            Console.WriteLine($"{num}factorial : {factorial}");
        }
        //8. 두 개의 정수를 입력받습니다.
        //두 정수를 포함한 사이의 정수의 합을 출력하세요
        //예를 들면 3과 5를 입력하면 3+4+5의 합을 출력하면 됩니다.
        private static void problem8() {
            Console.Write("정수1을 입력하세요 : ");
            int num1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("정수2을 입력하세요 : ");
            int num2 = Convert.ToInt32(Console.ReadLine());
            int sum = 0;
            if(num1 > num2) { int temp = num1; num1 = num2; num2 = temp; }
            for(int i = num1; i <= num2; i++) {
                sum += i;
            }
            Console.WriteLine($"{num1}부터 {num2}까지의 합은 {sum}\n");
        }
        //9. 5를 입력하면 아래처럼 그림을 출력하세요
        //*
        //o*
        //oo*
        //ooo*
        //oooo*
        private static void problem9() {
            Console.Write("정수를 입력하세요 : ");
            int num = Convert.ToInt32(Console.ReadLine());
            for(int i = 0; i < num; i++) {
                for(int j = 0; j < i; j++) {
                    Console.Write("o");
                }Console.WriteLine("*");
            }
            Console.WriteLine();
        }
        static void Main(string[] args) {
            while(true) {
                Console.Write("문제번호를 입력하세요 : ");
                int pro = Convert.ToInt32(Console.ReadLine());
                if(pro == 1) { problem1(); }
                if(pro == 2) { problem2(); }
                if(pro == 3) { problem3(); }
                if(pro == 4) { problem4(); }
                if(pro == 5) { problem5(); }
                if(pro == 6) { problem6(); }
                if(pro == 7) { problem7(); }
                if(pro == 8) { problem8(); }
                if(pro == 9) { problem9(); }
                else if(pro == 0) { break; }
            }
        }
    }
}
