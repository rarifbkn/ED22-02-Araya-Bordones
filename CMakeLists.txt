cmake_minimum_required(VERSION 3.0.0)
project(Taller VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories("src")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Taller src/main.cpp src/logic/LinkedList.cpp src/logic/Detector.cpp src/logic/Person.cpp src/logic/NodePerson.cpp )
target_link_libraries(Taller ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
