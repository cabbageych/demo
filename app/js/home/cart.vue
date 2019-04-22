<template>
  <div>
    <div class="cart">
      <div class="content">
        <div>
          <ul>
            <li>
              <span>
                <label>商品名称</label>
                <span>1111</span>
              </span>
              <span>
                <label>价格</label>
                <span>1111</span>
              </span>
              <span>
                <label>购买数量</label>
                <button @click="++count">+</button>
                <span>{{count}}</span>
                <button @click="--count">-</button>
              </span>
            </li>
          </ul>
        </div>
      </div>
      <footer>
          <span>
              <label>总价</label>

          </span>
          <button>确认下单</button>
      </footer>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
        count:1111
    };
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
  background: lightcyan;
  align-self: center;
}
ul {
  list-style: none;
  font-size: 20px;
}
ul > li{
  display: flex;
  justify-content: space-around;
  flex-direction: row;
}
ul>li>span>span{
    color:rgb(219, 44, 44);
}




footer {
  position: relative;
  height: 80px;
  background: rgb(243, 198, 180);
  text-align: center;
  border-radius: 5px;
}
footer>button{
    position:relative;
    height:38px;
    width:100px;
    font-size: 18px;
    border-radius: 5px;
    border:none;
}
footer>button:hover,footer>button:active{
    background:lightblue;
    color:white;
    border:2px solid yellow;
}
footer>span{
    position:relative;
    font-size:18px;
    line-height: 80px;
}
</style>

