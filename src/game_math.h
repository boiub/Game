#ifndef GAME_MATH_H
#define GAME_MATH_H

#include <algorithm>
#include <math.h>

#include "raylib.h"

// Vector3

static inline Vector3 operator+(Vector3 a, Vector3 b)
{
    Vector3 rtn;

    rtn.x = a.x + b.x;
    rtn.y = a.y + b.y;
    rtn.z = a.z + b.z;

    return rtn;
}

static inline Vector3 operator-(Vector3 a, Vector3 b)
{
    Vector3 rtn;

    rtn.x = a.x - b.x;
    rtn.y = a.y - b.y;
    rtn.z = a.z - b.z;

    return rtn;
}

static inline Vector3 operator*(float s, Vector3 v)
{
    Vector3 rtn;

    rtn.x = s * v.x;
    rtn.y = s * v.y;
    rtn.z = s * v.z;

    return rtn;
}

static inline Vector3 operator*(Vector3 v, float s)
{
    return s * v;
}

static inline Vector3& operator+=(Vector3& a, Vector3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

static inline Vector3& operator-=(Vector3& a, Vector3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;

    return a;
}

static inline Vector3& operator*=(Vector3& a, float s)
{
    a.x *= s;
    a.y *= s;
    a.z *= s;

    return a;
}

static inline float Dot(Vector3 a, Vector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float LengthSq(Vector3 v)
{
    return Dot(v, v);
}

static inline Vector3 Min(Vector3 a, Vector3 b)
{
    Vector3 rtn;

    rtn.x = std::min(a.x, b.x);
    rtn.y = std::min(a.y, b.y);
    rtn.z = std::min(a.z, b.z);

    return rtn;
}

static inline Vector3 Max(Vector3 a, Vector3 b)
{
    Vector3 rtn;

    rtn.x = std::max(a.x, b.x);
    rtn.y = std::max(a.y, b.y);
    rtn.z = std::max(a.z, b.z);

    return rtn;
}

/** More expensive than LengthSq, use that instead if possible */
float Length(Vector3 v)
{
    return sqrtf(LengthSq(v));
}


// Vector2

static inline Vector2 operator+(Vector2 a, Vector2 b)
{
    Vector2 rtn;

    rtn.x = a.x + b.x;
    rtn.y = a.y + b.y;

    return rtn;
}

static inline Vector2 operator-(Vector2 a, Vector2 b)
{
    Vector2 rtn;

    rtn.x = a.x - b.x;
    rtn.y = a.y - b.y;

    return rtn;
}

static inline Vector2 operator*(float s, Vector2 v)
{
    Vector2 rtn;

    rtn.x = s * v.x;
    rtn.y = s * v.y;

    return rtn;
}

static inline Vector2 operator*(Vector2 v, float s)
{
    return s * v;
}

static inline Vector2& operator+=(Vector2& a, Vector2 b)
{
    a.x += b.x;
    a.y += b.y;

    return a;
}

static inline Vector2& operator-=(Vector2& a, Vector2 b)
{
    a.x -= b.x;
    a.y -= b.y;

    return a;
}

static inline Vector2& operator*=(Vector2& a, float s)
{
    a.x *= s;
    a.y *= s;

    return a;
}

static inline float Dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

static inline float LengthSq(Vector2 v)
{
    return Dot(v, v);
}

/** More expensive than LengthSq, use that instead if possible */
static inline float Length(Vector2 v)
{
    return sqrtf(LengthSq(v));
}

static inline Vector2 Min(Vector2 a, Vector2 b)
{
    Vector2 rtn;

    rtn.x = std::min(a.x, b.x);
    rtn.y = std::min(a.y, b.y);

    return rtn;
}

static inline Vector2 Max(Vector2 a, Vector2 b)
{
    Vector2 rtn;

    rtn.x = std::min(a.x, b.x);
    rtn.y = std::min(a.y, b.y);

    return rtn;
}

// Rectangle

static inline Vector2 MinCorner(Rectangle r)
{
    return Vector2 { r.x, r.y };
}

static inline Vector2 MaxCorner(Rectangle r)
{
    return Vector2 { r.x + r.width, r.y + r.height};
}

static inline Vector2 Center(Rectangle rect)
{
    return Vector2 { rect.x + 0.5f * rect.width, rect.y + 0.5f * rect.height };
}

#endif //GAME_MATH_H
