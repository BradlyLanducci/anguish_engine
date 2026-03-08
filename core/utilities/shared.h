#pragma once

#include <cstdint>

#include <objects/object.h>

//------------------------------------------------------------------//

template <typename Type1, typename Type2>
concept not_same_as = !std::same_as<Type1, Type2>;

template <not_same_as<Object> ValueType>
using Shared = std::shared_ptr<ValueType>;

//------------------------------------------------------------------//
