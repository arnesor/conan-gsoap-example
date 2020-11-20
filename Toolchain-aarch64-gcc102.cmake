set(CMAKE_SYSTEM_NAME Linux)

# Assume compilers are in the PATH and that ccache links exists (optional).
set(CMAKE_C_COMPILER   aarch64-gcc102-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-gcc102-linux-gnu-g++)

set(CMAKE_AR aarch64-gcc102-linux-gnu-gcc-ar CACHE INTERNAL "Archiver")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++" CACHE INTERNAL "" FORCE)
