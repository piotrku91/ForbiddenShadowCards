cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(ForbiddenShadowCards)

set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic -pedantic-errors -g)

add_compile_options(${FLAGS})

#enable_testing()

##add_library(dbEngineLib STATIC Db.cpp)
#add_library(menuLib STATIC Menu.cpp Menu_cmds.cpp)

add_executable(${PROJECT_NAME} main.cpp Player.cpp)
#target_link_libraries(${PROJECT_NAME} dbEngineLib menuLib)

#$add_executable(${PROJECT_NAME}-ut test.cpp)
#target_link_libraries(${PROJECT_NAME}-ut dbEngineLib gtest_main)

#add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)