# Tokcount

A small Python utility for counting delimiter-separated tokens per line,
plus a verifier for the legacy fixture weight table carried over from the
old harness.

## Review scope

Please review `src/tokcount.py` for correctness, maintainability, and edge
cases. Run `python3 -m unittest discover -s tests` to verify behavior, and
follow `AGENTS.md` for the table check.
