<template>
  <div id="wrap">
    <h3>轮播图</h3>
    <div id="contentShow">
      <div style="position:absolute;bottom:10px;width:100%;" id="buttonWrapper">
        <button class="choose" v-for="item in choose" @click="changePic($event,item)"></button>
      </div>
      <div id="content">
        <img v-for="item in imageAddr" :src="item" />
      </div>
    </div>
  </div>
</template>

<script>
import url01 from "../assets/slideShow01.jpg";
import url02 from "../assets/slideShow02.jpg";
import url03 from "../assets/slideShow03.jpg";
import url04 from "../assets/slideShow04.jpg";
import url05 from "../assets/slideShow05.jpg";
export default {
  data() {
    return {
      imageAddr: [url01, url02, url03, url04, url01],
      choose: [0, 1, 2, 3],
      pic: 0,
      timeGap: 2000,
      timer:''
    };
  },
  methods: {
    changePic: function(e, num) {
      let buttons = [];
      buttons = document.getElementsByClassName("choose");
      for (let i = 0; i < buttons.length; i++) {
        buttons[i].style.background = "white";
      }
      let el = e.target;
      el.style.background = "red";
      let content = document.getElementById("content");
      content.style.transform = "translate(" + -800 * num + "px)";
      this.pic = num;
    },
    slideShow: function() {
      if (this.pic > 4) {
        this.pic = 0;
      }
      if (this.pic == 0 || this.pic == 5) {
        this.timeGap = 1000;
      } else {
        this.timeGap = 2000;
      }
      let buttons = document.getElementsByClassName("choose");
      for (let i = 0; i < buttons.length; i++) {
        buttons[i].style.background = "white";
      }
      if (this.pic == 4) {
        buttons[0].style.background = "red";
      } else {
        buttons[this.pic].style.background = "red";
      }
      let content = document.getElementById("content");
      if (this.pic == 0) {
        content.style.transition = "0s";
      } else {
        content.style.transition = "1s";
      }
      content.style.transform = "translate(" + -800 * this.pic + "px)";
      ++this.pic;
    }
  },
  mounted() {
    let buttons = document.getElementsByClassName("choose");
    buttons[0].style.background = "red";
    this.timer = setInterval(this.slideShow, this.timeGap);
  },
  destroyed(){
    clearInterval(this.timer);
    //console.log('destroyed');
  }
};
</script>
<style>
#wrap {
  position: relative;
  text-align: center;
}
#contentShow {
  position: relative;
  width: 800px;
  height: 400px;
  box-shadow: 0 0 5px gray;
  margin: 0 auto;
  background: url(../assets/slideShow01.jpg);
  background-size: cover;
  overflow: hidden;
}
.choose {
  position: relative;
  height: 13px;
  width: 13px;
  border: none;
  margin-left: 10px;
  padding: 0;
  border-radius: 50%;
  z-index: 1;
}
.choose:hover {
  background: rgb(3, 163, 163);
  box-shadow: 0 0 3px yellow;
}
.choose:focus {
  outline: none;
}
#content {
  position: relative;
  height: 400px;
  width: 4000px;
  transition: 1s;
}
img {
  height: 400px;
  width: 800px;
  float: left;
}
</style>
