#pragma once

//------------------------------------------------------------------//

#include <ae_core.h>

#include <json/json.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

/// @brief For persisting an object.
class Persists
{
public:
    virtual ~Persists() = default;

    /// @brief Serializes the object into JSON format.
    /// @return
    virtual Json::Value toJson() const = 0;
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
