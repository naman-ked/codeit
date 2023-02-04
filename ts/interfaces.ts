interface addFn{
    (a:number,b:number):number;
}

let add:addFn;

add = (n1:number,n2:number)=>{
    return n1+n2;
};

type Persontype = {
    readonly name:string;
    greet(phrase: string): void;
}

interface Person{
    readonly name:string;
    name2?:string; //optional parameter for each class that implement this
    greet(phrase: string): void;
}

class Person2 implements Person{
   name:string;
   age=24;
   role="developer";
   constructor(n: string){
    this.name=n;
   }
   greet(phrase:string){
    console.log(this.name+" "+phrase+" "+this.role);
   }
}
let user= new Person2("naman");
console.log(user);


let user1:Person;

user1={
    name:'Naman',
    greet(phrase: string){
        console.log(phrase+" "+this.name);
    }
}

user1.greet("This is great!")
