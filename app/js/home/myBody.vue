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
        <div class="test">
          <img src="../../img/huaji.jpg">
          <p class="p1"><label>商品名:</label>薛定谔的滑稽</p>
          <p class="p2"><label class="price">价格:</label>$999&nbsp;&nbsp;<label class="cart">加入购物车</label></p>
        </div>
        <div class="test"></div>
        <div class="test"></div>
        <div class="test"></div>
        <div class="test"></div>
        <div class="test"></div>
      </div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      showlist01: false,
      showlist02: false,
      showlist03: false,
      showlist04: false
    };
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
  position:relative;
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
  margin-left: 1%;
}
img{
  position:absolute;
  height:70%;
  width:70%;
  top:0;
  left:15%;
}
.p1{
  position:absolute;
  top:71%;
  left:50%;
  transform: translateX(-50%);
}
.p2{
  position:absolute;
  top:71%;
  left:50%;
  transform: translate(-50%,110%);
  
}
.price{
  position:inherit;
}
.cart{
  position:inherit;
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