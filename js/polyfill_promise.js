function Pro(executor){
    let onResolve, onReject;
    let isFullfilled =false,isCalled=false,value;
    function resolve(val){
        isFullfilled=true;
        value=val;
        if(typeof onResolve === 'function'){
            onResolve(value);
            isCalled=true;
        }
        
    }
    
    function reject(value){
        
        onReject(value);    
    }
    
    this.then = function (callback) {
        onResolve = callback;
        if(isFullfilled && !isCalled){
            called=true;
            onResolve(value);
        }
        return this;
    }
    
    this.catch = function(callback) {
      return this;  
    };
    
    executor(resolve,reject);
}


const examplePromise = new Pro((resolve,reject)=>{
    setTimeout(()=>{
        resolve(2);
    },1000);
});

examplePromise.then((res)=>{
    console.log(res);
}).catch((err)=>{console,log(err)});
