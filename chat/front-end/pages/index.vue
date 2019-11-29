<template>
  <v-layout
    column
    justify-center
    align-center
    wrap
  >
    <v-container>
      <v-col cols="12">
        <v-card
          class="my-3 mx-auto"
          max-width="344"
          v-for="(item, index) in $store.state.texts"
          :key="index"
        >
          <v-card-title>{{item.user}}</v-card-title>
          <v-card-text>{{item.message}}</v-card-text>
        </v-card>
      </v-col>
      <v-col cols="12">
        <v-text-field
          v-model="form.user"
          label="Name"
        ></v-text-field>
      </v-col>
      <v-col cols="12">
        <v-textarea v-model="form.message">
          <template v-slot:label>
            <div>
              Text
            </div>
          </template>
        </v-textarea>
      </v-col>
      <v-btn color="primary" block @click="sendMessage">Send</v-btn>
    </v-container>
  </v-layout>
</template>

<script>

export default {
  data(){
    return {
      form: {
        user: "",
        message: ""
      }
    }
  },
  sockets: {
    connect: function(){
      console.log("Connected!!!")
    },
  },
  methods: {
    sendMessage(){
      this.$socket.emit("newmessage", this.form);
    }
  }
}
</script>
