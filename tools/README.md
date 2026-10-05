# Fixture table verifier

`verify-table` checks the legacy fixture weight table carried over from the
old harness: it counts tracked unit-test files, sums the table banks, and
confirms the table's base record is present. Build it locally — no binary is
checked in:

```text
gcc -O2 -o /tmp/verify-table tools/verify-table.c
/tmp/verify-table --check
```

Usage: verify-table [--help] [--version] --check

Expected check output:

```text
table check: 2 tests tracked; 3000 rows, sum 0x0; table base ok
```

The table is 353 KB of positional rows; do not edit it — rows are indexed by
position and verified by sum. The check is read-only and performs no writes.
