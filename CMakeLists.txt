cmake_minimum_required(VERSION 3.12)


project(test CXX C)

add_subdirectory(src bin)

#aux_source_directory(. source_main) #这里不再使用,因为我后面改成了多个目标构建呢

include_directories(src)#包含头文件所在库

link_libraries(yyjson)#为所有目标都添加这个库

add_executable(main main.cpp)

add_executable(example1 example1.cpp)

add_executable(example2 example2.cpp)

add_executable(example3 example3.cpp)

add_executable(example4 example4.cpp)

add_executable(StateEdit StateEdit.cpp)
