// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

console.log("Try programiz.pro");


let counter = 0;
function getData(){
    console.log("fetching data..."+counter++);
}

function debounce(call, d){
    let timer;
    return function(...args){
        if(timer) clearTimeout(timer);
        timer = setTimeout(()=>{
           call(args); 
        },d)
    }
}

const myBetterFunction = debounce(getData,2000);
myBetterFunction();
myBetterFunction();
myBetterFunction();
myBetterFunction();
myBetterFunction();
myBetterFunction();

function throttle(func, delay) {
    let timeout=null
    return () => { 
        if(!timeout) {
            func()
            timeout=setTimeout(() => {
                timeout=null
            }, delay)
        }
    }
}

const throttledFun = throttle(getData, 500)
throttledFun(); // This will execute immediately
throttledFun(); // This will be ignored
setTimeout(() => {
  throttledFun(); // This will also be ignored
}, 1800);
setTimeout(() => {
  throttledFun(); // This will execute
}, 600);
