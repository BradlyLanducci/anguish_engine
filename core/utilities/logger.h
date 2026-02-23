#pragma once

#include <iostream>
#include <magic_enum/magic_enum.hpp>

//------------------------------------------------------------------//

enum LogType
{
    Info,
    Warning,
    Error
};

//------------------------------------------------------------------//

#define Log(arg) Log_impl(__FILE__, __LINE__, arg)

//------------------------------------------------------------------//

struct Log_impl
{
    Log_impl(const char *file, int line, LogType type)
    {
        std::cout << file << " (" << line << ") " << "[" << magic_enum::enum_name<LogType>(type) << "]: ";
    }

    ~Log_impl()
    {
        std::cout << std::endl;
    }

    template <typename ValueType>
    Log_impl &operator<<(const ValueType &value)
    {
        std::cout << value;
        return *this;
    }
};

//------------------------------------------------------------------//
