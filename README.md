# gsoap-example
Simple example of using gsoap with Conan and CMake.

## Usage
Instructions (Linux):

```bash
git clone https://github.com/arnesor/gsoap-example.git
mkdir build && cd build
conan install ../gsoap-example --build=missing
cmake ../gsoap-example
cmake --build .
bin/calcclient
```

## Cross compiling
This example cross compiles the program on CentoOS8 (x86_64) to an aarch64
executable, using a custom built gcc 10.2 cross compiler installed in
/opt/aarch64-gcc102-linux-gnu.

Instructions:

```bash
git clone https://github.com/arnesor/gsoap-example.git
mkdir build && cd build
conan install ../gsoap-example --profile:build=default --profile:host=gcc102-aarch64 --build=missing
source activate.sh
cmake -DCMAKE_TOOLCHAIN_FILE=../gsoap-example/Toolchain-aarch64-gcc102.cmake ../gsoap-example/
cmake --build .
```
