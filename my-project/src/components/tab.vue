<template>
  <div id="tabContainer">
    <input type="radio" class="pages" name="page" id="page1" checked />
    <input type="radio" class="pages" name="page" id="page2" />
    <input type="radio" class="pages" name="page" id="page3" />
    <p>
      <label for="page1" id="label1">分页一</label>
      <label for="page2" id="label2">分页二</label>
      <label for="page3" id="label3">分页三</label>
    </p>
    <div class="tabBody" id="body1">{{content1}}</div>
    <div class="tabBody" id="body2">{{content2}}</div>
    <div class="tabBody" id="body3">{{content3}}</div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      content1: "分页一内容：content01",
      content2: "分页二内容：content02",
      content3: "分页三内容：content03"
    };
  }
};
</script>

<style scoped>
* {
  background: transparent;
  border: none;
  margin: 0;
  padding: 0;
  font-size: 18px;
}
input {
  display: none;
}
p {
  position: relative;
  height: 35px;
  width: 100%;
  background: lightslategray;
  line-height: 35px;
}
label {
  position: relative;
  height: 35px;
  border: 1px solid transparent;
  background: lightblue;
  border-radius: 5px;
}
label:focus {
  outline: none;
}
label:hover {
  background: white;
  border: 1px solid gray;
}
#tabContainer {
  position: relative;
  height: 500px;
  width: 600px;
  margin-top: 50px;
  left: 50%;
  transform: translateX(-50%);
  border: 1px solid gray;
  border-radius: 5px;
}

.tabBody {
  position: relative;
  height: 100%;
  width: 100%;
  display: none;
  text-indent: 2em;
}
#page1:checked ~ #body1,
#page2:checked ~ #body2,
#page3:checked ~ #body3 {
  display: block;
}
#page1:checked ~ p > #label1,
#page2:checked ~ p > #label2,
#page3:checked ~ p > #label3 {
  background: white;
}
</style>