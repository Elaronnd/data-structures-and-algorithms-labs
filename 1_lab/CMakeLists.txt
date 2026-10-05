cmake_minimum_required(VERSION 4.3)
project(LAB1_CDA C)

set(CMAKE_C_STANDARD 11)

add_executable(LAB1_CDA_T1_M1 "task_1/method_1/Ковальчук_ІО-61_Lab1_task1_method1.c")
add_executable(LAB1_CDA_T1_M2 "task_1/method_2/Ковальчук_ІО-61_Lab1_task1_method2.c")
add_executable(LAB1_CDA_T2_M1 "task_2/method_1/Ковальчук_ІО-61_Lab1_task2_method1.c")
add_executable(LAB1_CDA_T2_M2 "task_2/method_2/Ковальчук_ІО-61_Lab1_task2_method2.c")
target_link_libraries(LR1_CDA_T1_M1 m)
target_link_libraries(LAB1_CDA_T1_M2 m)
target_link_libraries(LAB1_CDA_T2_M1 m)
target_link_libraries(LAB1_CDA_T2_M2 m)
