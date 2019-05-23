<template>
  <div id="app">
    <div id="mask">
      <hr id="centerLine">
      <div id="centerCircle"></div>
      <p id="welcome">welcome to cabbage's chatRoom!</p>
    </div>
    <textarea id="contentInput"></textarea>
    <hr>
    <button id="sendMessage" @click="sendMessage">Send</button>
    <button id="exit" @click="closeConnection">close connection</button>
  </div>
</template>
<script>

export default {
  data() {
    return {
      ws:null
    };
  },
  beforeMount(){
    setTimeout(()=>{
      document.getElementById('mask').style.display = 'none';
    },3000);
  },
  mounted(){
    this.ws = new WebSocket("ws://localhost:8080");
    this.ws.addEventListener('open',function(e){
      console.log("Connetion to server opended.");
    });
    this.ws.addEventListener('message',function(e){
      console.log("Client receive a message from server: "+e.data);
    });
  },
  methods:{
    sendMessage:function(){
      let content = document.getElementById('contentInput').value;
      console.log(content);
      this.ws.send(content);
    },
    closeConnection:function(){
      this.ws.onclose = function(){
        console.log("cancel connection!");
      }
    }
  }
};
</script>
<style>
  *{
    padding:0;
    margin:0;
  }
  #mask{
    position:absolute;
    width:100vw;
    height:100vh;
    background:lightblue;
    margin:0;
    padding:0;
    z-index: 1;
    text-align: center;
  }
  #centerLine{
    position:relative;
    top:35%;
    height:6px;
    background: rgb(139, 137, 137);
    border:none;
    z-index: 2;
  }
  #centerCircle{
    position:absolute;
    height:250px;
    width:250px;
    border-radius: 50%;
    border-width:5px;
    border-color: white;
    border-style: solid;
    box-shadow: 0 0 20px rgb(129, 126, 126);
    background: url('../img/huaji.jpg');
    background-size: cover;
    background-repeat: no-repeat;
    top:35%;
    left:50%;
    margin-top: -125px;
    margin-left: -125px;
    z-index: 3;
    animation: 10s circleRotate linear infinite;
  }

  @keyframes circleRotate{
    from{
      transform: rotate(0deg);
    }

    to{
      transform: rotate(360deg);
    }
  }
  #welcome{
    position:absolute;
    top:35%;
    left:50%;
    font-size: 50px;
    transform: translateX(-50%);
    margin-top: 180px;
  }
  #contentInput{
    position:relative;
    height:300px;
    width:800px;
    background: lightcyan;
    top:30%;
    left:20%;
    border:none;
    font-size: 18px;
  }
  #sendMessage{
    position:relative;
    height:40px;
    width:60px;
    font-size: 18px;
    border:none;
    left:50%;
    background: rgb(106, 117, 219);
    border-radius: 10px;
  }
  #exit{
    position:relative;
    height:40px;
    font-size: 18px;
    border:none;
    left:50%;
    background: rgb(106, 117, 219);
    border-radius: 10px;
  }
</style>