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

add_library(${PROJECT} SHARED ${SRC_PRIVATE} ${SRC})

target_link_libraries(${PROJECT}
    element3d
    CarbonGL
)

if(ANDROID)
    target_link_libraries(${PROJECT}
		EGL
		GLESv3
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
