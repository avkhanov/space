cmake_minimum_required(VERSION 2.8)

set(BINARY_NAME space)

project(${BINARY_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# set(SOURCE_FILES
#         src/main.cpp src/interface/console/InterfaceConsole.h src/interface/console/InterfaceTerminalConsole.cpp src/interface/console/InterfaceTerminalConsole.h src/threads/console.cpp src/threads/console.h src/state/GlobalState.cpp src/state/GlobalState.h src/threads/Thread.cpp src/threads/Thread.h src/threads/rendering.cpp src/threads/rendering.h src/util/utils.cpp src/util/utils.h)
set(SOURCE_FILES
        src/main.cpp src/state/GlobalState.cpp src/state/GlobalState.h src/util/utils.cpp src/util/utils.h src/threads/rendering.cpp)

# Including GLFW
add_subdirectory(src/interface/glfw-3.1.2)
include_directories(src/interface/glfw-3.1.2/include)


add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_link_libraries(${BINARY_NAME} glfw ${GLFW_LIBRARIES})
