cmake_minimum_required(VERSION 4.3)
project(LAB2_CDA C)

set(CMAKE_C_STANDARD 11)

add_executable(LAB2_CDA_M1 "task_1/method_1/Ковальчук_ІО-61_Lab2_method1.c")
add_executable(LAB2_CDA_M2 "task_1/method_2/Ковальчук_ІО-61_Lab2_method2.c")
target_link_libraries(LAB2_CDA_M1 m)
target_link_libraries(LAB2_CDA_M2 m)
