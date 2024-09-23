cmake_minimum_required(VERSION 3.10)
project(Vector)

# Создаем библиотеку
add_library(lib_vector vector.cpp vector.h)

# Указываем, что библиотека должна быть сгенерирована
set_target_properties(lib_vector PROPERTIES OUTPUT_NAME lib_vector)

# Создаем тесты
add_executable(test_vector test_vector.cpp)

# Подключаем библиотеки DMassive и Google Test к тестам
target_link_libraries(test_vector gtest gtest_main lib_dmassive lib_vector)

# ... (добавьте  find_package(GTest ...)  , если вы еще не сделали)
 
