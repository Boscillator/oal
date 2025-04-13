cmake_minimum_required(VERSION 3.15)
project(oal CXX)




add_library(oal src/oal.cpp)
target_include_directories(oal PUBLIC include)



set_target_properties(oal PROPERTIES PUBLIC_HEADER "include/oal.h")
install(TARGETS oal)
