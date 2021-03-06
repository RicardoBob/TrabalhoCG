cmake_minimum_required(VERSION 3.5)

# Project Name
PROJECT(engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${PROJECT_NAME} main.cpp tinyxml2-master/tinyxml2.cpp tinyxml2-master/tinyxml2.h classes/catmull.cpp  headers/catmull.h classes/Group.cpp headers/Group.h classes/Transformation.cpp  headers/Transformation.h classes/Point.cpp headers/Point.h)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

SET(CMAKE_CXX_FLAGS_DEBUG "-O2")


if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

    message(STATUS "Toolkits_DIR set to: " C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits)
    set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

    if (NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/GL/glut.h" OR NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.lib")
        message(ERROR ": GLUT not found")
    endif (NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/GL/glut.h" OR NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.lib")

    if (NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/GL/glew.h" OR NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.lib")
        message(ERROR ": GLEW not found")
    endif (NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/GL/glew.h" OR NOT EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.lib")


    include_directories(C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES}
            C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.lib
            C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.lib )

    if (EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.dll"  AND EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.dll")
        file(COPY C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
        file(COPY C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
    endif(EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glut/glut32.dll"  AND EXISTS "C:/Users/igor1/Desktop/CG/TrabalhoCG/toolkit/toolkits/glew/glew32.dll")

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

else (WIN32) #Linux and Mac

    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")

    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIR})
    link_directories(${GLUT_LIBRARY_DIRS})
    add_definitions(${GLUT_DEFINITIONS})

    if (NOT APPLE)
        find_package(GLEW REQUIRED)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
        target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES})
    else (NOT APPLE)
        target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
    endif(NOT APPLE)

    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
    if(NOT GLUT_FOUND)
        message(ERROR ": GLUT not found!")
    endif(NOT GLUT_FOUND)

endif(WIN32)