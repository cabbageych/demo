import Vue from 'vue'
import Router from 'vue-router'
import login from '../components/loginWithCookie.vue'
import slideShow from '../components/slideShow.vue'
import search from '../components/search.vue'
import tab from '../components/tab.vue'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: slideShow,
      component: slideShow
    },
    {
      path: '/login',

      component: login
    },
    {
      path: '/search',

      component: search
    },
    {
      path: '/tab',
      component: tab
    }
  ]
})
