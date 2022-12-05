const myPromise= new Promise((resolve,reject)=>{
    const x=false;
    if(x) resolve("Hello");
    else reject("Bye");
})

myPromise.then(
    (val)=>{console.log(val)},
    (val)=>{console.warn(val)}
    );
