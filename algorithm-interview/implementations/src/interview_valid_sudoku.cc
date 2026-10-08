#include <array>
#include <cstddef>
#include <vector>

bool valid_sudoku(const std::vector<std::vector<char>>& board) {
    if (board.size() != 9) return false;
    std::array<std::array<bool, 9>, 9> rows{};
    std::array<std::array<bool, 9>, 9> columns{};
    std::array<std::array<bool, 9>, 9> boxes{};
    for (std::size_t row = 0; row < 9; ++row) {
        if (board[row].size() != 9) return false;
        for (std::size_t column = 0; column < 9; ++column) {
            const char cell = board[row][column];
            if (cell == '.') continue;
            if (cell < '1' || cell > '9') return false;
            const std::size_t digit = static_cast<std::size_t>(cell - '1');
            const std::size_t box = row / 3 * 3 + column / 3;
            if (rows[row][digit] || columns[column][digit] || boxes[box][digit]) return false;
            rows[row][digit] = columns[column][digit] = boxes[box][digit] = true;
        }
    }
    return true;
}
