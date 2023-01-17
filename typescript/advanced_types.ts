//intersection types
type Admin = {
    name:string;
    privileges: string[];
}

type Employee = {
    name: string;
    startDate: Date;
}

type ElevatedEmployee = Admin  & Employee;

const el:ElevatedEmployee = {
    name:"Naman",
    privileges: ['learning ts'],
    startDate: new Date()
}

//Type guards
type Combinable = string | number;

function add(a:Combinable, b:Combinable){
    if(typeof a=='string' || typeof b === 'string'){
        //this checks runs only during runtime by javascript
        return a.toString() + b.toString();
    }
     return a+b;
}

type UnknownEmployee = Employee | Admin ;
function printEmployee(emp:UnknownEmployee){
    console.log("Name "+emp.name);
    if('privileges' in emp)
    console.log('Privileges: '+emp.privileges);
}

printEmployee(el)

//discriminated unions
interface Bird {
    type: "bird";
    flyingSpeed: number;
}

interface Horse {
    type:'horse'
    runningSpeed: number;
}

type Animal = Bird | Horse;

function moveAnimal(animal : Animal){
    let speed: number;
    switch(animal.type){
        case 'bird' : speed= animal.flyingSpeed;
        break;
        case 'horse': speed=animal.runningSpeed;
        break;    
    } 
    console.log('Moving with speed: '+ speed);
}

moveAnimal({type:'bird',flyingSpeed:1000});

//type casting
const userInput= <HTMLInputElement> document.getElementById('user-input');
const userInput2= document.getElementById('user-input2')!;
// ! tells that the expression above will never yield null.
userInput.value = 'Hi there !';
if(userInput2){
    (userInput2 as HTMLInputElement).value = "Welcome !";
}

//index properties
interface ErrorContainer {
    id:string;
    [prop : string]:string;
}

const errorBag : ErrorContainer = {
    id: "1",
    email : 'Not a  valid email !',
    username: "Must start with a capital letter"
}

//function overloads
//define multiple function signatures with different parameters
function add2(a: number  , b :number): number;
function add2(a: string  , b :string): string;
function add2(a:Combinable, b:Combinable){
    if(typeof a=='string' || typeof b === 'string'){
        //this checks runs only during runtime by javascript
        return a.toString() + b.toString();
    }
     return a+b;
}

const result = add2(5,5);
result.toPrecision(1);

