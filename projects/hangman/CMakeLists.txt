add_executable(hangman
    src/main.c
    # src/input.c
    # src/inventory.c
    # src/storage.c
)

target_include_directories(hangman PRIVATE include)