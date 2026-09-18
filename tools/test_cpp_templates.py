import os
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
TEMPLATE_ROOT = ROOT / "其它常见的题目" / "src"
FAILING_TEMPLATES = (
    "c_string_operations.cc",
    "digit_dp.cc",
    "graph_functional_graph_cycles.cc",
    "graph_max_flow_dinic.cc",
    "integer_conversion.cc",
    "interview_valid_sudoku.cc",
    "math_combinations.cc",
    "math_practice_snippets.cc",
    "number_theory_algorithms.cc",
    "sorting_algorithms_collection.cc",
    "tree_lowest_common_ancestor.cc",
)


def compile_and_run(source: str, *, run: bool = True) -> subprocess.CompletedProcess[str]:
    """Compile a C++ driver containing source and optionally execute it."""
    compiler = os.environ.get("CXX", "c++")
    with tempfile.TemporaryDirectory() as directory:
        temporary = Path(directory)
        driver = temporary / "driver.cc"
        binary = temporary / "driver"
        driver.write_text(source, encoding="utf-8")
        command = [
            compiler,
            "-std=c++17",
            "-Wall",
            "-Wextra",
            "-Wpedantic",
            str(driver),
            "-o",
            str(binary),
        ]
        compiled = subprocess.run(command, capture_output=True, text=True, check=False)
        if compiled.returncode != 0:
            raise AssertionError(
                f"C++ compilation failed\ncommand: {' '.join(command)}\n"
                f"stdout:\n{compiled.stdout}\nstderr:\n{compiled.stderr}"
            )
        if not run:
            return compiled
        executed = subprocess.run(
            [str(binary)], capture_output=True, text=True, check=False
        )
        if executed.returncode != 0:
            raise AssertionError(
                f"C++ driver failed with exit code {executed.returncode}\n"
                f"stdout:\n{executed.stdout}\nstderr:\n{executed.stderr}"
            )
        return executed


def include_driver(relative_path: str, assertions: str = "") -> str:
    """Return a driver that includes one repository source and appends assertions."""
    source = (TEMPLATE_ROOT / relative_path).as_posix()
    return f'#include "{source}"\n{assertions}\n'


