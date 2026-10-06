/*
 * CHAPTER 1 — The string library, by hand
 * ========================================
 *
 * Every string function in <string.h> is just a loop that walks a char*
 * until it hits '\0'. strlen counts until the zero. strcpy copies until
 * the zero. strcmp stops at the zero or the first difference. strchr
 * looks for your byte. That's all of them.
 *
 * Before you use those functions as black boxes, write them yourself once.
 * Then they stop being magic and start being obvious.
 *
 * Your job: fill in the five TODO functions below.
 * Rules:
 *   - Do NOT call anything from <string.h> in your functions. Just loops,
 *     pointer arithmetic, and comparisons. (It isn't even included above
 *     your code, so calling strlen() here won't compile — on purpose.)
 *   - Return exactly what the spec says, including NULL on not-found.
 *
 * Build and run:
 *   cd ~/my_c_path/exercises/string_practice
 *   gcc -std=gnu11 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
 *       01_string_lib.c -o 01_string_lib
 *   ./01_string_lib
 *
 * Goal: ALL TESTS PASSED. Ask me if you get stuck for more than a few minutes.
 */
#include <stdio.h>

/* ------------------------------------------------------------------
 * 1. my_strlen
 *    Return the number of characters before the '\0'.
 *      my_strlen("")      -> 0
 *      my_strlen("hello") -> 5
 * ------------------------------------------------------------------ */
size_t my_strlen(const char *s) {
    /* TODO */
    return 0;
}

/* ------------------------------------------------------------------
 * 2. count_char
 *    Return how many times c appears in s.
 *      count_char("banana", 'a') -> 3
 *      count_char("banana", 'z') -> 0
 * ------------------------------------------------------------------ */
int count_char(const char *s, char c) {
    /* TODO */
    return 0;
}

/* ------------------------------------------------------------------
 * 3. my_strcpy
 *    Copy src into dst INCLUDING the '\0'. Return dst.
 *    The caller guarantees dst is big enough — you don't need a size
 *    parameter; that's exactly why strcpy is dangerous and why sizes
 *    matter later.
 * ------------------------------------------------------------------ */
char *my_strcpy(char *dst, const char *src) {
    /* TODO */
    return dst;
}

/* ------------------------------------------------------------------
 * 4. my_strcmp
 *    Compare byte by byte. Stop at the first difference or at '\0'
 *    (whichever comes first).
 *    Return < 0 if a is less, 0 if equal, > 0 if a is greater.
 *    The comparison is by unsigned char value, not by char (char may
 *    be signed!). Byte 'a' is 97 in ASCII — you may hardcode nothing;
 *    compare characters directly and just return the difference.
 *      my_strcmp("abc", "abc")  -> 0
 *      my_strcmp("abc", "abd")  -> negative
 *      my_strcmp("abcd", "abc") -> positive
 * ------------------------------------------------------------------ */
int my_strcmp(const char *a, const char *b) {
    /* TODO */
    return 0;
}

/* ------------------------------------------------------------------
 * 5. my_strchr
 *    Return a pointer to the FIRST occurrence of c in s, or NULL.
 *    Note: looking for '\0' is legal — it should return the pointer
 *    to the terminator.
 *      my_strchr("hello", 'l')  -> points at the first 'l'
 *      my_strchr("hello", 'z')  -> NULL
 *      my_strchr("hello", '\0') -> points at the terminator
 * ------------------------------------------------------------------ */
char *my_strchr(const char *s, char c) {
    /* TODO */
    return NULL;
}

/* ==================================================================
 * TEST HARNESS — do not modify below this line
 * ================================================================== */
#include <string.h>

static int fails = 0;

static void check_int(const char *name, long got, long want) {
    if (got == want) {
        printf("  PASS  %-24s got %ld\n", name, got);
    } else {
        printf("  FAIL  %-24s got %ld, want %ld\n", name, got, want);
        fails++;
    }
}

static void check_str(const char *name, const char *got, const char *want) {
    if (got && strcmp(got, want) == 0) {
        printf("  PASS  %-24s \"%s\"\n", name, got);
    } else {
        printf("  FAIL  %-24s got \"%s\", want \"%s\"\n",
               name, got ? got : "(null)", want);
        fails++;
    }
}

static void check_ptr(const char *name, const char *got, const char *want) {
    if (got == want) {
        printf("  PASS  %-24s %s\n", name, got ? "correct pointer" : "NULL");
    } else {
        printf("  FAIL  %-24s got %p, want %p\n",
               name, (const void *)got, (const void *)want);
        fails++;
    }
}

static void check_sign(const char *name, int got, int want_sign) {
    int got_sign = (got > 0) - (got < 0);
    if (got_sign == want_sign) {
        printf("  PASS  %-24s sign %d\n", name, got_sign);
    } else {
        printf("  FAIL  %-24s sign %d, want %d (returned %d)\n",
               name, got_sign, want_sign, got);
        fails++;
    }
}

int main(void) {
    puts("1. my_strlen");
    check_int("empty",       (long)my_strlen(""),          0);
    check_int("\"a\"",       (long)my_strlen("a"),         1);
    check_int("\"hello\"",   (long)my_strlen("hello"),     5);
    check_int("with spaces", (long)my_strlen("   three"),  8);

    puts("2. count_char");
    check_int("\"banana\" 'a'",  count_char("banana", 'a'), 3);
    check_int("\"banana\" 'z'",  count_char("banana", 'z'), 0);
    check_int("empty string",    count_char("", 'a'),       0);
    check_int("\"aaaa\" 'a'",    count_char("aaaa", 'a'),   4);
    check_int("case matters",    count_char("AaA", 'A'),    2);

    puts("3. my_strcpy");
    char dst[32] = {0};
    my_strcpy(dst, "hello");
    check_str("copies text", dst, "hello");
    my_strcpy(dst, "");
    check_str("copies empty", dst, "");
    memset(dst, 'X', sizeof dst - 1);   /* fill with junk... */
    dst[sizeof dst - 1] = '\0';         /* ...but stay printable if your copy is buggy */
    my_strcpy(dst, "hi");
    check_str("writes the '\\0' too", dst, "hi");
    check_ptr("returns dst", my_strcpy(dst, "abc"), dst);

    puts("4. my_strcmp");
    check_int("equal",           my_strcmp("abc", "abc"), 0);
    check_int("empty vs empty",  my_strcmp("", ""),       0);
    check_sign("abc < abd",      my_strcmp("abc", "abd"), -1);
    check_sign("abd > abc",      my_strcmp("abd", "abc"), +1);
    check_sign("prefix smaller", my_strcmp("abc", "abcd"), -1);
    check_sign("space vs end",   my_strcmp("abc", "abc "), -1);
    check_sign("empty is smallest", my_strcmp("", "a"),    -1);

    puts("5. my_strchr");
    char s[] = "hello";
    check_ptr("first 'l'",  my_strchr(s, 'l'),  s + 2);
    check_ptr("first 'h'",  my_strchr(s, 'h'),  s);
    check_ptr("last 'o'",   my_strchr(s, 'o'),  s + 4);
    check_ptr("absent 'z'", my_strchr(s, 'z'),  NULL);
    check_ptr("finds '\\0'", my_strchr(s, '\0'), s + 5);

    printf("\n%s (%d failure%s)\n",
           fails ? "SOME TESTS FAILED" : "ALL TESTS PASSED",
           fails, fails == 1 ? "" : "s");
    return fails != 0;
}
