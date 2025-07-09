#include <raylib.h>
#include "Frame.h"

void Frame::Update()
{
    // nothing dipshit
}

void Frame::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}


Collider Frame::GetHitbox()
{
    return Collider(Rectangle{x, y, width, height});
}

float Frame::GetMass()
{
    return mass;
}
