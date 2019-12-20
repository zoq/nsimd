NSIMD fixed-point module
========================

Description
----------

This module implements a fixed-point numbers support for the NSIMD library.
Fixed-point numbers are integer types used to represent decimal numbers. A number `lf` 
of bits are used to encode its integer part, and `rt` bits are used to encode its 
fractional part.

The fixed_point module uses the templated type `nsimd::fixed_point::fp_t<lf, rt>` to 
represent a fixed_point number. All the basic floating-point arithmetic operaors have 
been defined, therefore fp\_t elements can be manipulated as normal numbers.
The fixed\_point module will use a `int8_t`, `int16_t`, or `int32_t` integer type for 
storage, depending on the value of `lf + 2 * rt`. 

All the functions of the module are under the namespace `nsimd::fixed_point`, 
and match the same interface than NSIMD.

The `fp_t` struct type is defined in `fixed.hpp`, and the associated simd `fpsimd_t` 
struct type is defined in `simd.hpp`.

The modules redefines the NSIMD pack type for fixed-point numbers, templated with `lf` 
and `rt` :

```C++
template <uint8_t lf, uint8_t rt>
struct pack;
```

Then, the pack can be manipulated as an NSIMD pack like other scalar types. Here is 
a minimal example :

```C++
// Assumes that NSIMD is in your include path
#include <iostream>
#include <nsimd/modules/fixed_point.hpp>

int main() {
  typedef nsimd::fixed_point::fp_t<8, 8> fp_t;
  typedef nsimd::fixed_point::pack<fp_t> vec_t;
  
  fp_t *input0;
  fp_t *input1;
  fp_t *res;
  
  // Input and output initializations 
  // We assume that a function float rand_float(); has been 
  // previously defined
  for(size_t i = 0; i < nsimd::fixed_point::len(fp_t()); i++) {
    input0 = fp_t(rand_float());
    input1 = fp_t(rand_float());
  }
  
  vec_t v0 = nsimd::fixed_point::loadu<vec_t>(input0);
  vec_t v1 = nsimd::fixed_point::loadu<vec_t>(input1);
  vec_t vres = nsimd::fixed_point::add(input0, input1);
  nsimd::fixed_point::storeu(res, vres);
  
  for(size_t i = 0; i < nsimd::fixed_point::len(fp_t()); i++) {
    std::cout << float(res[i]) << " ";
  }
  std::cout << std::endl;
  
  return EXIT_SUCCESS;
}

```

Supported operators
===================

The following nsimd operators are currently implemented, they have the same interface
than the regular NSIMD library.

Load / store
------------

- `loadu/a`
- `loadlu/a`
- `storeu/a`
- `storelu/a`
- `set1`

Arithmetic operators
--------------------

- `add`
- `sub`
- `mul`
- `div`
- `fma`
- `min`
- `max`

Comparisons
-----------

- `eq`
- `ne`
- `le`
- `lt`
- `ge`
- `gt`

Conditionals
------------

- `if_else1`

Bitwise operators
-----------------

- `andb/l`
- `andnotb/l`
- `notb/l`
- `orb/l`
- `xorb/l`

Mathematic functions
--------------------

- `rec`