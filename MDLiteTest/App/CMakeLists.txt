cmake_minimum_required(VERSION 3.4.1)

set(PROJECT MDLiteTest)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -frtti -fexceptions -Wall")
#add_definitions( -Wall -O2 -fexceptions )

if(WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -static-openmp")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -static-openmp")
endif(WIN32)

if(WIN32)
	add_definitions(-D__E3_EXPORTING__)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

file(GLOB SRC_PRIVATE CONFIGURE_DEPENDS
	private/*.cpp 
	#private/*.h
)

file(GLOB SRC CONFIGURE_DEPENDS
	*.cpp 
	#*.xml 
	*.h
)

if(ANDROID)
	set(SRC ${SRC} Android/android_main.cpp)
endif(ANDROID)

set (SRC
    ${SRC}
	${SRC_PRIVATE}
    Application.cpp
)

add_library(${PROJECT} SHARED ${SRC})

target_include_directories(${PROJECT} PRIVATE private)

target_link_libraries(${PROJECT}
    element3d
	${ELEMENTARY_LIBS}
    MDLite
)

if(ANDROID)
	target_link_libraries(${PROJECT}
		android
		EGL
		GLESv3
		log
	)	
elseif(EMSCRIPTEN)
	target_link_libraries(${PROJECT}
		yoga
	)
elseif(WIN32)
	target_link_libraries(${PROJECT}
		glew32
		OpenGL32
	)
endif()
