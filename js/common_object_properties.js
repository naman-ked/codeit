const input1= {a:1, b:2 , c:3, d:10, e:12};
const input2= {a:2 , f:10, d:10, e:12};

let common_cache={};

Object.keys(input1).map((key)=>{
  if(input2[key]==input1[key]){
    common_cache[key]=input1[key];  
  }  
})

console.log(common_cache); //{ d: 10, e: 12 }
