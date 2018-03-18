# cmacro-better

This is severe abuse of the preprocessor.

The goal was to take cfloat-better(another project of mine), and allow it to have the ability to serve not only the float type for values stored within it's array, but other types as well.

To this end, mimicking templating with the preprocessor in hindsight was a reasonable idea.

This can be disputed.

SIDENOTE: It was unintentionally also capable of working with structures, so to keep that compatibility, fa_get_sum was ommited.

All other functions from cfloat-better have now been implemented in cmacro-better, and follow the pattern: 
 - <normal-function-name\>_<name\>(<normal args, but types will be those of value*\>);

There is an anomaly in this pattern, where if the function name would end with "_arr", it is omitted here.

name and value are parameters passed to the macro MA_DEFINE_BETTER_STRUCT, which is the holy macro that creates the functions and structure that you'd be using.

## MA_DEFINE_BETTER_STRUCT(value, name);

 - value is the type, for example: an integer array would have this value as `int`, and a float array as `float`.
 - name is the name of the internal structure used in the lib, say `better_int`. it influences the names of the functions(as I have shown before), and repeating this wouldn't end well at compile time.

END NOTE/S:
  The supplied makefile compiles the general.c example, but due to the extreme simplicity of the makefile, modification to allow compilation of the other supplied examples would be rather easy.
