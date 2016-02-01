cmake_minimum_required(VERSION 3.0)

set(BINARY_NAME space)

project(${BINARY_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp src/interface/console/InterfaceConsole.h src/interface/console/InterfaceTerminalConsole.cpp src/interface/console/InterfaceTerminalConsole.h src/threads/console.cpp src/threads/console.h src/state/GlobalState.cpp src/state/GlobalState.h src/threads/Thread.cpp src/threads/Thread.h src/utils/dictionary.cpp src/utils/dictionary.h src/utils/data_types/Type.cpp src/utils/data_types/Type.h)

# Including GLFW
add_subdirectory(src/interface/glfw-3.1.2)
include_directories(src/interface/glfw-3.1.2/include)


add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_link_libraries(${BINARY_NAME} glfw ${GLFW_LIBRARIES})
