add_executable(
	shell-app
	main.cpp
	Obstacle.cpp
	Square.cpp
	Circle.cpp
	RobotWorkspace.cpp
	InputMap.cpp
	PathDisplay.cpp
	)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

target_include_directories(shell-app INTERFACE ${Boost_INCLUDE_DIRS})

include_directories(shell-app ${Boost_INCLUDE_DIRS})
link_directories(shell-app ${Boost_LIBRARY_DIRS})
target_link_libraries(shell-app ${Boost_LIBRARIES})

target_link_libraries(
shell-app
${Boost_LIBRARIES}
${Boost_PROGRAM_OPTIONS_LIBRARY}
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
Boost::filesystem
Boost::system
)
