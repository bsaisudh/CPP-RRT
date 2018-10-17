add_executable(
	shell-app
	main.cpp
	Obstacle.cpp
	Square.cpp
	Circle.cpp
	RobotWorkspace.cpp
	InputMap.cpp
	PathDisplay.cpp
	RRT.cpp
	)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

