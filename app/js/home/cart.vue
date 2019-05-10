<template>
  <div>
    <div class="cart">
      <div class="content">
        <div>
          <table>
            <tr>
              <th>商品名称</th>
              <th>单价</th>
              <th>购买数量</th>
              <th>操作</th>
            </tr>
            <tr v-for="(item,index) in value">
              <td>{{item.name}}</td>
              <td style="color:red;">¥{{item.price}}</td>
              <td>
                <button @click="++item.count">+</button>
                <span style="color:blue;">{{item.count}}</span>
                <button v-if="item.count>1" @click="--item.count">-</button>
              </td>
              <td style="color:red;" @click="del(index)">删除</td>
            </tr>
          </table>
        </div>
      </div>
      <footer>
        <span>
          <label style="color:red;">总价:</label>
          {{totalShow}}
        </span>
        &nbsp;&nbsp;
        <button @click="sub()">确认下单</button>
      </footer>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      value: "",
      totalPrice: 0
    };
  },
  methods: {
    del: function(a) {
      let sure = confirm("是否删除本项目?");
      if (sure) {
        this.value.splice(a, 1);
        localStorage.setItem("cart", JSON.stringify(this.value));
        let tempCount = localStorage.getItem("cartNum");
        --tempCount;
        localStorage.setItem("cartNum", tempCount);
      }
    },
    sub: function() {
      let sure = confirm("是否确认下单?");
      if (sure) {
        //console.log(this.value);
        /*fetch("http://localhost:8080", {
          method: "POST",
          headers: {
            "Content-Type": "application/json"
          },
          body: JSON.stringify(this.value),
        }).then((response)=>{
          return response.text();
        }).then((val)=>{
          console.log(val);
        });*/
        localStorage.setItem("cart", "[]");
        this.value = "";
        localStorage.setItem("cartNum", 0);
      }
    }
  },
  mounted() {
    let temp = localStorage.getItem("cart");
    if (temp === "[]") {
      this.value = [];
    } else {
      this.value = JSON.parse(localStorage.getItem("cart"));
    }
  },
  computed: {
    totalShow: {
      get() {
        let temp = 0;
        for (let i = 0; i < this.value.length; i++) {
          temp += this.value[i].count * this.value[i].price;
        }
        this.totalPrice = temp;
        return this.totalPrice;
      },
      set() {}
    }
  }
};
</script>
<style>
.cart {
  display: flex;
  flex-direction: column;
}
.content {
  position: relative;
  width: 60%;
  background: rgb(255, 239, 224);
  align-self: center;
}
table {
  font-size: 20px;
  width: 100%;
  text-align: center;
}

footer {
  position: relative;
  height: 80px;
  background: rgb(243, 198, 180);
  text-align: center;
  border-radius: 5px;
}
footer > button {
  position: relative;
  height: 38px;
  width: 100px;
  font-size: 18px;
  border-radius: 5px;
  border: none;
}
footer > button:hover,
footer > button:active {
  background: lightblue;
  color: white;
  border: 2px solid yellow;
}
footer > span {
  position: relative;
  font-size: 18px;
  line-height: 80px;
}
</style>

