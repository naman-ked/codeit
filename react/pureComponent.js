import {PureComponent} from "react";
import "./styles.css";
class App extends PureComponent {
  state={
    count:10
  }
render(){
  console.log("render");
  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <h3>Pure component</h3>
      <button onClick={()=>{
        this.setState({count:10})
      }}>
        Click
      </button>
      <br />
      <h4>{this.state.count}</h4>    
    </div>
  );
}
}
export default App;
