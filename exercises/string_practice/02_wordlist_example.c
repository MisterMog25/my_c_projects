/*
 * 02_wordlist_example.c — THE WORKED EXAMPLE
 * ===========================================
 * Read one line, split it into words, store the words in a growable heap
 * array, print a summary, free everything.
 *
 * Five patterns live in this program. They get reused for the rest of the
 * series. Each is tagged [P#] in the code.
 *
 *   [P1] Safe line input:  fgets + strip the newline with strcspn.
 *   [P2] In-place split:   walk the line, write '\0' over each separator,
 *                          remember where each word starts. No copying
 *                          while scanning — just cutting and pointing.
 *   [P3] String ownership: strdup gives each stored word its own private
 *                          heap copy, so the original line can die.
 *   [P4] Growable array:   len/cap, realloc through a TEMP pointer,
 *                          capacity doubled.
 *   [P5] Free in order:    free every owned string, then the array itself.
 *
 * Build & run:
 *   cd ~/my_c_path/exercises/string_practice
 *   gcc -std=gnu11 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined \
 *       02_wordlist_example.c -o 02_wordlist_example
 *   ./02_wordlist_example
 *
 * Try it with: "  the quick   brown fox  "  (extra spaces on purpose)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE     256
#define INITIAL_CAP 4

/* A growable array of owned strings. */
typedef struct {
    char  **items;   /* items[i] is a heap string that this struct owns */
    size_t  len;     /* how many words are stored                       */
    size_t  cap;     /* how many slots are allocated                    */
} WordList;

/* [P4] Start with a small allocated block. calloc = malloc + zero the
 * bytes. For pointer slots the zeroing isn't load-bearing (we overwrite
 * each slot before reading it) — but "fresh array, zeroed" is the habit:
 * for NUMBERS it very much is load-bearing. */
void wl_init(WordList *w) {
    w->items = calloc(INITIAL_CAP, sizeof *w->items);
    if (!w->items) { fprintf(stderr, "out of memory\n"); exit(1); }
    w->len = 0;
    w->cap = INITIAL_CAP;
}

/* [P3][P4] Append a COPY of word. Returns 1 on success, 0 on allocation
 * failure; on failure the list is unchanged. */
int wl_push(WordList *w, const char *word) {
    if (w->len == w->cap) {                     /* full -> grow */
        size_t ncap = w->cap * 2;
        char **tmp = realloc(w->items, ncap * sizeof *tmp);
        if (!tmp) return 0;                     /* old block still valid! */
        w->items = tmp;                         /* assign only after success */
        w->cap = ncap;
    }
    char *copy = strdup(word);                  /* private heap copy */
    if (!copy) return 0;
    w->items[w->len++] = copy;
    return 1;
}

/* [P5] Order matters: every owned string first, then the array of pointers. */
void wl_free(WordList *w) {
    for (size_t i = 0; i < w->len; i++) free(w->items[i]);
    free(w->items);
    w->items = NULL;
    w->len = w->cap = 0;
}

/* Find the index of a word, or -1. This is the "search by content" loop —
 * start at 0, walk to len, strcmp, return i the moment it matches.
 * This is the loop you were fighting with in morse. */
long wl_find(const WordList *w, const char *word) {
    for (size_t i = 0; i < w->len; i++)
        if (strcmp(w->items[i], word) == 0) return (long)i;
    return -1;
}

int main(void) {
    char line[MAXLINE];

    printf("Type a sentence: ");
    /* [P1] fgets returns NULL on EOF or error. Always check. */
    if (!fgets(line, sizeof line, stdin)) return 0;

    /* [P1] strcspn(line, "\r\n") = how many chars before the first \r or \n.
     *   - newline exists:        we overwrite it with '\0'
     *   - no newline (long line or last line of a file): strcspn == strlen,
     *     and we write '\0' over the EXISTING '\0'.
     * Both are in bounds. That is why this one line is the safe strip.
     * (Compare: line[strlen(line)-1] underflows on an empty line.) */
    line[strcspn(line, "\r\n")] = '\0';

    WordList w;
    wl_init(&w);

    /* [P2] Split in place. No character copying here: find the start of a
     * word, put '\0' where it ends, let strdup in wl_push make the copy. */
    char *p = line;
    while (*p) {
        while (*p == ' ') p++;              /* skip separators */
        if (!*p) break;                     /* only trailing spaces left */
        char *start = p;                    /* word starts here */
        while (*p && *p != ' ') p++;        /* walk to its end */
        if (*p) *p++ = '\0';                /* cut, then step past the separator */
        if (!wl_push(&w, start)) {
            fprintf(stderr, "out of memory\n");
            wl_free(&w);
            return 1;
        }
    }

    printf("\n%zu word(s):\n", w.len);
    for (size_t i = 0; i < w.len; i++)
        printf("  %zu. [%s] (%zu chars)\n", i + 1, w.items[i], strlen(w.items[i]));

    if (w.len > 0) {
        long idx = wl_find(&w, w.items[0]);
        printf("\nfirst word found again at index %ld\n", idx);
    }

    wl_free(&w);   /* [P5] ASan screams if we forget this */
    return 0;
}
