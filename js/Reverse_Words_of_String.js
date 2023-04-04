/* Input : "This is Javascript Code"  */

let s="This is a Javasript code";

const arr= s.split(' ');
let reversedArr= [];

console.log(arr); //[ 'This', 'is', 'a', 'Javasript', 'code' ]

reversedArr= arr.map((item)=>item.split('').reverse().join('')).join(' ');

console.log(reversedArr)  //sihT si a tpirsavaJ edoc
