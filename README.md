# conan-gsoap-example
Simple example of using gsoap with Conan and CMake.

## Usage

### Linux
```bash
git clone https://github.com/arnesor/conan-gsoap-example.git
mkdir build && cd build
conan install ../conan-gsoap-example --build=missing
cmake ../conan-gsoap-example
cmake --build .
bin/calcclient
```

### Windows
```powershell
git clone https://github.com/arnesor/conan-gsoap-example.git
mkdir build && cd build
conan install ..\conan-gsoap-example --profile=vs19-x86_64-win-debug --build=missing
cmake ..\conan-gsoap-example -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug
cmake --build .
bin\calcclient
```

## Cross compiling
This example cross compiles the program on CentoOS8 (x86_64) to an aarch64
executable, using a custom built gcc 10.2 cross compiler installed in
/opt/aarch64-gcc102-linux-gnu.

Instructions:

```bash
git clone https://github.com/arnesor/conan-gsoap-example.git
mkdir build && cd build
conan install ../conan-gsoap-example --profile:build=default --profile:host=gcc102-aarch64 --build=missing
source activate.sh
cmake -DCMAKE_TOOLCHAIN_FILE=../conan-gsoap-example/Toolchain-aarch64-gcc102.cmake ../conan-gsoap-example/
cmake --build .
```
