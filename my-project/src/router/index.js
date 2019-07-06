import Vue from 'vue'
import Router from 'vue-router'
import login from '../components/loginWithCookie.vue'
import slideShow from '../components/slideShow.vue'


Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: slideShow,
      component: slideShow
    }
  ]
})
