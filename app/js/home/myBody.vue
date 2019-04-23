<template>
  <div>
    <div class="myBody">
      <nav>
        <div style="color:rgb(224, 85, 20);">商品列表</div>
        <div @click="showlist01 = !showlist01">服饰</div>
        <p v-if="showlist01">服饰</p>
        <div @click="showlist02 = !showlist02">电子数码</div>
        <p v-if="showlist02">手机、电脑</p>
        <p v-if="showlist02">其他</p>
        <div @click="showlist03 = !showlist03">食品</div>
        <p v-if="showlist03">零食、生鲜</p>
        <p v-if="showlist03">干货</p>
        <div @click="showlist04 = !showlist04">文体办公</div>
        <p v-if="showlist04">体育用品</p>
        <p v-if="showlist04">办公用品</p>
      </nav>
      <div class="mainPart">
        <div class="test" v-for="(item,key,index) in results">
          <img :src="item.src">
          <p class="p1">{{item.name}}</p>
          <p class="p2">
            <label>价格:</label>
            ¥{{item.price}}
            <label @click="addToCart(key)"  class="addCart">加入购物车</label>
          </p>
        </div>
      </div>
    </div>
  </div>
</template>
<script>
import url from "../../img/huaji.jpg";
import global from "./global.vue";
export default {
  data() {
    return {
      results: [
        {
          id: 111,
          name: "薛定谔的滑稽",
          price: 999,
          src: url
        },
        {
          id: 222,
          name: "薛定谔的滑稽02",
          price: 999,
          src: url
        },
        {
          id: 333,
          name: "薛定谔的滑稽03",
          price: 999,
          src: url
        },
        {
          id: 444,
          name: "薛定谔的滑稽04",
          price: 999,
          src: url
        },
        {
          id: 555,
          name: "薛定谔的滑稽05",
          price: 999,
          src: url
        },
        {
          id: 666,
          name: "薛定谔的滑稽06",
          price: 999,
          src: url
        }
      ],
      showlist01: false,
      showlist02: false,
      showlist03: false,
      showlist04: false,
      cart: []
    };
  },
  methods: {
    addToCart: function(num) {
      this.cart = JSON.parse(localStorage.getItem("cart"));
      this.cart.push({
        id: this.results[num].id,
        name: this.results[num].name,
        price: this.results[num].price,
        count: 1
      });
      localStorage.setItem("cart", JSON.stringify(this.cart));
    }
  }
};
</script>
<style>
.myBody {
  display: flex;
  flex: 1;
}

nav {
  text-align: center;
  width: 12%;
  height: 1000px;
  background: rgb(205, 243, 243);
  font-size: 23px;
  white-space: nowrap;
}
nav div:not(:first-child) {
  border: 2px solid yellow;
  background: lightgrey;
}

nav div:not(:first-child):active,
nav div:not(:first-child):hover {
  color: white;
  background: rgb(32, 32, 16);
}
nav p {
  position: relative;
  background: white;
  margin: 0;
  padding: 0;
  color: rgb(236, 133, 236);
}
nav p:hover,
nav p:active {
  color: rgb(42, 114, 209);
  text-decoration: underline;
}

.mainPart {
  width: 88%;
  position: relative;
  background: rgb(212, 225, 228);
  flex-direction: row;
}
.test {
  position: relative;
  height: 20vw;
  width: 20vw;
  background: rgb(229, 235, 202);
  display: inline-block;
  padding: 0;
  margin: 0;
  margin-top: 10px;
  margin-left: 1%;
  overflow: hidden;
}
img {
  position: absolute;
  height: 70%;
  width: 70%;
  top: 0;
  left: 15%;
  margin: 0;
  padding: 0;
}
.p1 {
  position: absolute;
  top: 70%;
  left: 50%;
  transform: translate(-50%, 50%);
  margin: 0;
  padding: 0;
}
.p2 {
  position: absolute;
  top: 70%;
  left: 50%;
  transform: translate(-50%, 200%);
  margin: 0;
  padding: 0;
  word-break: unset;
}
.price {
  display: inline-block;
}
.addCart {
  display: inline-block;
  color:red;
}
.addCart:hover,.addCart:active{
  color:rgb(48, 162, 233);
  text-decoration: underline;
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