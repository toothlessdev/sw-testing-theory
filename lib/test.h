#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    const char *green;
    const char *red;
    const char *reset;
} ColorPalette;
typedef struct {
    int passed;
    int failed;
} TestStats;

ColorPalette colors = {.green = "\x1b[32m", .red = "\x1b[31m", .reset = "\x1b[0m"};
TestStats stats = {0, 0};

#define expect(cond)                                                                        \
    do {                                                                                    \
        if (cond) {                                                                         \
            printf("  %s✔ PASS%s\n", colors.green, colors.reset);                           \
            stats.passed++;                                                                 \
        }                                                                                   \
        else {                                                                              \
            printf("  %s✖ FAIL%s (%s:%d)\n", colors.red, colors.reset, __FILE__, __LINE__); \
            stats.failed++;                                                                 \
        }                                                                                   \
    } while (0)

#define test(desc, block)                       \
    do {                                        \
        printf("\nTest Case : [ %s ]\n", desc); \
        block                                   \
            printf("\n");                       \
    } while (0)

#define describe(name, block)                                   \
    do {                                                        \
        printf("\n%s%s%s\n", colors.green, name, colors.reset); \
        block                                                   \
    } while (0)

#endif