import unittest
from src.tokcount import count


class TestCount(unittest.TestCase):
    def test_counts_tokens(self):
        self.assertEqual(count(["a b c", "d"]), [3, 1])


if __name__ == "__main__":
    unittest.main()
