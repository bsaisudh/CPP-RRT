set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    ObstacleTest.cpp
    RobotWorkspaceTest.cpp
    InputMapTest.cpp
    PathDisplayTest.cpp
    RRTTest.cpp
    ../app/Circle.cpp
    ../app/InputMap.cpp
    ../app/Obstacle.cpp
    ../app/PathDisplay.cpp
    ../app/RobotWorkspace.cpp
    ../app/RRT.cpp
    ../app/Square.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
					   ../vendor/googletest/googlemock/include
					   ../include)
target_link_libraries(cpp-test PUBLIC gtest)
