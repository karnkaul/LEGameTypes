>*Note: This repository primarily serves as a submodule for `LittleEngine` (and is bound by the same licence), but is completely standalone and free to be used in any other projects.*

### LittleEngine Game Types

*Copyright 2019 Karn Kaul*

Types:
  - `Fixed`: fixed-point implementation using scaled `uint64_t`
  - `Vector2`: geometric interpretation with full vector arithmetic support and common functions
  - `Matrix3`: row-major 3x3 transformation matrix with multiplication support
  - `Transform`: scene-graph unit with efficient matrix computations and support for parenting
  - `Rect2`: struct with two `Vector2`s and convenience functions
  - `UByte`: struct using `uint8_t` as a byte value (0-255), with convenience functions
  - `Time`: struct using `int64_t` to store microsecond spans, with convenience functions
  - `Version`: struct modelling semantic versioning, with support for parsing a string representation
  - `Utils`: various maths and templated generic and stateless functions

CMake:
  - Set `SOURCES` to existing source file list and include `GameTypes.cmake` before creating the target

Compile Units:
  - All .cpp files
