
arr = [1,2,3,4,5]

arr.forEach((val,index)=>{
    arr[index]+=val;
}
);

arr = [1,2,3,4,5]

arr2 = arr.map((item,index)=>{
    return item = item * 2;
}).map((item,index)=>{
    return item = item * 2;
})

console.log(arr2[1]);
arr3 = arr.filter((item,index)=>{
    return item>2; 
})
console.log(arr3[0], arr3[1], arr3[2]);

arr4 = arr.reduce((item,initial_value)=>{
    return item+initial_value; 
},0)
console.log(arr4);
