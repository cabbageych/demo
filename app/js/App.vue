<template>
  <div id="app">
    <div id="mask">
      <hr id="centerLine" />
      <div id="centerCircle"></div>
      <p id="welcome">welcome to cabbage's chatRoom!</p>
    </div>
    <div id="wrap">
      <div id="partLeft">
        <a id="returnToMain" href="http://www.huajiyang.com/chenhui/mainPage.html">点击返回主页</a>
        <div id="contentShow"></div>
        <hr style="background:black;height:3px;width:100%;" />
        <textarea id="contentInput"></textarea>
        <button id="sendMessage" @click="sendMessage">click to send message!</button>
      </div>
      <div id="partRight">
        <div id="inner">
          <p style="font-size:25px;color:lightyellow;margin-bottom:10px;margin-top:5vh;">在线成员列表</p>
          <ul id="memberList" style="font-size:20px;">
            <ol v-for="item in memberList">{{item}}</ol>
          </ul>
        </div>
      </div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      ws: null,
      selfName: "",
      memberList: [],
      overTime: 8000,
      lastResponse: ""
    };
  },
  beforeMount() {
    setTimeout(() => {
      document.getElementById("mask").style.display = "none";
    }, 3000);
  },
  mounted() {
    let _this = this;
    this.ws = new WebSocket("ws://localhost:8080");
    this.ws.addEventListener("open", function(e) {
      console.log("Connetion to server opended.");
    });
    this.ws.addEventListener(
      "message",
      function(e) {
        _this.lastResponse = new Date();
        if (e.data == "alive!") {
          //console.log(e.data);
          return;
        }
        let data = JSON.parse(e.data);
        if (data.type == 0) {
          this.selfName = data.name;
        } else if (data.type == 1) {
          //console.log(data.memberList);
          this.memberList = data.memberList;
          for (let i = 0; i < this.memberList.length; i++) {
            if (this.selfName == this.memberList[i]) {
              this.memberList[i] = "me";
            }
          }
        } else {
          let contentShow = document.getElementById("contentShow");
          let p = document.createElement("p");
          let strong = document.createElement("strong");
          if (data.name == this.selfName) {
            strong.innerText = "me";
          } else {
            strong.innerText = data.name;
          }
          p.appendChild(strong);
          p.append(data.message);
          contentShow.appendChild(p);
          //console.log("Client receive a message from server: "+e.data);
        }
      }.bind(this)
    );
    setInterval(() => {
      _this.ws.send(JSON.stringify({ ping: "1" }));
      if (new Date() - _this.lastResponse > _this.overTime) {
        console.log("断线重连...");
        _this.ws = new WebSocket("ws://localhost:8080");

        _this.ws.addEventListener("open", function(e) {
          console.log("Connetion to server opended.");
        });
        _this.ws.addEventListener("message", function(e) {
          _this.lastResponse = new Date();
          if (e.data == "alive!") {
            return;
          }
          let data = JSON.parse(e.data);
          if (data.type == 0) {
            _this.selfName = data.name;
          } else if (data.type == 1) {
            //console.log(data.memberList);
            _this.memberList = data.memberList;
            for (let i = 0; i < _this.memberList.length; i++) {
              if (_this.selfName == _this.memberList[i]) {
                _this.memberList[i] = "me";
              }
            }
          } else {
            let contentShow = document.getElementById("contentShow");
            let p = document.createElement("p");
            let strong = document.createElement("strong");
            if (data.name == _this.selfName) {
              strong.innerText = "me";
            } else {
              strong.innerText = data.name;
            }
            p.appendChild(strong);
            p.append(data.message);
            contentShow.appendChild(p);
            //console.log("Client receive a message from server: "+e.data);
          }
        });
      }
    }, 5000);
  },
  methods: {
    sendMessage: function() {
      //console.log(this.memberList);
      let content = document.getElementById("contentInput").value;
      if (content.trim() == "") {
        alert("输入内容不能为空!");
      } else {
        this.ws.send(content);
        document.getElementById("contentInput").value = "";
      }
    }
  }
};
</script>
<style>
body,
html {
  padding: 0;
  margin: 0;
}
strong {
  color: red;
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
#wrap {
  display: flex;
  flex-direction: row;
}
#partLeft {
  background: rgb(218, 218, 194);
  width: 70vw;
  height: 100vh;
  display: flex;
  flex-direction: column;
}
#partRight {
  background: rgb(210, 222, 230);
  width: 30vw;
  height: 100vh;
  text-align: center;
}
#contentShow {
  position: relative;
  height: 50vh;
  width: 50vw;
  background: lightcyan;
  left: 10vw;
  margin-top: 1vh;
  border: none;
  font-size: 18px;
  border-radius: 20px;
  overflow: auto;
}
#contentShow > p {
  margin-left: 10px;
  margin-top: 8px;
  margin-bottom: 8px;
}
#contentShow > p > strong {
  margin-right: 10px;
}
#contentInput {
  position: relative;
  height: 140px;
  width: 50vw;
  background: white;
  left: 10vw;
  margin-top: 10px;
  border: none;
  font-size: 18px;
  border-radius: 10px;
}
#sendMessage {
  position: relative;
  margin-top: 10px;
  height: 40px;
  width: 30vw;
  font-size: 18px;
  border: none;
  left: 20vw;
  background: rgb(146, 153, 221);
  border-radius: 6px;
  font-size: 20px;
}
#inner {
  position: relative;
  background: lightseagreen;
  width: 15vw;
  height: 70vh;
  margin: 0 auto;
  border-radius: 10px;
}
#memberList {
  padding: 0;
  margin: 0;
}
#memberList > ol {
  padding: 0;
  margin: 0;
}
#returnToMain {
  border: none;
  border-radius: 5px;
  height: 40px;
  width: 100%;
  margin: 0;
  padding: 0;
  background: rgb(79, 114, 212);
  text-align: center;
  text-decoration: none;
  color: rgb(231, 235, 209);
  line-height: 40px;
  font-size: 20px;
}
</style>