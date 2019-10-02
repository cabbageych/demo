<template>
  <div id="shoppingCart">
    <header>
      <span class="title">cabbage商城</span>
      <button class="cart" @click="mainPageShow=true">商品页</button>
      <button class="cart" id="cartShow" @click="mainPageShow=false">
        购物车
        <span style="color:blue;">{{listLen}}</span>
      </button>
    </header>
    <template v-if="mainPageShow">
      <mainPage></mainPage>
    </template>
    <template v-else>
      <list></list>
    </template>
  </div>
</template>
<script>
import shoppingCartMainPage from "./shoppingCartMainPage.vue";
import shoopingCartList from "./shoppingCartList.vue";
import shoppingCartList from "./shoppingCartList.vue";
export default {
  components: {
    mainPage: shoppingCartMainPage,
    list: shoppingCartList
  },
  data() {
    return {
      mainPageShow: true,
      tempArr: [
        { name: "cabbage01", price: "$999", count: 10 },
        { name: "cabbage02", price: "$999", count: 11 },
        { name: "cabbage03", price: "$999", count: 12 }
      ]
    };
  },
  computed: {
    listLen: function() {
      return this.$store.getters.getListLen;
    }
  },
  mounted() {}
};
</script>

<style scoped>
#shoppingCart {
  position: relative;
  width: 50vw;
  height: 800px;
  left: 50%;
  transform: translateX(-50%);
  margin-top: 30px;
}
header {
  text-align: center;
  margin-bottom: 20px;
}
.title {
  font-size: 25px;
}
.cart {
  border: none;
  background: transparent;
  font-size: 20px;
  margin-left: 100px;
  color: lightcoral;
  margin-top: 10px;
}
.cart:hover {
  text-decoration: underline;
  color: rgb(44, 142, 235);
}
.cart:focus {
  outline: none;
}
#cartInfo {
  position: absolute;
  display: block;
  margin: 0;
  border: 0;
  padding: 0;
}
.cartShow {
  list-style: none;
  padding: 10px;
}
li {
  text-decoration: underline;
}
</style>