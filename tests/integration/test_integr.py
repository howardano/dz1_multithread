import unittest
import subprocess
from subprocess import Popen, PIPE

def run_multiple_obj(expression):
    result = subprocess.run(["../../build/main", expression],
                            stdout=subprocess.PIPE, check=True)
    return result.stdout.split(' ')

def run_one_obj(expression):
    result = subprocess.run(["../../build/main", expression],
                            stdout=subprocess.PIPE, check=True)
    return result.stdout


class TestCalculator(unittest.TestCase):
    def test_lower_bound_(self):
        program_path = "../../build/main"

        p = Popen([program_path], stdout=PIPE, stdin=PIPE)

        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")
        p.stdin.write(b"2\n")
        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")
        p.stdin.write(b"2\n")

        p.stdin.flush()
        result = p.stdout.readline().strip()

        self.assertEqual(result, b"2")

    def test_upper_bound_(self):
        program_path = "../../build/main"

        p = Popen([program_path], stdout=PIPE, stdin=PIPE)

        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")
        p.stdin.write(b"2\n")
        p.stdin.write(b"3\n")
        p.stdin.write(b"2\n")
        p.stdin.write(b"2\n")

        p.stdin.flush()

        result = p.stdout.readline().strip()
        self.assertEqual(result, b"3")

    def test_binary_search_(self):
        program_path = "../../build/main"

        p = Popen([program_path], stdout=PIPE, stdin=PIPE)

        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")
        p.stdin.write(b"2\n")
        p.stdin.write(b"3\n")
        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")

        p.stdin.flush()

        result = p.stdout.readline().strip()
        self.assertEqual(result, b"1")

    def test_equal_range_(self):
        program_path = "../../build/main"

        p = Popen([program_path], stdout=PIPE, stdin=PIPE)

        p.stdin.write(b"3\n")
        p.stdin.write(b"1\n")
        p.stdin.write(b"2\n")
        p.stdin.write(b"3\n")
        p.stdin.write(b"4\n")
        p.stdin.write(b"2\n")

        p.stdin.flush()

        result = p.stdout.readline().strip().split()
        self.assertEqual(result[0], b"2")
        self.assertEqual(result[1], b"3")

if __name__ == "__main__":
    unittest.main()