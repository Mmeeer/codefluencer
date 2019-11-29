export const state = () =>({
  texts: []
})

export const actions = {
  SOCKET_newmessage({commit}, data){
    commit('saveData',data);
  }
}
export const mutations = {
  saveData(state, data){
    console.log(state);
    state.texts.push(data);
  }
}
