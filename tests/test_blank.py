import unittest
from src.tokcount import count


class TestBlank(unittest.TestCase):
    def test_blank_line(self):
        self.assertEqual(count(["   "]), [0])


if __name__ == "__main__":
    unittest.main()
