class Car extends React.component{
 
  const myDebounce = (cb,d) =>{
    let timer;
    return function(...args) {
      if(timer) clearTimeOut(timer);
      timer= setTimeout(function() {
        cb();
      }, d);
    };
  };
  
  const handleChange = myDebounce((e)=>{
    console.log(e.target.value);
  },1000);
  
  render(){
    return(
      <div>
        <input onChange={handleChange} />
      </div>
      );
  }
    
}
