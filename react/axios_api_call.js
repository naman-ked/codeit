//Post call

var postData = {
  email: "test@test.com",
  password: "password"
};

let axiosConfig = {
  headers: {
      'Content-Type': 'application/json;charset=UTF-8',
      "Access-Control-Allow-Origin": "*",
  }
};

axios.post('http://<host>:<port>/<path>', postData, axiosConfig)
.then((res) => {
  console.log("RESPONSE RECEIVED: ", res);
})
.catch((err) => {
  console.log("AXIOS ERROR: ", err);
})





//Class component
import axios from "axios";
import {Component} from "react";
import "./styles.css";
class App extends Component {
  state={
    joke:""
  }
  async componentDidMount(){
    console.log("componentDidMount");
    let url="https://official-joke-api.appspot.com/random_joke"
    const joke=await axios.get(url)
    this.setState({joke:joke.data})
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

//Functional component
import axios from "axios";
import { useEffect, useState } from "react";
import "./styles.css";

export default function App() {
  const [joke, setJoke] = useState({});

  useEffect(() => {
    console.log("componentDidMount");
    async function fetchData() {
    await axios.get("https://reqres.in/api/users?page=2")
        .then(res=>{
          console.log(res.data.data[0])
        setJoke(res.data.data[0]);
      }).catch(err=> {
        console.log(err);
      })
  }
  fetchData();
  },[]);

  return (
    <div className="App">
      <h1>Hello CodeSandbox</h1>
      <h2>Start editing to see some magic happen!</h2>

      <h3>Fetch data from API</h3>
      <h4>{joke.id}</h4>
      <h4>{joke.email}</h4>
    </div>
  );
}
