cmake_minimum_required(VERSION 3.0)

set (PROJECT MDLite)
project(${PROJECT})

file(GLOB SRC_PRIVATE CONFIGURE_DEPENDS
	private/*.cpp 
	private/*.h
)

file(GLOB SRC CONFIGURE_DEPENDS
	*.cpp 
	*.h
)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/get_elementary_libs.cmake)
get_elementary_libs()

add_library(${PROJECT} SHARED ${SRC_PRIVATE} ${SRC})

target_link_libraries(${PROJECT}
    element3d
	${ELEMENTARY_LIBS}
)

if(ANDROID)
    target_link_libraries(${PROJECT}
		EGL
		GLESv3
		log
    )
elseif(WIN32)
	add_definitions(-D__E3_EXPORTING__)
    target_link_libraries(${PROJECT}
        glew32
        OpenGL32
    )
elseif(UNIX)
    target_link_libraries(${PROJECT}
        GL
        GLEW
    )
endif()
