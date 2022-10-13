//CLASS Component
import {Component} from "react";
import "./styles.css";
class App extends Component {
  state={
    joke:""
  }
  async componentDidMount(){
    console.log("componentDidMount");
    let url="https://official-joke-api.appspot.com/random_joke"
    const joke=await fetch(url).then((response)=>response.json())
    this.setState({joke:joke})
  }

render(){
  console.log("render");
  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>
      <h3>Fetch data from API</h3>
      <h4>{this.state.joke.setup}</h4>
      <h4>{this.state.joke.punchline}</h4>    
    </div>
  );
}
}
export default App;

//Functional Component
