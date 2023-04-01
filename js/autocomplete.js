//html 
<!DOCTYPE html>
<html>
  <head>
    <title>Autocomplete</title>
    <meta charset="UTF-8" />
  </head> 
  
  <body>
    <div id="app">
      <h1>Search</h1>
      <input type="text" id="search-input">
      <section id="suggestion-wrapper"></section>
    </div>
  </body>
 </html>

//css
#app {
  width: 400px;
  position: realtive;
  display: inline-block;
}

input{
  width:100%;
  height:50px;
  border-radius: 4px;
  outline:none;
}

input:focus{
  border: 2px solid blue;
}

.suggestions-wrapper {
  display:block;
  max-height:300px;
  overflow-y:scroll;
  border: 1px solid silver;
}

//js

const fruits=["banana","apple","mango","lichi","almond"];

const getSuggestions = (keyword) =>{
  const result = fruits.filter(i=> i.substr(0,keyword.length).toLowerCase()===keyword.toLowerCase())
  return new Promise((res)=>{
    setTimeout(()=>res(result),1000);
  })
}  



const inputBox = document.getElementById("search-input");
const suggestionBox = document.getElementById("suggestion-wrapper");

const renderDropdownItems = (list=[]) => {
  const suggFrag = document.createDocumentFragment();
  
  list.forEach((item)=>{
    const el= document.createElement('div');
    el.innerHTML= item
    el.classList.add("dropdown-item");
    suggFrag.appendChild(el);
  })
  suggestionBox.innerHTML="";
  suggestionBox.appendChild(suggFrag);
}

const handleSearch = async (keyword) => {
  const result = await getSuggestions(keyword);
  if(result.length!=fruits.length){
    suggestionBox.classList.add("suggestions-visible");
     renderDropdownItems(result);
  }
  else{
    renderDropdownItems();
  }
  console.log(result);
}

const handleInputChange = (event) =>{
  const value= event.target.value;
  handleSearch(value);
  
};


const debounce = (fn,delay=5000)=>{
  let timerCtx;
  return function(){
    const self=this;
    const args= arguments;
    clearTimeout(timerCtx);
    timerCtx=setTimeout(()=> fn.apply(self,args),delay);
  }
}

(()=>{
  inputBox.addEventListener("input",debounce(handleInputChange,500));
})();


