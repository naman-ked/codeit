/* Input : "This is Javascript Code"  */

let s="This is a Javasript code";

const arr= s.split(' ');
let reversedArr= [];

console.log(arr); //[ 'This', 'is', 'a', 'Javasript', 'code' ]

reversedArr= arr.map((item)=>item.split('').reverse().join('')).join(' ');

console.log(reversedArr)  //sihT si a tpirsavaJ edoc

// Yes, it is possible in Js to create a reverse() method that can reverse any string 
// and it can be done by adding your custom reverse logic to String.prototype
