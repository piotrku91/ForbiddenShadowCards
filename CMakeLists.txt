cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(ForbiddenShadowCards)

set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic -pedantic-errors -g)

add_compile_options(${FLAGS})
find_package(SDL2 REQUIRED)
include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp window.cpp Player.cpp )
target_link_libraries(
    ${PROJECT_NAME}
    GL
    SDL2
    SDL2_image
)


#$add_executable(${PROJECT_NAME}-ut test.cpp)
#target_link_libraries(${PROJECT_NAME}-ut dbEngineLib gtest_main)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)