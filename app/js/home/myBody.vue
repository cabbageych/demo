<template>
  <div>
    <div id="myBody">
      <nav>
        <div style="color:rgb(224, 85, 20);">商品列表</div>
        <div @click="showlist01 = !showlist01">服饰</div>
        <p v-if="showlist01" @click="showType(1)">衣裤</p>
        <div @click="showlist02 = !showlist02">电子数码</div>
        <p v-if="showlist02" @click="showType(2)">手机</p>
        <p v-if="showlist02" @click="showType(3)">电脑</p>
        <div @click="showlist03 = !showlist03">食品</div>
        <p v-if="showlist03" @click="showType(4)">零食</p>
        <p v-if="showlist03" @click="showType(5)">生鲜</p>
        <div @click="showlist04 = !showlist04">文体办公</div>
        <p v-if="showlist04" @click="showType(6)">体育用品</p>
        <p v-if="showlist04" @click="showType(7)">办公用品</p>
        <div @click="showTypeAll">商品全种类展示</div>
      </nav>
      <div id="mainPart">
        <div class="test" v-for="(item,key,index) in resultsTemp">
          <img :src="returnSrc(item)" title="点击图片查看详情" @click="showDetail(item)">
          <p class="p1">{{item.name}}</p>
          <p class="p2">
            <label>价格:</label>
            ¥{{item.price}}&nbsp;&nbsp;
            <button
              @click="addToCart($event,key)"
              class="addCart"
            >加入购物车</button>
          </p>
        </div>
        <button id="topButton" @click="scrollTopToZero">返回顶部</button>
      </div>
    </div>
    <div id="detailWindow">
      <img
        src="#"
        id="img"
        style="display:inline-block;height:300px;width:300px;position:relative;margin:0 auto;"
      >
      <div style="position:relative;">
        <p id="name"></p>
        <p id="price"></p>
        <p id="totalCount"></p>
        <p id="des"></p>
        <p id="seller"></p>
        <button @click="hideDetail">返回</button>
      </div>
    </div>
    <p id="p" style="position:absolute;color:rgb(31, 196, 80);display:none;font-size:20px;">添加成功!</p>
  </div>
</template>
<script>
import url from "../../img/huaji.jpg";
let body = document.getElementsByTagName("body")[0];
export default {
  data() {
    return {
      resultsTemp: [],
      results: [
        /*{
          id: 111,
          type: 3,
          name: "薛定谔的滑稽",
          price: 999,
          src: url
        },
        {
          id: 222,
          type: 4,
          name: "薛定谔的滑稽02",
          price: 999,
          src: url
        },
        {
          id: 444,
          type: 1,
          name: "薛定谔的滑稽04",
          price: 999,
          src: url,
          des: "emmmm des for test!",
          totalCount: 99,
          sellerName: "cabbage"
        },
        {
          id: 555,
          type: 5,
          name: "薛定谔的滑稽05",
          price: 999,
          src: url
        },
        {
          id: 666,
          type: 6,
          name: "薛定谔的滑稽06",
          price: 999,
          src: url
        },
        {
          id: 666,
          type: 7,
          name: "薛定谔的滑稽07",
          price: 999,
          src: url
        },
        {
          id: 666,
          type: 2,
          name: "薛定谔的滑稽08",
          price: 999,
          src: url
        }*/
      ],
      showlist01: false,
      showlist02: false,
      showlist03: false,
      showlist04: false,
      cart: [],
      timer: null
    };
  },
  methods: {
    returnSrc: function(item) {
      //console.log(this);
      //console.log(item.url);
      //console.log('test');
      //console.log((item.src).replace('img//','img/'));
      return item.url;
    },
    hideDetail: function() {
      detailWindow.style.display = "none";
    },
    showDetail: function(item) {
      let detailWindow = document.getElementById("detailWindow");
      detailWindow.style.display = "block";
      detailWindow.childNodes[0].src = item.url;
      let temp = detailWindow.childNodes[2].childNodes;
      temp[0].innerHTML = "商品名称: " + item.name;
      temp[2].innerHTML = "价格: " + item.price;
      temp[4].innerHTML = "仓库剩余: " + item.totalCount;
      temp[6].innerHTML = "详情: " + item.description;
      temp[8].innerHTML = "卖家: " + item.shopName;
    },
    scrollTopToZero: function() {
      mainPart.scrollTop = 0;
    },
    showTypeAll:function(){
      this.resultsTemp = this.results;
    },
    showType: function(type) {
      this.resultsTemp = [];
      for (let i = 0; i < this.results.length; i++) {
        if (this.results[i].type == type) {
          this.resultsTemp.push(this.results[i]);
        }
      }
    },
    addToCart: function(e, num) {
      let p = document.getElementById('p');
      p.style.left = e.pageX-10;
      p.style.top = e.pageY+3;
      p.style.display = 'block';
      let tempCart = {};
      tempCart.id = this.results[num].id;
      tempCart.type = this.results[num].type;
      tempCart.name = this.results[num].name;
      tempCart.price = this.results[num].price;
      tempCart.count = 1;
      this.$emit("cart", tempCart); //向父组件传值
      setTimeout(()=>{
        let p = document.getElementById('p');
        p.style.display = 'none';
      },1000);
    },
    returnToTop: function(e) {
      if (e.target.scrollTop > 350) {
        this.showTopTag(e);
      }
    },
    showTopTag: function(e) {
      topButton.style.display = "block";
      topButton.style.right = 0;
      topButton.style.top = e.target.scrollTop + 100 + "px";
      if (this.timer) {
        clearTimeout(this.timer);
      }
      this.timer = setTimeout(function() {
        let topButton = document.getElementById("topButton");
        topButton.style.display = "none";
      }, 5000);
    }
  },
  mounted() {
    //console.log("myBody:");
    fetch("http://localhost:8082", {
      method: "GET"
    })
      .then(response => {
        return response.json();
      })
      .then(val => {
        /*for(let i = 0;i<val.length;i++){
          console.log(val[i]);
        }*/
        this.results = val;
        this.resultsTemp = this.results;
        //console.log(this.resultsTemp);
        let tempCount = localStorage.getItem("cartNum");
        if (tempCount >= 0) {
          this.countTest = tempCount;
        }
        let mainPart = document.getElementById("mainPart");
        let topButon = document.getElementById("topButton");
        mainPart.addEventListener("scroll", this.returnToTop);
      });
  }
};
</script>
<style>
#img {
  color:rgb(31, 196, 80);
  margin: 0;
  padding: 0;
  transform: translateX(20%);
  top: 10px;
}
#detailWindow {
  display: none;
  position: absolute;
  height: 600px;
  width: 600px;
  box-shadow: 0 0 20px gray;
  background: white;
  top: 50%;
  left: 50%;
  transform: translate(-50%, -50%);
  text-align: center;
  font-size: 20px;
  border-radius: 20px;
  padding-top:30px;
}
#detailWindow img{
  left:-65px;
}
#detailWindow p {
  margin: 0;
  margin-top: 10px;
  padding: 0;
}
#detailWindow button {
  border: none;
  margin-top: 10px;
  border-radius: 10px;
  font-size: 18px;
  height: 40px;
  width: 60px;
  background: rgb(83, 73, 230);
  color:white;
}
#detailWindow button:focus,
#detailWindow button:hover {
  outline: none;
  border: 2px solid rgb(73, 69, 69);
  background: yellow;
  color:black;
}
#topButton {
  position: absolute;
  height: 30px;
  width: 80px;
  border: 2px solid yellow;
  border-radius: 10px;
  color: white;
  font-size: 15px;
  background: lightblue;
  display: none;
}
#topButton:hover {
  color: black;
  background: lightyellow;
  border: 2px solid red;
}
#topButton:focus {
  outline: none;
}
#myBody {
  display: flex;
  flex: 1;
}

