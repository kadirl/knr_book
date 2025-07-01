import subprocess
import random
from filecmp import demo


EXERCISE = 'exercise_1_8'
TESTS = 100
SIZE = 100


def compile():
    compile_cmd = ['gcc', EXERCISE + '.c', '-o', EXERCISE]

    result = subprocess.run(
        compile_cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)

    if result.returncode != 0:
        print("Compilation failed")
        print(result.stderr.decode())
        exit(1)
    else:
        print("Compiled successfully")


def generate_random_input(length=100):
    chars = ['a', 'b', ' ', '\t', '\n', 'x', 'y']
    return ''.join(random.choice(chars) for _ in range(length))


def expected_counts(input_str):
    return (f"blanks: {input_str.count(' ')}\n"
        f"tabs: {input_str.count(chr(9))}\n"
        f"newlines: {input_str.count(chr(10))}")


def run_test_case(input_data):
    run_cmd = ['./' + EXERCISE]

    result = subprocess.run(
        run_cmd,
        input=input_data.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    # check if no runtime error occured
    if result.returncode != 0:
        print("Runtime error.")
        print(result.stderr.decode())
        exit(1)

    # get expected & actual outputs
    expected_output = expected_counts(input_data)
    actual_output = result.stdout.decode()

    # output & compare
    # print(f"Input: {input_data}")
    print(f"Expected output: \n{expected_output}")
    print(f"Actual output: \n{actual_output}")

    if actual_output != expected_output:
        print("Test failed.")
        return False
    else:
        print("Test successfull.")
        return True


if __name__ == "__main__":
    compile()

    count = 0
    print(f"Running {TESTS} tests for {EXERCISE}.\n")

    for test in range(TESTS):
        print(f"Test #{test + 1}:")
        random_input = generate_random_input(SIZE)
        count += run_test_case(random_input)
        print()

    print("Test finished.")
    print(f"{count}/{TESTS} cases passed successfully.")
