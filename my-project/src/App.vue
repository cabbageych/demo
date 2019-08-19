<template>
  <div id="app">
    <div class="header">
      <h1>Demos</h1>
      <router-link to='/login'>login</router-link>
      <router-link to='/'>轮播图</router-link>
      <router-link to='/search'>智能提示搜索</router-link>
    </div>
    <router-view/>
  </div>
</template>

<script>
export default {
  name: "App"
};
</script>

<style>
#app {
  display: flex;
  flex-direction: column;
  width: 100vw;
  height: 100vh;
}
.header {
  width: 100%;
  text-align: center;
}
header > h1 {
  position: relative;
  margin: 0 auto;
  text-align: center;
  color: rgb(14, 84, 97);
  font-size: 50px;
}
</style>
