"""Count delimiter-separated tokens per line."""


def count(lines, sep=" "):
    return [len([t for t in line.split(sep) if t]) for line in lines]


def count_file(path, sep=" "):
    with open(path, "r", encoding="utf-8", errors="replace") as handle:
        return count(handle, sep)
