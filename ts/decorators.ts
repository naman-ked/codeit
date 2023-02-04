//Decorator Factories
function Logger(logString:string) {
   return function(constructor: Function){
     console.log(logString);
     console.log(constructor);
   }
}


// @Logger('Wah Wah Wah!')
// class Person4{
//     name = "Naman";
//     constructor(){
//         console.log('Creating person object...');
//     }
// }

// const pers4= new Person4();
// console.log(pers4);

//More useful decorators
function WithTemplate(template:string, hookId:string){
    return function(_:Function) {
        console.log("rendering second decorator");
        const hookEl = document.getElementById(hookId);
        if(hookEl){
            hookEl.innerHTML = template;
        }
    }
}
@Logger('multiple decorators')
@WithTemplate('<h1>My Person Object</h1>','app')
class Person3{
    name = "Naman";
    constructor(){
        console.log('Creating person object...');
    }
}

const pers3= new Person3();
console.log(pers3);

// Property Decorator

function Log(target:any , propertyName:string | symbol){
  console.log("Property decorator!");
  console.log(target,propertyName);
}

function Log2(target:any, name: string , descriptor: PropertyDescriptor){
    console.log("Accesor Decorator");
    console.log(target);
    console.log(name);
    console.log(descriptor);
}

function Log3(target:any, name: string , descriptor: PropertyDescriptor){
    console.log("Method Decorator");
    console.log(target);
    console.log(name);
    console.log(descriptor);
}

function Log4(target:any, name: string , position: number){
    console.log("Parameter Decorator");
    console.log(target);
    console.log(name);
    console.log(position);
}

class Product{
    @Log
    title:String;
    private _price:number;
    @Log2
    set Price(val: number){
        if(val>0){
            this._price = val;
        }else{
            throw new Error("Invalid Price- should be positive");
        }
    }
    
    constructor(t:string,p:number){
        this.title=t;
        this._price=p;
    }
    @Log3
    getPriceWithTax(@Log4 tax:number){
        return this._price * (1 + tax);
    }
}
const newProduct = new Product('book',19);

//creating an autobind decorator
function Autoing(_:any,_2:string,descriptor:PropertyDescriptor){
        const originalMethod = descriptor.value;
        const adjDescriptor : PropertyDescriptor = {
            configurable:true,
            enumerable: false,
            get() {
                const boundFn = originalMethod.bind(this);
                return boundFn;
            }
        };
        return adjDescriptor;
}


class Printer{
    message="This works!";
    @Autoing
    showMessage(){
        console.log(this.message);
    }
}
const p = new Printer();
const button = document.querySelector('button')!;
button.addEventListener('click',p.showMessage);

//validator
interface ValidatorConfig {
  [property: string]: {
    [validatableProp: string]: string[]; //['required','positive']
  };
}

const registeredValiators: ValidatorConfig = {};

function Required(target: any, propName: string) {
  registeredValiators[target.constructor.name] = {
    [propName]: ["required"],
  };
}

function Positive(target: any, propName: string) {
  registeredValiators[target.constructor.name] = {
    [propName]: ["positive"],
  };
}
function Validate(obj: any) {
  const objectValidators = registeredValiators[obj.constructor.name];
  if (!objectValidators) {
    return true;
  }
  let isValid = true;
  for (const prop in objectValidators) {
    for (const validator of objectValidators[prop]) {
      switch (validator) {
        case "required":
          isValid = isValid && !!obj[prop];
        case "positive":
          isValid = isValid && obj[prop] > 0;
      }
    }
  }
  return isValid;
}

class Course {
  @Required
  title: string;
  @Positive
  price: number;

  constructor(t: string, p: number) {
    this.title = t;
    this.price = p;
  }
}

const courseForm = document.querySelector("form")!;
courseForm.addEventListener("submit", (event) => {
  event.preventDefault();
  const titleEl = document.getElementById("title") as HTMLInputElement;
  const priceEl = document.getElementById("price") as HTMLInputElement;

  const title = titleEl.value;
  const price = +priceEl.value;

  const createCourse = new Course(title, price);

  if (!Validate(createCourse)) {
    alert("invalid input");
  }
  console.log(createCourse);
});

