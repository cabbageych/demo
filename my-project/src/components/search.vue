<template>
  <div id="searchWrap">
    <ul id="searchUl">
      <li id="firstLine">
        <input type="text" id="search" @input="showList" />
        <button @click="send" id="sendBtn">search</button>
      </li>
      <div id="list"></div>
    </ul>
  </div>
</template>

<script>
export default {
  data() {
    return {};
  },
  mounted() {
    window["del"] = function(e) {
      e.stopPropagation();
      let list = document.getElementById("list");
      //console.log(e.target.parentNode);
      list.removeChild(e.target.parentNode);
    };
    window["search"] = function(e) {
      let content = e.target.innerText;
      let searchInput = document.getElementById("search");
      searchInput.value = content.substr(0, content.length - 6);
      let send = document.getElementById("sendBtn");
      send.click();
      //Promise.resolve().then(() => {});
    };
    window["callback"] = function(str) {
      let list = document.getElementById("list");
      list.innerHTML = "";
      let arr = str.s;
      for (let i = 0; i < arr.length; i++) {
        let li = document.createElement("li");
        li.innerText = arr[i];
        let btn = document.createElement("button");
        btn.innerText = "delete";
        btn.onclick = del;
        li.append(btn);
        li.onclick = window.search;
        list.append(li);
      }
    };
  },
  methods: {
    showList: function() {
      let id = document.getElementById("search");
      let val = id.value.trim();
      let script = document.createElement("script");
      script.src =
        "https://sp0.baidu.com/5a1Fazu8AA54nxGko9WTAnF6hhy/su?wd=" +
        val +
        "&cb=callback";
      document.body.appendChild(script);
      //cb();
    },
    send: function() {
      let searchInput = document.getElementById("search");
      let str = searchInput.value;
      alert("search: " + str);
    }
  }
};
</script>

<style>
ul {
  list-style: none;
}
#searchWrap {
  position: relative;
  margin: 0 auto;
  margin-top: 100px;
}
#searchWrap * {
  margin: 0;
  padding: 0;
}
li button {
  font-size: 16px;
  padding: 0;
  border: 0;
  float: right;
  box-shadow: 0 0 1px gray;
  border-radius: 3px;
  transform: translateY(2px);
}
li button:hover {
  background: lightcoral;
}
#sendBtn {
  font-size: 18px;
  background: transparent;
  border-radius: 5px;
  height: 40px;
  border: 1px solid gray;
  background: lightblue;
}

#sendBtn:hover {
  color: white;
  background: rgb(12, 167, 219) !important;
}
#sendBtn:focus {
  outline: none;
}

#search {
  height: 40px;
  width: 250px;
  font-size: 18px;
  border-radius: 10px;
  border: 1px solid gray;
}
#search:focus {
  outline: none;
}

#list li {
  border-radius: 5px;
}

#list li:hover {
  background: lightblue;
}
</style>