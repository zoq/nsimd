/*

Copyright (c) 2019 Agenium Scale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef NSIMD_MODULES_FIXED_POINT_FUNCTION_BIT_PRINTER_HPP
#define NSIMD_MODULES_FIXED_POINT_FUNCTION_BIT_PRINTER_HPP

#include <iostream>

namespace nsimd
{
namespace fixed_point
{
template <typename T>
void print_bits(const T &in)
{
  uint64_t two = 1;
  uint64_t ref = *((uint64_t *) (&in));
  for(unsigned int i = 0; i < 8 * sizeof(T); ++i)
  {
    std::cout << int((two & ref) / two);
    two *= 2;
    if((i % 4) == 3)
      std::cout << " ";
  }
  std::cout << "\n";

  return;
}

} // namespace fixed_point
} // namespace nsimd

#endif
