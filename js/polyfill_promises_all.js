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

var promises = [importantAction("Hello to Promise 1"),importantAction2("Hello to Promise 2")];

Promise.allPolyfill= (promises) =>{
    return new Promise((resolve,rej)=>{
        let results= [];
        if(!promises.length){
            resolve(results);
            return
        }
        let pending = promises.length;
        promises.forEach((promise,index)=>{
            Promise.resolve(promise).then((res)=>{
                results[index]=res;
                pending--;
                if(pending===0){
                    resolve(results);
                }
            },rej)
        })
    })
}

Promise.allPolyfill(promises).then((res)=>{
    console.log(res);
}).catch((err)=>{console.log(err)});