nav {
  text-align: center;
  width: 12%;

  background: rgb(245, 243, 243);
  font-size: 23px;
  white-space: nowrap;
}
nav div:not(:first-child) {
  border-radius: 6px;
  border: 1px solid rgb(188, 230, 243);
  background: rgb(169, 212, 238);
}

nav div:not(:first-child):active,
nav div:not(:first-child):hover {
  color: white;
  background: rgb(54, 78, 212);
}
nav p {
  position: relative;
  background: white;
  margin: 0;
  padding: 0;
  color: rgb(104, 108, 109);
  border-radius: 5px;
  border: 1px solid rgb(165, 164, 164);
}
nav p:hover,
nav p:active {
  color: rgb(238, 49, 153);
}

#mainPart {
  display: flex;
  flex-wrap: wrap;
  align-content: flex-start;
  flex-direction: row;
  overflow: auto;
  width: 88%;
  height: 100vh;
  padding-top: 10px;
  position: relative;
}
.test {
  display: flex;
  flex-direction: column;
  align-items: center;
  position: relative;
  height: 20vw;
  width: 20vw;
  box-shadow: 0 0 2px gray;
  padding: 0;
  margin: 0;
  margin-left: 1%;
  margin-top: 20px;
  overflow: hidden;
  font-size: 18px;
  padding-top: 20px;
}
img {
  position: relative;
  height: 70%;
  width: 70%;
  margin: 0;
  padding: 0;
}
.p1 {
  position: relative;
  padding: 0;
}
.p2 {
  position: relative;
  padding: 0;
  margin-top: -10px;
  white-space: nowrap;
  overflow-x: hidden;
  overflow-y: hidden;
}
.price {
}
.addCart {
  border: none;
  padding: 0;
  margin: 0;
  color: red;
  background-color: transparent;
  font-size: 18px;
}
.addCart:hover,
.addCart:focus {
  color: rgb(48, 162, 233);
  text-decoration: underline;
  outline: none;
}
.test:nth-child(1) {
  margin-top: 0;
}
.test:nth-child(2) {
  margin-top: 0;
}
.test:nth-child(3) {
  margin-top: 0;
}
.test:nth-child(4) {
  margin-top: 0;
}
</style>