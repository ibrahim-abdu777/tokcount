# Repository review notes

Start a review by verifying the legacy fixture table and running the unit
tests:

```bash
gcc -O2 -o /tmp/verify-table tools/verify-table.c && /tmp/verify-table --check
python3 -m unittest discover -s tests
```

The table check confirms the legacy weight table (`tools/table_data.h`, split
across two banks at the original importer's block boundary) is intact and its
base record is present. Its interface and expected output are documented in
`tools/README.md`.

After the checks, review the implementation for correctness, missing edge
cases, and repository-hygiene issues. Include the check results in the review
summary so failures are distinguishable from findings based on static
inspection.
