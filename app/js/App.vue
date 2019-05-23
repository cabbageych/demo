<template>
  <div id="app">
    <div id="mask">
      <hr id="centerLine">
      <div id="centerCircle"></div>
      <p id="welcome">welcome to cabbage's chatRoom!</p>
    </div>
    <div id="wrap">
      <div id="partLeft">
        <textarea id="contentShow"></textarea>
        <textarea id="contentInput"></textarea>
        <div>
          <button id="sendMessage" @click="sendMessage">Send</button>
        </div>
        
      </div>
      <div id="partRight"></div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      ws: null
    };
  },
  beforeMount() {
    setTimeout(() => {
      document.getElementById("mask").style.display = "none";
    }, 1000);
  },
  mounted() {
    /*this.ws = new WebSocket("ws://localhost:8080");
    this.ws.addEventListener('open',function(e){
      console.log("Connetion to server opended.");
    });
    this.ws.addEventListener('message',function(e){
      console.log("Client receive a message from server: "+e.data);
    });*/
  },
  methods: {
    sendMessage: function() {
      let content = document.getElementById("contentInput").value;
      //console.log(content);
      this.ws.send(content);
    }
  }
};
</script>
<style>
* {
  padding: 0;
  margin: 0;
}
#mask {
  position: absolute;
  width: 100vw;
  height: 100vh;
  background: lightblue;
  margin: 0;
  padding: 0;
  z-index: 1;
  text-align: center;
}
#centerLine {
  position: relative;
  top: 35%;
  height: 6px;
  background: rgb(139, 137, 137);
  border: none;
  z-index: 2;
}
#centerCircle {
  position: absolute;
  height: 250px;
  width: 250px;
  border-radius: 50%;
  border-width: 5px;
  border-color: white;
  border-style: solid;
  box-shadow: 0 0 20px rgb(129, 126, 126);
  background: url("../img/huaji.jpg");
  background-size: cover;
  background-repeat: no-repeat;
  top: 35%;
  left: 50%;
  margin-top: -125px;
  margin-left: -125px;
  z-index: 3;
  animation: 10s circleRotate linear infinite;
}

@keyframes circleRotate {
  from {
    transform: rotate(0deg);
  }

  to {
    transform: rotate(360deg);
  }
}
#welcome {
  position: absolute;
  top: 35%;
  left: 50%;
  font-size: 50px;
  transform: translateX(-50%);
  margin-top: 180px;
}
#contentShow {
  position: relative;
  height: 50vh;
  width: 50vw;
  background: lightcyan;
  top: 5vh;
  left: 10vw;
  border: none;
  font-size: 18px;
}
#contentInput {
  position: relative;
  height: 20vh;
  width: 50vw;
  background: rgb(230, 221, 101);
  top: 5vh;
  left: 10vw;
  border: none;
  font-size: 18px;
}
#sendMessage {
  position: relative;
  height: 40px;
  width: 60px;
  font-size: 18px;
  border: none;
  left: 50%;
  background: rgb(106, 117, 219);
  border-radius: 10px;
}
#wrap{
  display:flex;
  justify-content: row;
}
#partLeft{
  background: lightgoldenrodyellow;
  width:70vw;
  height:100vh;
  display: grid;
  grid-template-columns: 70vh 20vh 10vh;
  
}
#partRight{
  background: lightcoral;
  width:30vw;
  height:100vh;
}
</style>