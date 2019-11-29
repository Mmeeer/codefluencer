import Vue from 'vue'
import VueSocketIO from 'vue-socket.io'

export default function({store}){
  Vue.use(new VueSocketIO({
    debug: true,
    connection: 'http://localhost:8000/',
    vuex: {
        store,
        actionPrefix: 'SOCKET_',
        mutationPrefix: 'SOCKET_'
    },
  }))
}
