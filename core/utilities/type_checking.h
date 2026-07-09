#pragma once

#include <ae_core.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

/// @brief The current state of this project expects there to be only one window.
namespace TypeChecking
{
    /// @brief Checks to see if a type can be converted from TypeA to TypeB.
    /// @tparam TypeA
    /// @tparam TypeB
    /// @param value The value to check if it can be down or up casted to TypeA.
    /// @return
    template <typename TypeA, typename TypeB>
    static bool isType(TypeB value)
    {
        return dynamic_cast<TypeA>(value) != nullptr;
    }
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
