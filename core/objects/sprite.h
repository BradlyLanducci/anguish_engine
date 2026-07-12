#pragma once

//------------------------------------------------------------------//

#include <objects/rendered_object.h>
#include <texture/texture.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class Sprite : public RenderedObject
{
public:
    void setEnabled(bool enabled);

private:
    void draw() override;
    bool m_enabled{ true };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
