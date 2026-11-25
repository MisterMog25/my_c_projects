# my_c_projects

C11 practice: standalone exercises plus three small console programs.
Everything builds with `-Wall -Wextra -Wpedantic` **and** AddressSanitizer +
UndefinedBehaviorSanitizer, so a build is also a first correctness check.

## Layout

| Path | What |
|---|---|
| `exercises/*.c` | One file per exercise — pointers, structs, strings, `funcs`, `morse`, `digital_clock`, … |
| `exercises/string_practice/` | String-library practice, compiled by hand (see below) |
| `exercises/old/` | Early scratch programs, kept for reference |
| `projects/inventory/` | Inventory manager split into `src/` + `include/` (input, storage, inventory) |
| `projects/studentMS/` | Student records manager |
| `projects/hangman/` | Hangman, with words loaded from a file |
| `CMakeLists.txt` | Build entry point |
| `.clang-format`, `.clang-tidy` | Formatting and static-analysis config |

## Build and run

```bash
cmake -S . -B build          # configure (also writes build/compile_commands.json)
cmake --build build -j4      # build everything

./build/morse                # every exercises/*.c becomes ./build/<file stem>
./build/structs
./build/inventory
./build/studentMS
./build/hangman
```

Each `exercises/<name>.c` gets its own executable named after the file, so a
new exercise needs no build-system edit — CMake re-globs automatically
(`CONFIGURE_DEPENDS`).

`exercises/string_practice/*.c` sits outside that glob and is compiled by hand:

```bash
clang -Wall -Wextra -Wpedantic -fsanitize=address,undefined \
      exercises/string_practice/01_string_lib.c -o /tmp/01_string_lib
```

Sanitizers are on for every target, so the usual failure mode is a loud
`AddressSanitizer: …` report instead of a silent wrong answer.

## Tooling

- `clangd` picks up `build/compile_commands.json` (generated at configure time).
- `.clang-tidy` enables `bugprone-*`, `clang-analyzer-*`, `performance-*`,
  `readability-*`.
- `.clang-format` keeps the style stable.

## Known compiler warnings

A clean build currently prints these. They are harmless but they hide the next
real warning, so they are worth clearing one by one — reproduce with:

```bash
cmake --build build 2>&1 | grep -E "warning|note"
```

| Location | Warning | What it means |
|---|---|---|
| `exercises/funcs.c:33` | `-Wunused-variable` | `student1` is constructed and never read |
| `exercises/morse.c:113` | `-Wsign-compare` | `int buf_len` compared against `size_t` from `sizeof`; both should be the same type |
| `exercises/testing.c:4` | `-Wstrict-prototypes` | `int main()` should be `int main(void)` |
| `exercises/testing.c:23` | `-Wformat` | `strcspn` returns `size_t`, printed with `%d`; needs `%zu` |
| `projects/studentMS/src/sms.c:353` | `-Warray-parameter` | `loadStudents` takes `char path[50]` here but was declared `char path[55]` at line 25 — one of the two is wrong |
