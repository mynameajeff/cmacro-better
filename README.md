# cmacro-better

This is severe abuse of the preprocessor.

The goal was to take cfloat-better, and allow it to have the ability to serve not only the float type for values stored within it's array, but other types as well.

To this end, mimicking templating with the preprocessor in hindsight was a reasonable idea.

This can be disputed.

SIDENOTE: It was unintentionally also capable of working with structures, so to keep that compatibility, fa_get_sum was ommited.
