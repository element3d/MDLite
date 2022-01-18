cmake_minimum_required(VERSION 3.4.1)

include_directories(App)

add_subdirectory(App)

if ((WIN32 OR (UNIX AND NOT ANDROID)) AND NOT EMSCRIPTEN)
	add_subdirectory(Desktop)
    add_subdirectory(MobileSimulator)
endif()


