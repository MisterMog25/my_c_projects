/*
 * TASK 02 — taglist.c   (the "similar but different" program)
 * ============================================================
 * Same machinery as 02_wordlist_example.c, different behavior. Read the
 * example, understand every [P#], then build this one yourself.
 *
 * SPEC
 * ----
 * Read ONE line from stdin — use the [P1] pattern (fgets + strcspn).
 * Do NOT use scanf for the line.
 *
 * The line is a comma-separated list of tags, like:
 *     "  c, malloc ,realloc,, free,c  "
 *
 * For each comma-separated field:
 *   - trim leading and trailing spaces
 *   - if what remains is empty, skip it
 *   - if the tag is already stored (exact match, strcmp), skip it
 *   - otherwise store a heap copy of it (strdup) — first occurrence wins
 *
 * When done, print:
 *     N unique tag(s):
 *     - <tag>
 *     (one tag per line, in the order they were first seen)
 *
 * RULES
 * -----
 *   - The storage must be heap allocated and growable. A fixed array like
 *     char tags[50][32] is banned — that is the whole point of [P3]/[P4].
 *   - Do not use strtok / strsep / strchr for the splitting. Write the
 *     walk yourself, like the example does for spaces. (strcmp, strlen,
 *     strdup, memmove are all fine.)
 *   - Free everything. Run under ASan: zero leaks, zero overflows.
 *
 * SELF-CHECKS (run each, compare with the expectations)
 * -----------------------------------------------------
 *   input: "  c, malloc ,realloc,, free,c  "
 *        -> 4 unique tag(s): c, malloc, realloc, free
 *   input: ""
 *        -> 0 unique tag(s):
 *   input: " a , a , a "
 *        -> 1 unique tag(s): a
 *   input: "solo"
 *        -> 1 unique tag(s): solo
 *
 * Build & run:
 *   cd ~/my_c_path/exercises/string_practice
 *   gcc -std=gnu11 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
 *       02_taglist.c -o 02_taglist
 *   ./02_taglist
 *
 * HINT MAP
 * --------
 *   reading + strip     -> example [P1]
 *   walking the fields  -> example [P2] (',' is the separator now; each
 *                          field also needs its spaces trimmed)
 *   storing a copy      -> example [P3]
 *   growing the array   -> example [P4]
 *   duplicate check     -> example wl_find
 *   freeing             -> example [P5]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* TODO: your program */
    return 0;
}
