Function.prototype.bind = function(context) {
  const fn = this;
  const args = Array.prototype.slice.call(arguments, 1);

  return function() {
    const moreArgs = Array.prototype.slice.call(arguments);

    return fn.apply(context, args.concat(moreArgs));
  };
};

Function.prototype.bind = function(context, ...args) {
  const that = this;
  return (...moreArgs) => that.call(context, ...args, ...moreArgs);
};

sum(1)(2)(3);

const sum = a => {
  const plus = b => sum(a + b);
  plus.valueOf = () => a;
  return plus;
};

function addOne(a) {
  return a + 1;
}
function square(x) {
  return x * 2;
}

// square.pipe = function(fn) {
//   const self = this;
//   return num => fn(self(num));
// };

[1, 2, 4].map(square.pipe(addOne)); //[3, 5, 9]
//implement function pipe()
