<template>
  <div id="carContainer">
    <table>
      <tr>
        <td>商品</td>
        <td>价格</td>
        <td>数量</td>
      </tr>
      <tr v-for="item in list">
        <td>{{item.name}}</td>
        <td>{{item.price}}</td>
        <td>
          <button @click="addNum(item.name)">+</button>
          <input type="text" class="numInput" v-model="item.count" />
          <button @click="minusNum(item.name)">-</button>
        </td>
      </tr>
    </table>
    <button @click="submit" class="sub">提交</button>
  </div>
</template>

<script>
export default {
  data() {
    return {
      list: []
    };
  },
  mounted() {
    this.list = this.$store.getters.getList;
  },
  methods: {
    submit: function() {
      this.$store.dispatch("clear");
      this.list = [];
    },
    addNum: function(name) {
      this.$store.dispatch("addNums", name);
    },
    minusNum: function(name) {
      this.$store.dispatch("minusNums", name);
    }
  }
};
</script>

<style scoped>
#carContainer {
  height: 100px;
  width: 100%;
  text-align: center;
}
table {
  width: 100%;
}

td {
  text-align: center;
}
table tr:first-child {
  font-size: 20px;
  font-weight: bold;
  border: 1px solid black;
}
.sub {
  margin-top: 30px;
  border: none;
  background: transparent;
  font-size: 20px;
  background: rgb(73, 192, 231);
  border-radius: 5px;
  color: white;
}
button:focus {
  outline: none;
}
.sub:hover {
  background: rgb(3, 98, 177);
}
button {
  border-radius: 3px;
}
button:hover {
  background: rgb(153, 240, 221);
}
.numInput {
  border-radius: 3px;
  width: 40px;
  border: 1px solid gray;
  font-size: 14px;
}
</style>