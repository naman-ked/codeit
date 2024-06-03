const calls = [
  { name: "Jamie", numOfCalls: 7 },
  { name: "Anna", numOfCalls: 2 },
  { name: "Sam", numOfCalls: 3 },
  { name: "Tony", numOfCalls: 8 },
  { name: "Jamie", numOfCalls: 7 },
  { name: "Anna", numOfCalls: 1 },
  { name: "Sam", numOfCalls: 16 },
  { name: "Tony", numOfCalls: 1 },
  { name: "James", numOfCalls: 1 },
]; 

const listOfCalls = calls.map((item,index)=>{
    return `Hi, ${item.name} You have this many number of calls - ${item.numOfCalls}`; 
})

const uniqueListOfCalls = calls.reduce((currentobj, item)=>{
    if(currentobj.hasOwnProperty(item.name)){
        currentobj[item.name]+=item.numOfCalls;
    }
    else{
        currentobj[item.name]=item.numOfCalls;
    }
    return currentobj;
},{})
console.log(uniqueListOfCalls)
let callsArray= [];
Object.keys(uniqueListOfCalls).forEach((key)=>{
  callsArray.push({"name" : key, "numOfCalls":uniqueListOfCalls[key]});  
});

callsArray.sort((a,b)=>{
    return a.numOfCalls - b.numOfCalls
})

console.log(callsArray)
