add_executable(inventory
    src/main.c
    src/input.c
    src/inventory.c
    src/storage.c
)




target_include_directories(inventory PRIVATE include)
