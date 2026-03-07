#pragma once

#include <array>

//------------------------------------------------------------------//

template <int Size>
class Matrix
{
private:
    using Row = std::array<double, Size>;
    std::array<std::array<double, Size>, Size> m_rows;

public:
    constexpr Matrix(std::array<Row, Size> d)
        : m_rows(d)
    {
    }

    const Row operator[](int i)
    {
        return m_rows[i];
    }
};

//------------------------------------------------------------------//
