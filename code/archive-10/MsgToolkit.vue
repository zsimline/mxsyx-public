<template>
  <div>
    <MsgInput v-model="msg"/>
  </div>
</template>

<script>
import MsgInput from "/MsgInput.vue";

export default {
  name: "MsgToolkit",
  data: function() {
    return {
      msg: ''
    }
  },

  components: {
    MsgInput
  },
}
</script>