cmake_minimum_required(VERSION 3.16)
project(my_c_path C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic -g -fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

# shared code


# every exercises/*.c becomes its own executable, named after the file
file(GLOB EXERCISES CONFIGURE_DEPENDS exercises/*.c)
foreach(src ${EXERCISES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()

# real projects
add_subdirectory(projects/inventory)
add_subdirectory(projects/studentMS)
