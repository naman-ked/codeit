//built in generics
const names2: Array<string | number> = [];

const promise : Promise<string> = new Promise((resolve,reject)=>{
    setTimeout(()=>{
        resolve("This is done!");
    },2000);
})
//generic function with constraint
function merge<T extends object, U extends object>(objA: T , objB: U) {
    return Object.assign(objA,objB);
}

const mergedObj = merge({name:"Tandeli"}, {identity:"🐍"});
console.log(mergedObj.identity);

//another generic function
interface Lengthy {
    length:number;
}

function countAndPrint<T extends Lengthy>(element: T) : [T,string]{
    let text="Got no value.";
    if(element.length>0){
        text="Got " + element.length + " elements";
    }
    return [element,text]
}
console.log(countAndPrint("Hi there!"));
console.log(countAndPrint([]));

//keyof constraint
function extractAndConvert<T extends object, U extends keyof T>(obj: T, key: U){
    return obj[key];
}

console.log(extractAndConvert({name:"Naman"},'name'));

//generic classes 
class DataStorage<T extends string | number | boolean> {
    private data: T[] = [];
    addItem(item:T){
        this.data.push(item);
    }

    removeItem(item:T){
        this.data.splice(this.data.indexOf(item),1);
    }

    getItems(){
        return [...this.data];
    }
}

const textStorage = new DataStorage<string>();
textStorage.addItem("Naman");
textStorage.addItem("Kedia");
console.log(textStorage.getItems());

//generic utility types
//partial type
interface CourseGoal {
    title: string;
    description: string;
    day : Date;
}

function createCourseGoal(title:string , description: string , day:Date): CourseGoal{
    let courseGoal: Partial<CourseGoal> ={};
    courseGoal.title=title;
    courseGoal.description=description;
    courseGoal.day=day;
    return courseGoal as CourseGoal;
}
//locked array
const names: Readonly<string[]>=["max", "ana"];
//error : names.push("manu");
