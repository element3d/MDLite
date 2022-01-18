cmake_minimum_required(VERSION 3.0)

set (PROJECT MDLiteTestMobileSimulator)
project(${PROJECT})

set (SRC 
	main.cpp 
	MainWindow.h 
	MainWindow.cpp
)

add_executable(${PROJECT} ${SRC})

target_link_libraries(${PROJECT} 
	MDLiteTest 	
)

set_property(TARGET ${PROJECT} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")