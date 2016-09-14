cmake_minimum_required(VERSION 3.3)
project(PythonGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB PythonGenerator_SRC
    "*.cpp"
    "*.h"
    )

set(BOOST_ROOT "../boost_1_61_0")
find_package(Boost 1.61.0 COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(pygen ${PythonGenerator_SRC})
target_link_libraries(pygen ${Boost_LIBRARIES})
