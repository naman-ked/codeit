import "./styles.css";

function getContent(offset, num) {
  let arr = [];
  for (var i = offset; i < offset + num; i++) {
    arr.push(i);
  }
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(arr);
    }, Math.random() * 2000);
  });
}

const box= document.getElementById("root");

const handleContent=(result)=>{
  const frag = document.createDocumentFragment();
  
  result.map((number)=>{
    const div=document.createElement(div);
    div.innerHTML=number;
    div.classList.add("number-styling");
    frag.appendChild(div);
  });
  
  box.appendChild(frag);
}

  const res= getContent(1,50)
  res.then((r)=>{
    handleContent(r);
  })

  let offset=50;

  const handleCall=(event)=>{
    if(box.scrollTop>=(offset*1))
    {
      console.log("reached end");
      box.innerHtml="";
      const res= getContent(offset+1,offset+50);
      res.then((r)=>{
       handleContent(r);
     })
    offset+=50;
    }
  }

  box.addEventListener("scroll",handleCall);


#html
<!DOCTYPE html>
<html>
  <head>
    <title>Parcel Sandbox</title>
    <meta charset="UTF-8" />
  </head>

  <body>
    <div id="root" class="container"></div>

    <script src="src/index.js"></script>
  </body>
</html>

#css
body {
  font-family: sans-serif;
}

.container {
  height: 300px;
  width: 80%;
  border: 1px solid black;
  overflow-y: scroll;
  word-wrap: break-word;
}

.number-styling {
  font-size: 40px;
  width: 50px;
  height: 50px;
  background-color: #d3d3d8;
  margin: 10px;
}
