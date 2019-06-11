<template>
  <div id="app">
    <header>
      <div class="name">
        <transition name="title">
          <span class="head" v-if="show">
            <strong v-if="show01" style="color:red;">I</strong>
            <strong v-if="show02" style="color:blue;">W</strong>
            <strong v-if="show03" style="color:orange;">A</strong>
            <strong v-if="show04" style="color:green;">N</strong>
            <strong v-if="show05">N</strong>
            <strong v-if="show06" style="color:purple;">A</strong>
          </span>
        </transition>
        <span class="tail">商城</span>
      </div>
      <div id="headerBottom">
        <a class="a1" href="./login.html">商家入口</a>
        <button class="a2" @click="toCart()">
          我的购物车&nbsp;&nbsp;
          <strong id="showCartNum">{{childValue}}</strong>
        </button>
        <button class="a3" @click="toMainPage()">主页</button>
      </div>
    </header>
    <myBody v-on:showTypeAll="showAll" v-on:cart="addToCart" v-if="childShow"></myBody>
    <cart :cart="cart" v-on:deleteItem="delCart" v-on:clearCart="clearCart" v-else></cart>
  </div>
</template>
<script>
import myBody from "./home/myBody.vue";
import cart from "./home/cart.vue";
export default {
  components: {
    myBody,
    cart
  },
  data() {
    return {
      childShow: true,
      count: 0,
      show: true,
      title: ["I", "W", "A", "N", "N", "A"],
      show01: false,
      show02: false,
      show03: false,
      show04: false,
      show05: false,
      show06: false,
      childValue: 0,
      cart: []
    };
  },
  methods: {
    changeShow: function() {
      ++this.count;
      if (this.count === 7) {
        //this.show = !this.show;
        this.count = 0;
      } else if (this.count == 1) {
        this.show01 = !this.show01;
      } else if (this.count == 2) {
        this.show02 = !this.show02;
      } else if (this.count == 3) {
        this.show03 = !this.show03;
      } else if (this.count == 4) {
        this.show04 = !this.show04;
      } else if (this.count == 5) {
        this.show05 = !this.show05;
      } else if (this.count == 6) {
        this.show06 = !this.show06;
      }
    },
    showAll:function(temp,result){
      temp = result;
    },
    clearCart: function() {
      this.cart = [];
      this.childValue = 0;
    },
    delCart: function(val) {
      this.childValue = this.cart.length;
    },
    addToCart: function(cartTemp) {
      let flag = false;
      for (let i = 0; i < this.cart.length; i++) {
        if (this.cart[i].id == cartTemp.id) {
          flag = true;
          this.cart[i].count = this.cart[i].count + 1;
          break;
        }
      }
      if (!flag) {
        this.cart.push(cartTemp);
      }
      this.childValue = this.cart.length;
    },
    toCart: function() {
      if (this.childShow == true) {
        this.childShow = false;
      }
    },
    toMainPage: function() {
      if (this.childShow == false) {
        this.childShow = true;
      }
    }
  },
  mounted() {
    setInterval(this.changeShow, 600);
  },
  computed: {}
};
</script>
<style>
html,body{
  margin:0;
  padding:0;
}
body::-webkit-scrollbar { width: 0 !important }
div,
span,
strong,
p {
  cursor: default;
}
#app {
  display: flex;
  display: -webkit-flex;
  flex-direction: column;
}
header {
  background: whitesmoke;
  height: 90px;
  position: relative;
  overflow-x: auto;
}
.name {
  text-align: center;
  font-size: 3rem;
  line-height: 60px;
}
.a1 {
  margin-right: 30px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  overflow: auto;
}
.a2 {
  margin-right: 30px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  border: none;
  background: transparent;
  padding: 0;
}
.a3 {
  margin-right: 100px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  border: none;
  background: transparent;
  padding: 0;
}
header {
  display: flex;
  flex-direction: column;
  align-content: center;
  align-items: center;
  justify-content: center;
}
#headerBottom{
  display: flex;
  width:100%;
  flex-direction: row;
  justify-content: flex-end;
}
#showCartNum {
  color: black;
  text-indent: 2em;
}

header button:focus {
  outline: none;
}
header button:hover {
  color: lightblue;
  text-decoration: underline;
}

header > a:hover,
header > a:hover:active {
  color: lightblue;
  text-decoration: underline;
}
.head {
  position: relative;
  height:60px;
  font-size: 55px;
}
.tail {
  margin-left: 20px;
}
/*
.title-enter-active,
.title-leave-active {
  transition: all 2s;
}
.title-enter {
  opacity: 0;
  transform: translateY(-30px);
}
.title-leave-to {
  opacity: 0;
  transform: translateY(30px);
}*/
</style>