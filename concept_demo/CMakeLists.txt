cmake_minimum_required(VERSION 3.23)
project(concept_demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(concept_demo main.cpp)

include_directories(headers c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(concept_demo ${SFML_LIBRARIES})
endif()
