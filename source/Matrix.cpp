//
// Created by HORIA on 15.03.2023.
//
#include "Matrix.h"

Matrix::Matrix(Data rows, Data cols) : m_rows {rows}, m_cols {cols} {
    allocate_matrix();
    allocate_copy();
}

Matrix::~Matrix() {
    deallocate_matrix();
    deallocate_copy();
}

void Matrix::read_matrix_from_file(std::ifstream &file) {

    if (m_matrix)
        for (auto i{0u}; i < m_rows; ++i)
            for (auto j{0u}; j < m_cols; ++j)
                file >> (*m_matrix)[i][j];

}

void Matrix::print_matrix() const {
    if (m_matrix)
        for (auto &row : *m_matrix) {
            for (auto &element: row)
                std::cout << element << ' ';
            std::cout << '\n';
        }
}

void Matrix::solve_system() {

    while (m_pivot.first < m_rows && m_pivot.second < m_cols) {

        if (!select_pivot()) break;

        copy_matrix();

        divide_live_by_pivot((*m_matrix)[m_pivot.first], (*m_matrix)[m_pivot.first][m_pivot.second]);

        zero_out_below_pivot();

        calculate_elements_not_on_pivot_row_and_column();

        print_matrix();

        std::cout << std::endl;

        ++m_pivot.first;
        ++m_pivot.second;
    }

    get_solutions();

}

/*
* Function to select my pivot element
* if pivot is 0, then we have to swap the rows
* if after swapping rows pivot is still 0, then we have to swap the columns
* Try all possible combinations between row and col swaps
* @return true if pivot is not 0, false otherwise
*/
bool Matrix::select_pivot() {

    if (m_matrix) {

        if (!(*m_matrix)[m_pivot.first][m_pivot.second].is_null()) return true;

        //swap rows
        for (auto i{m_pivot.first}; i < m_rows - 1; ++i) {
            swap_row((*m_matrix)[m_pivot.first], (*m_matrix)[i + 1]);

            // after swapping rows, check if m_pivot is 0
            if (!(*m_matrix)[m_pivot.first][m_pivot.second].is_null()) return true;
            swap_row((*m_matrix)[i + 1], (*m_matrix)[m_pivot.first]);
        }

        // still 0, swap columns
        for (auto i{m_pivot.second}; i < m_rows - 1; ++i) {
            swap_cols(i);

            // after swapping columns, check if m_pivot is 0
            if (!(*m_matrix)[m_pivot.first][m_pivot.second].is_null()) {
                std::cout << 'C' << m_pivot.second + 1 << "->" << 'C' << i + 2 << '\n';
                return true;
            }
            swap_cols(i);
        }

        for (auto i{m_pivot.first}; i < m_rows - 1; ++i) {
            for (auto j{m_pivot.second}; j < m_cols - 1; ++j) {

                // swap rows
                swap_row((*m_matrix)[m_pivot.first], (*m_matrix)[i + 1]);

                // swap columns
                swap_cols(j);

                // check if m_pivot is nonzero
                if (!(*m_matrix)[m_pivot.first][m_pivot.second].is_null()) {
                    std::cout << 'C' << m_pivot.second + 1 << " -> " << 'C' << i + 2 << '\n';
                    return true;
                }

                // swap columns back
                swap_cols(j);

                // swap rows back
                swap_row((*m_matrix)[i + 1], (*m_matrix)[m_pivot.first]);
            }
        }
    }
    // still 0, return false
    return false;
}

void Matrix::calculate_elements_not_on_pivot_row_and_column() {

    if (m_matrix && m_copy) {

        for (auto i{0}; i < m_rows; ++i)
            for (auto j{0}; j < m_cols; ++j)
                if (i != m_pivot.first && j != m_pivot.second) {
                    auto first {(*m_copy)[m_pivot.first][m_pivot.second] * (*m_copy)[i][j]};
                    auto second {(*m_copy)[i][m_pivot.second] * (*m_copy)[m_pivot.first][j]};
                    auto res {first - second};
                    (*m_matrix)[i][j] = res;
                }
    }
}

void Matrix::copy_matrix() {

    if (m_matrix && m_copy) {
        for (auto i{0}; i < m_rows; ++i)
            for (auto j{0}; j < m_cols; ++j)
                (*m_copy)[i][j] = (*m_matrix)[i][j];
    }

}

void Matrix::zero_out_below_pivot() {
    if (m_matrix) {
        for (auto i{0}; i < m_rows; ++i)
            if (i != m_pivot.first)
                (*m_matrix)[i][m_pivot.second] = Fraction {0};
    }
}

void Matrix::get_solutions() {

    if (m_matrix) {
        auto var{'a'};
        for (auto i{0}, j{0}; i < m_rows; ++i, ++j) {

            auto size{m_cols - 1};
            auto answer{((*m_matrix)[i][size]) / (*m_matrix)[i][j]};

            std::cout << var++ << " = " << answer << std::endl;

        }
    }
}

void Matrix::swap_row(std::vector<Fraction> &row1, std::vector<Fraction> &row2) {
    for (auto i{0}; i < row1.size(); ++i)
        std::swap(row1[i], row2[i]);
}

void Matrix::swap_cols(uint32_t col) {
    for (auto i{0}; i < m_rows; ++i)
        std::swap((*m_matrix)[i][col], (*m_matrix)[i][col + 1]);
}

void Matrix::allocate_matrix() {
    m_matrix = new M (m_rows, std::vector<Fraction>(m_cols));
}

void Matrix::deallocate_matrix() {
    delete m_matrix;
}

void Matrix::allocate_copy() {
    m_copy = new M (m_rows, std::vector<Fraction> (m_cols));
}

void Matrix::deallocate_copy() {
    delete m_copy;
}

auto Matrix::divide_live_by_pivot(std::vector<Fraction>& line, Fraction pivot) -> void {

    for (auto& element : line) {
        auto fr {element};
        auto res {fr / pivot};
        element = res;
    }

}
