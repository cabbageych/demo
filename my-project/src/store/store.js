import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex);

const store = new Vuex.Store({
    state: {
        list: []
    },
    getters: {
        getListLen: function (state) {
            return state.list.length;
        },
        getList: function (state) {
            return state.list;
        },
        getNum: function (state, name) {
            let arr = state.list;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i].name == name) {
                    return arr[i].count;
                }
            }
        }
    },
    mutations: {
        addToCart: function (state, obj) {
            let arr = state.list;
            let flag = true;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i].name == obj.na) {
                    arr[i].count += obj.co;
                    flag = false;
                }
            }
            if (flag) {
                let tempObj = {
                    name: obj.na,
                    price: obj.pr,
                    count: obj.co
                }
                state.list.push(tempObj);
            }
        },
        rmFromCart: function (state, name) {
            let arr = state.list;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i].name == name) {
                    arr.splice(i, 1);
                    break;
                }
            }
        },
        addNums: function (state, name) {
            let arr = state.list;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i].name == name) {
                    ++arr[i].count;
                }
            }
        },
        minusNums: function (state, name) {
            let arr = state.list;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i].name == name) {
                    --arr[i].count;
                }
            }
        },
        clear: function (state) {
            state.list = [];
        }
    },
    actions: {
        addToCart: function ({ commit }, name, price, count) {
            commit('addToCart', name, price, count);
        },
        rmFromCart: function ({ commit }, name) {
            commit('rmFromCart', name);
        },
        addNums: function ({ commit }, name) {
            commit('addNums', name);
        },
        minusNums: function ({ commit }, name) {
            commit('minusNums', name);
        },
        clear: function ({ commit }) {
            commit('clear');
        }
    }
});

export default store;