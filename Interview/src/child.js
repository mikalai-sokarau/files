import Parent from './parent';

function Child() {
  Parent.apply(this, arguments);
}
Child.prototype = Object.create(Parent.prototype);
Child.prototype.constructor = function() {
  console.log('here');
  return new Child();
};

Child.prototype.walk = function() {
  Child.prototype.move.apply(this, arguments);
  console.log("I'm walking");
};

export default Child;
