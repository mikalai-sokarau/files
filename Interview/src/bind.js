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
  return (...moreArgs) => that.call(context, ...moreArgs, ...args);
};
