const arr=[1,2,3,4,5,6,7];
let n=arr.length;
let k=10%n;
let output=[];
for(let i=0;i<n;i++){
    if(i<k) output[i]=arr[n+i-k];
    else output[i]=arr[i-k];
};

console.log(output); //[5, 6, 7, 1, 2, 3, 4]
