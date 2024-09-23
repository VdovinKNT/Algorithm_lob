cmake_minimum_required(VERSION 3.10)
project(Stack)

# Создаем библиотеку
add_library(lib_stack stack.cpp stack.h)

# Указываем, что библиотека должна быть сгенерирована
set_target_properties(lib_stack PROPERTIES OUTPUT_NAME lib_stack)

# Создаем тесты
add_executable(test_stack test_stack.cpp)

# Подключаем библиотеки Google Test к тестам
target_link_libraries(test_stack gtest gtest_main lib_stack)

# ... (добавьте  find_package(GTest ...)  , если вы еще не сделали)
 
