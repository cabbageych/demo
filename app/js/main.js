import Vue from "vue" //vue模块
import App from "./App.vue" //vue的入口文件
import router from "./router" //路由文件，用于页面管理
Vue.config.productionTip = false

//新建一个vue对象
new Vue({
    el: "#app",
    router,
    components: {
        App
    },
    template: "<app/>",
});
