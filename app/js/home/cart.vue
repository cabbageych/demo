<template>
  <div>
    <div class="cart">
      <div class="content">
        <div>
          <table style="border-collapse: collapse;">
            <tr>
              <th>商品名称</th>
              <th>单价</th>
              <th>购买数量</th>
              <th>操作</th>
            </tr>
            <tr style="position:relative;border:25px solid transparent;" v-for="(item,index) in value">
              <td>{{item.name}}</td>
              <td style="color:red;">¥{{item.price}}</td>
              <td>
                <button v-if="item.count>1" @click="--item.count">-</button>
                <input
                  style="box-shadow:0 0 3px gray;height:25px;border:none;font-size:18px;width:40px;border-radius:5px;"
                  type="text"
                  :value="item.count"
                  @change="countChange($event,item)"
                >
                <button @click="++item.count">+</button>
              </td>
              <td style="color:red;" @click="del(index)">删除</td>
            </tr>
          </table>
        </div>
      </div>
      <footer>
        <span>
          <label style="color:red;">总价:</label>
          ¥{{totalShow}}
        </span>
        &nbsp;&nbsp;
        <button @click="sub()">确认下单</button>
      </footer>
    </div>
  </div>
</template>
<script>
export default {
  props: ["cart"],
  data() {
    return {
      value: "",
      totalPrice: 0
    };
  },
  methods: {
    countChange: function(e, item) {
      item.count = e.target.value;
      //console.log(item.count);
    },
    del: function(a) {
      let sure = confirm("是否删除本项目?");
      if (sure) {
        this.value.splice(a, 1);
        //console.log(a);
        this.$emit("deleteItem", a);
      }
    },
    sub: function() {
      let sure = confirm("是否确认下单?");
      if (sure) {
        if (this.value.length == 0) {
          alert("您还没有添加购物车!");
        } else {
          //console.log(this.value);
          fetch("http://www.huajiyang.com:8082", {
            method: "POST",
            headers: {
              "Content-Type": "application/json"
            },
            body: JSON.stringify(this.value)
          })
            .then(response => {
              return response.text();
            })
            .then(val => {
              //console.log(val);
              val = val.toString().trim();
              if (val == "failed") {
                alert("订单中的商品库存不足，请重新选择!");
              } else {
                alert("下单成功!");
              }
            });
          this.value = "";
          this.$emit("clearCart");
        }
      }
    }
  },
  mounted() {
    //console.log('cart:');
    //console.log(this.cart);
    this.value = this.cart;
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
      set() {
        
      }
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

  align-self: center;
}
table {
  position:relative;
  font-size: 20px;
  width: 100%;
  text-align: center;
}

footer {
  margin-top: 50px;
  position: relative;
  height: 80px;
  box-shadow: 0 0 2px gray;
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
  background: rgb(78, 107, 236);
  color: white;
}
footer > button:hover,
footer > button:active {
  background: rgb(40, 26, 226);
}
footer > span {
  position: relative;
  font-size: 18px;
  line-height: 80px;
}
</style>

