let name = {
 firstname:"Naman",
 lastname: "Kedia",
}

let printFullName = function(hometown,state) {
  console.log(this.firstName + " " + this.lastname + " from " + hometown + ", " + state)
}

printFullName.call(name, "Dehradun", "Uttarakhand")

let name2 = {
    firstname:"Sachin",
    lastname: "Tendulkar",
}

printFullName.call(name2, "Mumbai", "Maharashtra");
printFullName.apply(name2, ["Mumbai", "Maharashtra"]);

let printName = printFullName.call(name2, "Mumbai", "Maharashtra");
console.log(printName);
printName();
