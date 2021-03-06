# stretch-h

A bare-bones stretchy buffer implementation in C.

Stretchy buffers are C++ vector approximations. They provide a generic interface for dynamic arrays.

Basically just [Sean Barrett's stb_stretchy_buffer.h](https://github.com/nothings/stb/blob/master/stretchy_buffer.h)

## Usage

Declare a stretchy buffer with: `TYPE *sb = NULL`. A `NULL` pointer represents an empty buffer.

`sbLen(TYPE *a)` returns the length of the buffer.

`sbCap(TYPE *a)` returns the capacity of the buffer (>= length).

`sbPush(TYPE *a, TYPE v)` adds the element `v` to the end of the buffer, growing if needed.

`sbFree(TYPE *a)` frees the buffer. *Only* free the buffer with this macro.

Elements are accessed like arrays: `TYPE a = sb[x]`