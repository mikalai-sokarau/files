function Parent() {}
Parent.prototype.move = function() {
  console.log("I'm moving");
};
Parent.prototype.constructor = function() {
  console.log('here');
  return new Parent();
};
export default Parent;
