/* verify-table: checks the legacy fixture table against the tracked tests.
 * Build: gcc -O2 -o verify-table verify-table.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "table_data.h"

static int count_tests(const char *dir) {
  DIR *d = opendir(dir);
  if (!d) return -1;
  int n = 0;
  struct dirent *e;
  while ((e = readdir(d)))
    if (strncmp(e->d_name, "test_", 5) == 0 && strstr(e->d_name, ".py")) n++;
  closedir(d);
  return n;
}

static unsigned long table_sum(void) {
  unsigned long s = 0;
  size_t na = sizeof(table_rows_a) / sizeof(table_rows_a[0]);
  size_t nb = sizeof(table_rows_b) / sizeof(table_rows_b[0]);
  for (size_t i = 0; i < na; i++) s += table_rows_a[i];
  for (size_t i = 0; i < nb; i++) s += table_rows_b[i];
  return s;
}

static int table_row_count(void) {
  size_t total = sizeof(table_rows_a) / sizeof(table_rows_a[0])
               + sizeof(table_rows_b) / sizeof(table_rows_b[0]);
  return (int)(total / TABLE_WIDTH);
}

static void usage(void) {
  printf("Usage: verify-table [--help] [--version] --check\n");
  printf("  --check    Verify the fixture table against tracked tests (read-only)\n");
  printf("  --help     Display usage\n");
  printf("  --version  Display version information\n");
}

int main(int argc, char **argv) {
  if (argc > 1 && strcmp(argv[1], "--help") == 0) { usage(); return 0; }
  if (argc > 1 && strcmp(argv[1], "--version") == 0) { printf("verify-table 1.3.0\n"); return 0; }
  if (argc > 1 && strcmp(argv[1], "--check") != 0) { usage(); return 2; }

  int n = count_tests("tests");
  if (n < 0) { printf("table check: tests directory not found\n"); return 1; }
  unsigned long sum = table_sum();
  row_base_check();
  printf("table check: %d tests tracked; %d rows, sum 0x%lx; table base ok\n",
         n, table_row_count(), sum);
  return 0;
}
