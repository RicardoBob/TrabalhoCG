cmake_minimum_required(VERSION 3.5)

# Project Name
PROJECT(engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 11)

if (NOT APPLE)
    if (WIN32)
        set(TOOLKITS_FOLDER "" CACHE PATH "Path to toolkits folder")
        include_directories(
                ${TOOLKITS_FOLDER}/glew
                ${TOOLKITS_FOLDER}/glut
                ${TOOLKITS_FOLDER}/devil)
        link_directories(
                ${TOOLKITS_FOLDER}/glew
                ${TOOLKITS_FOLDER}/glut
                ${TOOLKITS_FOLDER}/devil)
    else(WIN32)
        find_package(GLEW REQUIRED)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
    endif(WIN32)
endif(NOT APPLE)

if (NOT WIN32)
    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIR})
    link_directories(${GLUT_LIBRARY_DIRS})
    add_definitions(${GLUT_DEFINITIONS})

    find_package(DevIL REQUIRED)
    link_libraries(${IL_LIBRARIES} )
    include_directories(${IL_INCLUDE_DIR})
endif(NOT WIN32)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2)

add_executable(${PROJECT_NAME} main.cpp tinyxml2-master/tinyxml2.cpp tinyxml2-master/tinyxml2.h classes/catmull.cpp  headers/catmull.h classes/Group.cpp headers/Group.h classes/Transformation.cpp  headers/Transformation.h classes/Point.cpp headers/Point.h)

file(COPY ${CMAKE_SOURCE_DIR}/texturas DESTINATION ${CMAKE_BINARY_DIR})

if (WIN32)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glut32 glew32 DevIL)
    file(COPY ${TOOLKITS_FOLDER}/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${TOOLKITS_FOLDER}/devil/DevIL.dll DESTINATION ${CMAKE_BINARY_DIR})

else(WIN32)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif (WIN32)