<template>
  <div id="app">
    <header>
      <div class="name">
        <transition name="title">
          <span class="head" v-if="show">
            <strong v-if="show01" style="color:red;">I</strong>
            <strong v-if="show02" style="color:lightblue;">W</strong>
            <strong v-if="show03" style="color:yellow;">A</strong>
            <strong v-if="show04" style="color:pink;">N</strong>
            <strong v-if="show05">N</strong>
            <strong v-if="show06" style="color:purple;">A</strong>
          </span>
        </transition>
        <span class="tail">网上商城</span>
      </div>
      <a class="a1" href="#">商家入口</a>
      <button class="a2" @click="toCart()">
        我的购物车&nbsp;&nbsp;
        <strong id="showCartNum">{{childValue}}</strong>
      </button>
      <button class="a3" @click="toMainPage()">主页</button>
    </header>
    <myBody v-on:cartNum="showChildValue" v-if="childShow"></myBody>
    <cart v-else></cart>
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
      childValue: 0
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
    showChildValue: function(val) {
      this.childValue = val;
    },
    toCart: function() {
      if (this.childShow == true) {
        this.childShow = false;
        localStorage.setItem("cartNum", this.childValue);
      }
    },
    toMainPage: function() {
      if (this.childShow == false) {
        this.childShow = true;
        let tempCount = localStorage.getItem("cartNum");
        if (tempCount != this.childValue) {
          this.childValue = tempCount;
        }
      }
    }
  },
  mounted() {
    setInterval(this.changeShow, 600);
    localStorage.setItem("cart", "[]");
  },
  computed: {
    
  }
};
</script>
<style>
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
  background: lightyellow;
}
header {
  background: whitesmoke;
  height: 120px;
  position: relative;
  overflow-x: auto;
}
.name {
  text-align: center;
  font-size: 3rem;
  line-height: 120px;
}
.a1 {
  position: absolute;
  left: 50%;
  bottom: 35px;
  margin-left: 220px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  overflow: auto;
}
.a2 {
  position: absolute;
  left: 50%;
  bottom: 35px;
  margin-left: 330px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  border: none;
  background: transparent;
  padding: 0;
}
.a3 {
  position: absolute;
  left: 50%;
  bottom: 35px;
  margin-left: 480px;
  font-size: 20px;
  text-decoration: none;
  color: lightcoral;
  border: none;
  background: transparent;
  padding: 0;
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
  position: absolute;
  left: 50%;
  margin-left: -280px;
}
.tail {
  position: absolute;
  left: 50%;
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