cmake_minimum_required(VERSION 3.18)
project(leetcode-training)

set(CMAKE_CXX_STANDARD 17)

message("CMAKE_CXX_COMPILER_ID = " ${CMAKE_CXX_COMPILER_ID})
message("CMAKE_C_COMPILER      = " ${CMAKE_C_COMPILER})
message("CMAKE_CXX_COMPILER    = " ${CMAKE_CXX_COMPILER})

#
# Enable warning raising as an error
#
if (${CMAKE_VERSION} VERSION_EQUAL "3.24.0" OR ${CMAKE_VERSION} VERSION_GREATER "3.24.0")
    set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
else ()
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
    endif ()
endif ()

# Allow to detect local execution
add_compile_definitions(LEETCODE_TRAINING_PROJECT "")

# All sub-directories with solutions below this line.

