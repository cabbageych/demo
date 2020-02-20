<template>
  <div id="login">
    <div id="box">
      <div style="margin:30px;">
        <span>账号:&nbsp;</span>
        <input type="text" id="account" @blur="fillPW" />
      </div>
      <div style="margin:30px;">
        <span>密码:&nbsp;</span>
        <input type="password" id="password" />
      </div>
      <label>
        <input type="checkbox" value="true" v-model="choose" />是否记住密码
      </label>
      <button @click="login">登陆</button>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      choose: ""
    };
  },
  methods: {
    print: function() {
      alert(this.choose);
    },
    login: function() {
      let name = document.getElementById("account").value;
      let pw = document.getElementById("password").value;
      if (this.choose == true) {
        document.cookie = `${name}=${pw}`;
      }
      //console.log(`${name}=${pw}`);
      alert("success!");
    },
    fillPW: function() {
      let name = document.getElementById("account").value;
      name = name.trim();
      if (name == "") {
        return;
      }
      let pw = document.getElementById("password");
      if (pw.value.trim() == "") {
        let cookie = document.cookie;
        //console.log(cookie);
        let temp = name + "=(\\w*)(;|$)";
        if (cookie.match(temp) != null) {
          let password = cookie.match(temp)[1];
          pw.value = password;
          //console.log(password);
        }
      } else {
        pw.value = "";
      }
    }
  }
};
</script>
<style>
#login {
  flex: 1;
}
#box {
  position: relative;
  height: 300px;
  width: 300px;
  margin: 0 auto;
  top: 50%;
  transform: translateY(-80%);
  box-shadow: 0 0 5px gray;
  display: flex;
  flex-direction: column;
  text-align: center;
  font-size: 18px;
  padding: 50px;
}
#box > button {
  position: relative;
  border: none;
  background: lightskyblue;
  height: 40px;
  width: 80px;
  margin: 0 auto;
  font-size: 20px;
  border-radius: 5px;
  color: white;
  margin-top: 20px;
}
#box > button:hover {
  background: rgb(5, 82, 107);
}
</style>
