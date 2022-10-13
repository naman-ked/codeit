import { createRef, useRef } from "react";
import "./styles.css";

export default function App() {
  const inputValue=useRef();
  //const inputValue=createRef();
  const handleSubmit=()=>{
    console.log(inputValue.current.value)
  }
  return (
    <div className="App">
      <h1>Uncontrolled Component</h1>
      <label>Name :</label>
      <input placeholder={"Enter your name"} ref={inputValue}/>
      <button onClick={handleSubmit}>Submit</button>
    </div>
  );
}
