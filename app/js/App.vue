<template>
  <div id="app">
    <div id="mask">
      <hr id="centerLine">
      <div id="centerCircle"></div>
      <p id="welcome">welcome to cabbage's chatRoom!</p>
    </div>
  </div>
</template>
<script>

export default {
  data() {
    return {};
  },
  beforeMount(){
    setTimeout(()=>{
      document.getElementById('mask').style.display = 'none';
    },3000);
  }
};
</script>
<style>
  *{
    padding:0;
    margin:0;
  }
  #mask{
    position:absolute;
    width:100vw;
    height:100vh;
    background:lightblue;
    margin:0;
    padding:0;
    z-index: 1;
    text-align: center;
  }
  #centerLine{
    position:relative;
    top:35%;
    height:6px;
    background: rgb(139, 137, 137);
    border:none;
    z-index: 2;
  }
  #centerCircle{
    position:absolute;
    height:250px;
    width:250px;
    border-radius: 50%;
    border-width:5px;
    border-color: white;
    border-style: solid;
    box-shadow: 0 0 20px rgb(129, 126, 126);
    background: url('../img/huaji.jpg');
    background-size: cover;
    background-repeat: no-repeat;
    top:35%;
    left:50%;
    margin-top: -125px;
    margin-left: -125px;
    z-index: 3;
    animation: 10s circleRotate linear infinite;
  }

  @keyframes circleRotate{
    from{
      transform: rotate(0deg);
    }

    to{
      transform: rotate(360deg);
    }
  }
  #welcome{
    position:absolute;
    top:35%;
    left:50%;
    font-size: 50px;
    transform: translateX(-50%);
    margin-top: 180px;
  }
</style>