console.log('Your code goes here...');

function add(n1: number,n2: number){
    return n1+n2;
}

const number1=5;
const number2=2.8;

const result=add(number1,number2);
console.log(result);
//tuple
const person:{
   name:string;
   age:number;
   hobbies:string[];
   role : [number,string];
}={
    name:"Naan",
    age:24,
    hobbies: ['eating','sleeping'],
    role:[1,"nba"]
};

console.log(person.name);

//enum
// const ADMIN=0;
// const READ_ONLY=1;
// const AUTHOR=2;
enum Role {ADMIN=5,READ_ONLY,AUTHOR};
const person2={
     name:"Naan",
     age:24,
     hobbies: ['eating','sleeping'],
     role:Role.ADMIN
 };

 //Union Types
function accept(n1: number|string,n2:number|string){
    console.log(n1,n2);
}

const number3=5;
const number4=2.8;

const result2=accept(number3,number4);

//custom type 
type Combinable =  number | string;
type User = { name: string; age: number };
const u1: User = { name: 'Max', age: 30 }; // this works!

//function type
let combine : (a:number,b:number) => number;
combine=add;

//callbacks
function addHandle(n1:number,n2:number, cb: (num:number)=>void) {
    const result = n1+n2;
    cb(result);
}

addHandle(10,20,(result)=>{
    console.log(result);
})

//unknown type
let userInput : unknown;

userInput =5;
userInput= {"name":"Nama"}

//never type
function generateError(message:string, code:number){
    throw {message:message, errorCode: code};
}

const res = generateError('An error occurred',500);
console.log(result) // it never returns anything blank in console
