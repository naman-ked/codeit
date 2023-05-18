#1 Using an Object Literal
const person = {firstName:"John", lastName:"Doe", age:50, eyeColor:"blue"};

#2 Using the JavaScript Keyword new
const person = new Object();
person.firstName = "John";
person.lastName = "Doe";
person.age = 50;
person.eyeColor = "blue";

#3 JavaScript Object Constructors
function Person(first, last, age, eye) {
  this.firstName = first;
  this.lastName = last;
  this.age = age;
  this.eyeColor = eye;
}
const person = new Person("John", "Doe", 50, "blue");

#4 Using a Class
When you have a class, you can use the class to create objects:
class Car {
  constructor(name, year) {
    this.name = name;
    this.year = year;
  }
}
const myCar1 = new Car("Ford", 2014);
const myCar2 = new Car("Audi", 2019);
