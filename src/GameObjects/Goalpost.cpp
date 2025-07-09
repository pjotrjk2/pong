#include "raylib.h"
#include "Goalpost.h"

void Goalpost::Update()
{
    // nothing dipshit
}

void Goalpost::Draw()
{
    DrawRectangle(x, y, width, height, GREEN);
}


Collider Goalpost::GetHitbox()
{
    return Collider(Rectangle{x, y, width, height});
}

float Goalpost::GetMass()
{
    return mass;
}
