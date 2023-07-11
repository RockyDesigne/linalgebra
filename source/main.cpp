#include <iostream>
#include <filesystem>
#include <cassert>

#include "Matrix.h"
#include "Timer.h"

int main() {

    namespace fs = std::filesystem;

    const fs::path filePath{"matrix.txt"};

    if (!fs::exists(filePath))
        assert("File not found!");

    std::ifstream file {filePath};

    if (!file.is_open())
        assert("Failed to open file!");

    auto nrOfMatrices{0u};

    file >> nrOfMatrices;

    Timer timer {};

    for (int i{0}; i < nrOfMatrices; ++i) {

        auto rows{0u}, cols{0u};

        file >> rows >> cols;

        if (rows < cols - 1)
            std::cout << "Sistemul este nedeterminat, fiindca matricea nu este patratica.\n";

        Matrix matrix{rows, cols};

        matrix.read_matrix_from_file(file);

        matrix.solve_system();

        std::cout << '\n';

    }

    std::cout << "Time: " << timer.elapsed() << '\n';

    file.close();

    return 0;
}