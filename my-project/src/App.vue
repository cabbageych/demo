<template>
  <div id="app">
    <header>
      <h1>Demos</h1>
    </header>
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
header {
  width: 100%;
}
header > h1 {
  position: relative;
  margin: 0 auto;
  text-align: center;
  color: rgb(14, 84, 97);
  font-size: 50px;
}
</style>
