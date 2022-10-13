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
