using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    class Program
    {
        static void Main(string[] args)
        {
            int var = 0;
            Console.WriteLine("choose the key of cipher: ");
            int key = int.Parse(Console.ReadLine());
            Console.WriteLine("type the message: ");
            string input = Console.ReadLine();
            char[] result = input.ToCharArray();
            for (int i = 0; i < input.Length; i++)
            {
                var = result[i];
                result[i] = result[i] == ' ' ? ' ' : (char)(var + key);

            }
            input = new string(result);
            Console.WriteLine(input);
        }
    }
}
