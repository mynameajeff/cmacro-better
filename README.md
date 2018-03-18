# cmacro-better

This is severe abuse of the preprocessor.

The goal was to take cfloat-better, and allow it to have the ability to serve not only the float type for values stored within it's array, but other types as well.

To this end, mimicking templating with the preprocessor in hindsight was a reasonable idea.

This can be disputed.

SIDENOTE: It was unintentionally also capable of working with structures, so to keep that compatibility, fa_get_sum was ommited.

All other functions from cfloat-better have now been implemented in cmacro-better, and follow the pattern: 
 - <normal-function-name\><name\>(<normal args, but types will be those of value*\>);

The exeption/s to this are:
  - ma_expanded_get_<name\>, where the _arr has been dropped in the name.

name and value are parameters passed to the macro DEFINE_BETTER_STRUCT, which is the holy macro that creates the functions and structure that you'd be using.

## DEFINE_BETTER_STRUCT(value, name);

 - value is the type, for example: and integer array would have this value as `int`, and a float array as `float`.
 - name is the name of the internal structure used in the lib, say `better_int`. it influences the names of the functions(as I have shown before), and repeating this wouldn't end well at compile time.
