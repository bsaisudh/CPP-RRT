cmake_minimum_required(VERSION 3.2.1)
project (CPP-RRT)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" ON)

#set(Boost_USE_STATIC_LIBS ON) 
#set(Boost_USE_MULTITHREADED ON)  
#set(Boost_USE_STATIC_RUNTIME ON) 
#find_package(Boost 1.45.0 COMPONENTS tuple) 
#
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS}) 
#    add_executable(progname file1.cxx file2.cxx) 
#    target_link_libraries(progname ${Boost_LIBRARIES})
#endif()

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost REQUIRED COMPONENTS filesystem system)
SET(CMAKE_LD_FLAGS "-lutil -lboost_iostreams -lboost_system -lboost_filesystem")
message(${Boost_LIBRARY_DIRS} "---" ${Boost_SYSTEM_LIBRARY})

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -O0 -g -D_GLIBCXX_DEBUG")


if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/main.cpp include/lib.hpp)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)
