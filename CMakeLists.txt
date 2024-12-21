cmake_minimum_required(VERSION 3.10)
project(stack)

# Добавление библиотеки stack
add_library(stack stack.c)

# Добавление исполняемого файла для основной программы
add_executable(main main.c)

# Связка основной программы с библиотекой stack
target_link_libraries(main stack)
