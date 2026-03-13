#pragma once

//------------------------------------------------------------------//

#include <objects/object.h>

#include <cstdint>

//------------------------------------------------------------------//

/*
    We only want shared objects to be considered for non objects.
    This isn't a design pattern I want to encourage throughout, but
    it's useful for things that are not objects that I'd prefer to
    not have to be managed.
*/
template <typename Type1, typename Type2>
concept not_same_as = !std::same_as<Type1, Type2>;

template <not_same_as<Object> ValueType>
using Shared = std::shared_ptr<ValueType>;

//------------------------------------------------------------------//
