let obj1={
    name:"Naman",
    money:"100"
}
let obj3 = obj1;

let obj2={
    ...obj1,
    name:"Naman2"
}
obj3.name="Naman3";

let obj0 = JSON.parse(JSON.stringify(obj2));
obj0.name="kljijojljl";
console.log(obj0);
console.log(obj1);
console.log(obj2);
console.log(obj3);
