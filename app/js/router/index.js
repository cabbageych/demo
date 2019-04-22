import Vue from 'vue'
import Router from 'vue-router' //导入路由模块
import VueRouter from 'vue-router'
import myBody from '../home/myBody.vue'
import cart from '../home/cart.vue'


//使用路由
Vue.use(Router)
//新建路由




export default new Router({
    routes: [
        {
            path:'/',
            name:"myBody",
            component:myBody
        },
        {
            path:'/cart',
            name:"cart",
            component:cart
        },
        {
            path:'/myBody',
            name:"myBody",
            component:myBody
        },
    ]
})