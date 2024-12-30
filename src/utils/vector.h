#pragma once

class Vector2
{
public:
    Vector2(float x, float y) :
        x(x), y(y) {};
        
    ~Vector2() = default;

public:
    float x;
    float y;
};