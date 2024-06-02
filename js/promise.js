// link : https://www.programiz.com/javascript/promise

const myPromise= new Promise((resolve,reject)=>{
    const x=false;
    if(x) resolve("Hello");
    else reject("Bye");
})

myPromise.then(
    (val)=>{console.log(val)},
    (val)=>{console.warn(val)}
    );

//Promise Chaining Solution to callback hell
function importantAction(message){
    return new Promise((res,rej)=>{
    setTimeout(()=>res(message),1000);
})
}

function importantAction2(message){
    return new Promise((res,rej)=>{
    setTimeout(()=>res(message),1000);
})
}

importantAction("Hello to Promise 1").then((res)=>{
    console.log(res);
    return importantAction("Hello to Promise 2").then((res)=>{
    console.log(res);
})
})

//Promise Combinators

// Promise.all([array of promises]).then(()=>{}).catch(()=>{})  returns only if all promises are resolved otherwise catch
Promise.all([importantAction("Hello to Promise 1"),importantAction2("Hello to Promise 2")]).then((res)=>{
    console.log(res);
})
Output:
[ 'Hello to Promise 1', 'Hello to Promise 2' ]

// Promise.race([array of promises]).then(()=>{}).catch(()=>{}) returns the first selected or rejected
Promise.race([importantAction("Hello to Promise 1"),importantAction2("Hello to Promise 2")]).then((res)=>{
    console.log(res);
})
Output:
Hello to Promise 1

// Promise.allSettled([array of promises]).then(()=>{}).catch(()=>{}) returns all the promises
Promise.allSettled([importantAction("Hello to Promise 1"),importantAction2("Hello to Promise 2")]).then((res)=>{
    console.log(res);
})
Output:
[
  { status: 'fulfilled', value: 'Hello to Promise 1' },
  { status: 'fulfilled', value: 'Hello to Promise 2' }
]

// Promise.any([array of promises]).then(()=>{}).catch(()=>{})
// returns the first fullfilled promise only  ignores all the errors unless all the promises failed
