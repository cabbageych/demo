<template>
  <div id="contentBody">
    <div v-for="item in goods" class="template">
      <div>
        <img :src="picUrl" />
      </div>
      <p>商品：{{item.name}}&nbsp;&nbsp;&nbsp;&nbsp;价格：{{item.price}}</p>
      <button class="addToCart" @click="addToCart($event,item)">添加购物车</button>
    </div>
  </div>
</template>

<script>
import huaji from "../assets/huaji.jpg";
export default {
  data() {
    return {
      goods: [
        { name: "01", price: "$999" },
        { name: "02", price: "$999" },
        { name: "03", price: "$999" },
        { name: "04", price: "$999" },
        { name: "05", price: "$999" },
        { name: "06", price: "$999" }
      ],
      picUrl: huaji
    };
  },
  methods: {
    addToCart: function(e, item) {
      let x = e.pageX;
      let y = e.pageY;
      let tip = document.createElement("p");
      tip.innerHTML = "添加购物车成功!";
      tip.style.position = "absolute";
      tip.style.left = x + "px";
      tip.style.top = y + "px";
      tip.style.color = "green";
      tip.id = "addTip";
      document.body.append(tip);
      this.$store.dispatch("addToCart", item.name, item.price, 1);
      setTimeout(() => {
        let tip = document.getElementById("addTip");
        document.body.removeChild(tip);
      }, 800);
    }
  }
};
</script>

<style scoped>
#contentBody {
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
  justify-content: center;
}
.template {
  display: flex;
  flex-direction: column;
  position: relative;
  width: 250px;
  margin: 10px;
  padding: 10px;
  box-shadow: 0 0 3px gray;
  align-items: center;
}
img {
  height: 150px;
  width: 150px;
}
.addToCart {
  border: none;
  background: rgb(3, 79, 102);
  font-size: 16px;
  border-radius: 5px;
  color: white;
}
.addToCart:focus {
  outline: none;
}
.addToCart:hover {
  background: rgb(112, 207, 236);
}
</style>