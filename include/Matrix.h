//
// Created by HORIA on 15.03.2023.
//

#ifndef LINALGEBRA_MATRIX_H
#define LINALGEBRA_MATRIX_H

#include "Fraction.h"

#include <iostream>
#include <vector>
#include <fstream>

class Matrix {
public:
    using M = std::vector<std::vector<Fraction>>;
    using Data = uint32_t;
    using Pivot = std::pair<uint32_t, uint32_t>;

    Matrix(Data rows, Data cols);

    ~Matrix();

    void read_matrix_from_file(std::ifstream& file);

    void print_matrix() const;

    void solve_system();

private:

    M* m_matrix {};
    M* m_copy {};
    Data m_rows {};
    Data m_cols {};
    Pivot m_pivot {};

    bool select_pivot();

    void calculate_elements_not_on_pivot_row_and_column();

    void copy_matrix();

    void zero_out_below_pivot();

    void get_solutions();

    static void swap_row(std::vector<Fraction>& row1, std::vector<Fraction>& row2);

    static auto divide_live_by_pivot(std::vector<Fraction>& line, Fraction pivot) -> void;

    void swap_cols(uint32_t col);

    void allocate_matrix();

    void deallocate_matrix();

    void allocate_copy();

    void deallocate_copy();

};

#endif //LINALGEBRA_MATRIX_H
