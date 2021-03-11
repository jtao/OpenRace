# Building

Using conan to manage dependencies. Instructiosn to install conan can be found [here](https://conan.io/downloads.html).

To build, run the following:

```
mkdir build && cd build
conan install ..
cmake -DLLVM_DIR=$LLVM_DIR ..
make -j
```

Feel free to adjust cmake options as you see fit.

The only required option is `LLVM_DIR` which should point to the directory containing `LLVMConfig.cmake`.

# Developing
Project layout based on: https://github.com/vector-of-bool/pitchfork
- In general prefere Merged header/source
- Pointer analysis is exception for legacy

Cmake guidelines based off of: https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1

Conan usage based on: https://docs.conan.io/en/latest/integrations/build_system/cmake/cmake_generator.html