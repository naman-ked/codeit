//class component
import React from "react";
  
class App extends React.Component {
    constructor() {
        super();
        this.state = {
            message: "initial state"
        }
        console.log("Constructor called");
    }
    
    componentDidMount() {
        console.log("componentDidMount called");
    }
  
    componentWillUpdate(nextProps, nextState) {
      console.log("Phase 3: UPDATING -> Component Will update!");
    }
    
    componentDidUpdate(prevProps, prevState) {
      console.log("Phase 3: UPDATING -> Component Did update!");
    }
    
    // Unmount of component 
    componentWillUnmount() {
      console.log("Component Will unmount!");
    }
  
    call() {
        this.setState({ message: "state updated" })
    }
  
    render() {
        console.log("render called");
  
        // Rendering a button
        return (
            <div style={{ margin: 100 }}>
                <button onClick={() => { this.call() }}>
                    Click to update state!
                </button>
                  
                <p>{this.state.message}</p>
            </div>
        );
    }
}
  
export default App;

//function component
import { useEffect, useState } from "react";
import "./styles.css";

export default function App() {
  const [name, setName] = useState("naman");

  useEffect(() => {
    console.log("component Render");
  });

  useEffect(() => {
    console.log("componentDidMount");
  }, []);

  useEffect(() => {
    console.log("componentDidUpdate");
  }, [name]);

  useEffect(() => {
    return () => {
      console.log("componentWillUnmount");
    };
  }, []);

  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>

      <h3>Life Cycle methods</h3>
      <button onClick={()=>{setName(name+".")}}>Click</button>
      <h4>{name}</h4>
    </div>
  );
}