class CppTemplateBehaviorTest(unittest.TestCase):
    def test_c_string_operations(self):
        compile_and_run(include_driver("c_string_operations.cc", r"""
#include <cassert>
int main() {
    char text[16] = "abcdef";
    cstring_ops::move(text + 2, text, 4);
    assert(cstring_ops::compare(text, "ababcd") == 0);
    char destination[16] = {};
    cstring_ops::copy_string(destination, "hello");
    cstring_ops::concatenate(destination, "!");
    assert(cstring_ops::length(destination) == 6);
    assert(cstring_ops::compare(destination, "hello!") == 0);
}
"""))

    def test_integer_conversion(self):
        compile_and_run(include_driver("integer_conversion.cc", r"""
#include <cassert>
#include <limits>
int main() {
    int value = 0;
    assert(integer_conversion::parse(" -2147483648 ", value));
    assert(value == std::numeric_limits<int>::min());
    assert(!integer_conversion::parse("12x", value));
    assert(!integer_conversion::parse("2147483648", value));
    assert(integer_conversion::format(-255, 16) == "-ff");
    assert(integer_conversion::format(10, 2) == "1010");
}
"""))

    def test_valid_sudoku(self):
        compile_and_run(include_driver("interview_valid_sudoku.cc", r"""
#include <cassert>
int main() {
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    board[0][0] = '5'; board[1][1] = '3'; board[4][4] = '7';
    assert(valid_sudoku(board));
    board[0][1] = '5';
    assert(!valid_sudoku(board));
}
"""))

    def test_sorting_algorithms(self):
        compile_and_run(include_driver("sorting_algorithms_collection.cc", r"""
#include <algorithm>
#include <cassert>
int main() {
    using Sort = void (*)(std::vector<int>&);
    const std::vector<Sort> sorts{
        sorting_algorithms::bubble_sort,
        sorting_algorithms::insertion_sort,
        sorting_algorithms::selection_sort,
        sorting_algorithms::shell_sort,
        sorting_algorithms::quick_sort,
        sorting_algorithms::merge_sort,
        sorting_algorithms::counting_sort,
        sorting_algorithms::radix_sort,
        sorting_algorithms::bucket_sort,
        sorting_algorithms::heap_sort,
    };
    for (Sort sort : sorts) {
        std::vector<int> values{5, 1, 3, 3, -2, 8, 0};
        auto expected = values;
        std::sort(expected.begin(), expected.end());
        sort(values);
        assert(values == expected);
        std::vector<int> empty;
        sort(empty);
        assert(empty.empty());
    }
}
"""))

    def test_combinations(self):
        compile_and_run(include_driver("math_combinations.cc", r"""
#include <cassert>
int main() {
    assert(combinatorics::choose(5, 2) == 10);
    assert(combinatorics::choose(3, 4) == 0);
    combinatorics::ModCombinations combinations(20, 1'000'000'007LL);
    assert(combinations.choose(10, 3) == 120);
    assert(combinatorics::lucas(10, 3, 7) == 1);
}
"""))

    def test_math_practice(self):
        compile_and_run(include_driver("math_practice_snippets.cc", r"""
#include <cassert>
int main() {
    assert(math_practice::is_prime(2));
    assert(!math_practice::is_prime(9));
    assert(math_practice::primes_up_to(10) == std::vector<int>({2, 3, 5, 7}));
    assert(math_practice::gcd(18, 24) == 6);
    assert(math_practice::lcm(6, 15) == 30);
    assert(math_practice::power(3, 4) == 81);
}
"""))

    def test_number_theory(self):
        compile_and_run(include_driver("number_theory_algorithms.cc", r"""
#include <cassert>
int main() {
    assert(number_theory::is_prime(97));
    assert(!number_theory::is_prime(9));
    assert(number_theory::primes_up_to(10) == std::vector<int>({2, 3, 5, 7}));
    assert(number_theory::prime_factors(84) == std::vector<int>({2, 2, 3, 7}));
    auto result = number_theory::extended_gcd(30, 18);
    assert(result.gcd == 6);
    assert(30 * result.x + 18 * result.y == result.gcd);
    assert(number_theory::mod_power(2, 10, 1'000'000'007) == 1024);
    assert(number_theory::combination_mod(5, 2, 1'000'000'007) == 10);
}
"""))

    def test_digit_dp(self):
        compile_and_run(include_driver("digit_dp.cc", r"""
#include <cassert>
int main() {
    assert(digit_dp::count_stepping_numbers("0", "21") == 13);
    assert(digit_dp::count_stepping_numbers("10", "15") == 2);
    assert(digit_dp::count_stepping_numbers("11", "11") == 0);
}
"""))

    def test_graph_cycles(self):
        compile_and_run(include_driver("graph_functional_graph_cycles.cc", r"""
#include <cassert>
int main() {
    assert(graph_cycles::shortest_undirected_cycle(
        4, {{0, 1}, {1, 2}, {2, 0}, {2, 3}}) == 3);
    assert(graph_cycles::shortest_undirected_cycle(
        4, {{0, 1}, {1, 2}, {2, 3}}) == -1);
    assert(graph_cycles::longest_directed_cycle({1, 2, 0, 2}) == 3);
    assert(graph_cycles::longest_directed_cycle({1, 2, -1}) == -1);
}
"""))

    def test_dinic(self):
        compile_and_run(include_driver("graph_max_flow_dinic.cc", r"""
#include <cassert>
int main() {
    Dinic flow(4);
    flow.add_edge(0, 1, 2); flow.add_edge(0, 2, 3);
    flow.add_edge(1, 2, 1); flow.add_edge(1, 3, 1);
    flow.add_edge(2, 3, 2);
    assert(flow.max_flow(0, 3) == 3);
    Dinic parallel(2);
    parallel.add_edge(0, 1, 2); parallel.add_edge(0, 1, 3);
    assert(parallel.max_flow(0, 1) == 5);
}
"""))

    def test_lowest_common_ancestor(self):
        compile_and_run(include_driver("tree_lowest_common_ancestor.cc", r"""
#include <cassert>
int main() {
    LowestCommonAncestor lca(7, {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    });
    assert(lca.query(3, 4) == 1);
    assert(lca.query(3, 5) == 0);
    assert(lca.query(2, 6) == 2);
    assert(lca.query(0, 6) == 0);
}
"""))


if __name__ == "__main__":
    unittest.main()
