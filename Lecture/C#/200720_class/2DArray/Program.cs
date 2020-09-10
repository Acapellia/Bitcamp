using System;

namespace _2DArray {
    class Program {
        static void Main(string[] args) {
            int[,] arr = new int[15, 10];
            //Array.Clear(arr, 0, arr.Length);
            for(int i = 0; i < arr.GetLength(0); i++) {
                for(int j = 0; j < arr.GetLength(1); j++) {
                    Console.Write(arr[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
