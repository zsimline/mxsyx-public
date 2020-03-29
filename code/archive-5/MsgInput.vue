<template>
    <div
      class="msg-input"
      contenteditable="true"
      @input="changeText"
    >{{ innerText }}</div>
</template>

<script>
export default{
  name: "MsgInput",
  props: ['value'],
  
  data: function() {
    return {
      innerText: this.value,
    }
  },
  
  methods: {
    changeText() {
      this.$emit('input', this.$el.innerText);
    }
  }
}
</script>

<style scoped>
.msg-input {
  width: 500px;
  font-size: 14px;
  line-height: 16px;
  border: solid 1px #999;
}
.msg-input:empty::before {
  content: "输入消息...";
  color: #999999;
}
.msg-input:focus::before {
  content: none;
}
</style>