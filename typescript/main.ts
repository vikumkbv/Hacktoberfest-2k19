interface Person {
  name: string,
  age: number,
  say(): string
}

let yearOfBirth = new Date().getUTCFullYear();

let masyoudi = {
  age: yearOfBirth - 1997, 
  name: 'Masyoudi', 
  say: function() { 
      return `My name is ${this.name} and I'm ${this.age} years old!`
  }
}

function sayIt(person: Person) {
  return person.say();
}

console.log(sayIt(masyoudi))
