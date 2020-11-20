project(gsoap-test CXX)
cmake_minimum_required(VERSION 3.1.2)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    message(FATAL_ERROR "You need to run conan install <source-dir> in the build-directory \
            first in order to install third-party libraries and generate conanbuildinfo.cmake.")
endif()

find_program(WSDL2H_PROG wsdl2h)
message("WSDL2H  : ${WSDL2H_PROG}")

find_program(SOAPCPP2_PROG soapcpp2)
message("SOAPCPP2: ${SOAPCPP2_PROG}")

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/calc.h
    COMMAND ${CONAN_BIN_DIRS_GSOAP}/wsdl2h -o ${CMAKE_BINARY_DIR}/calc.h ${CMAKE_SOURCE_DIR}/calc.wsdl
    DEPENDS ${CMAKE_SOURCE_DIR}/calc.wsdl
)

add_custom_command(
	OUTPUT ${CMAKE_BINARY_DIR}/soapcalcProxy.cpp ${CMAKE_BINARY_DIR}/soapC.cpp
    COMMAND ${CONAN_BIN_DIRS_GSOAP}/soapcpp2 -j -r -CL ${CMAKE_BINARY_DIR}/calc.h 
    DEPENDS ${CMAKE_BINARY_DIR}/calc.h
)

add_executable(calcclient ${CMAKE_BINARY_DIR}/soapcalcProxy.cpp ${CMAKE_BINARY_DIR}/soapC.cpp CalcClient.cpp)
target_link_libraries(calcclient CONAN_PKG::gsoap)
target_include_directories(calcclient PRIVATE ${CMAKE_BINARY_DIR})

