const input= [2,7,11,4,-2];

let sum=0;
input.map((i)=>{
    sum=sum+i;
});

output=[];
let sum2=0;
input.map((i)=>{
    output.push(sum-i);
})
console.log(output); //[ 20, 15, 11, 18, 24 ]
