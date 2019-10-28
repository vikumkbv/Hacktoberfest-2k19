using System;

namespace Inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            Dog dog = new Dog();
            dog.run();
            dog.eats();
            Lion lion = new Lion();
            lion.eats();
            lion.run();
        }
    }
}
