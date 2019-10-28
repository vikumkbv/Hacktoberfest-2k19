using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{
    class Dog:Animal
    {
        public void run()
        {
            Console.WriteLine("Dog runs");
        }
        public void eats()
        {
            Console.WriteLine("Dog eats");
        }
    }
}
