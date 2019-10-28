void main() {
  var s1 = Singleton();
  s1.printHelloWorld();
}
class Singleton {
  static final Singleton singleton = Singleton.internal();

  factory Singleton() {
    return singleton;
  }

  void printHelloWorld(){
    print("Hello World");
  }

  Singleton.internal();
}