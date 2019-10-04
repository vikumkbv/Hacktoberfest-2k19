class Person {
  constructor(name) {
    this.name = name;
  }

  introduce() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

class Student extends Person {
  constructor(name, grades) {
    super(name);
    this.grades = grades;
  }

  calculateGPA() {
    const gpa = this.grades.reduce((total, acc) => total + acc) / this.grades.length;
    console.log(`My GPA is ${Math.round(gpa)}`)
  }
}

class Professor extends Person {
  constructor(name) {
    super(name);
  }

  groundStudent(student) {
    console.log(`${student.name}, you are grounded!`);
  }
}

const john = new Student('John', [12, 20, 10, 9]);
const jane = new Professor('Jane');
john.introduce(); // Hello my name is John
john.calculateGPA(); // My GPA is 13
jane.introduce(); // Hello my name is Jane
jane.groundStudent(john); // John you are grounded!