cmake_minimum_required(VERSION 4.3)
project(LR1_CDA C)

set(CMAKE_C_STANDARD 11)

add_executable(LR1_CDA_E1_1 "1 task/method 2/ІО-61_Ковальчук_Л1_П1_код2.c")
add_executable(LR1_CDA_E1_2 "2 task/method 1/ІО-61_Ковальчук_Л1_П2_код1.c")
add_executable(LR1_CDA_E2_1 "1 task/method 1/ІО-61_Ковальчук_Л1_П1_код1.c")
add_executable(LR1_CDA_E2_2 "2 task/method 2/ІО-61_Ковальчук_Л1_П2_код2.c")
target_link_libraries(LR1_CDA_E1_1 m)
target_link_libraries(LR1_CDA_E1_2 m)
target_link_libraries(LR1_CDA_E2_1 m)
target_link_libraries(LR1_CDA_E2_2 m)
