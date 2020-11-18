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
