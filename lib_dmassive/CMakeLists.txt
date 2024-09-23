cmake_minimum_required(VERSION 3.10)
project(DMassive)

# Создаем библиотеку
add_library(lib_dmassive dmassive.cpp dmassive.h) 

# Указываем, что библиотека должна быть сгенерирована
set_target_properties(lib_dmassive PROPERTIES OUTPUT_NAME lib_dmassive) 

# Создаем тесты
add_executable(test_dmassive test_dmassive.cpp)

# Подключаем библиотеку и Google Test к тестам
target_link_libraries(test_dmassive gtest gtest_main lib_dmassive)


 
