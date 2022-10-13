//Parent Component
import { useState,useMemo } from "react";
import Child from "./Child";
export default function App(){

  const [one,setOne]=useState(1)

  return(
    <div>
   <h1>Memo</h1>
   <Child />
   <button onClick={()=>{setOne(one+1)}}>Click 1</button>
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
