const myPromise= new Promise((resolve,reject)=>{
    const x=false;
    if(x) resolve("Hello");
    else reject("Bye");
})

myPromise.then(
    (val)=>{console.log(val)},
    (val)=>{console.warn(val)}
    );

//Promise Chaining
const res = new Promise((res,rej)=>{
    setTimeout(()=>res(),2000);
})

res.then(()=>{
    console.log("Prmoise1");
}).then(()=>{
    console.log("Promise2");
})
