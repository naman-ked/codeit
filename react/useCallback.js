//Parent component
import { useState,useMemo, useCallback } from "react";
import Child from "./Child";
export default function App(){

  const [one,setOne]=useState(1);
  const [two,setTwo]=useState(1);
  
  const Even=useCallback(()=>{
      console.log("even")
  },[two])

  return(
    <div>
   <h1>Memo</h1>
   <Child two={two} fun={Even}/>
   <button onClick={()=>{setOne(one+1)}}>Click 1</button>
   <button onClick={()=>{setTwo(two+1)}}>Click 2</button>
   </div>
  );
}

//Child component
import { memo } from "react";

const Child=()=>{
  console.log("child component rendered");
  return(
    <h1>Child component</h1>
  );
}

export default memo(Child);
