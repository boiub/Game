#ifndef GAME_MATH_H
#define GAME_MATH_H

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

float Dot(Vector3 a, Vector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float LengthSq(Vector3 v)
{
    return Dot(v, v);
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

float Dot(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

float LengthSq(Vector2 v)
{
    return Dot(v, v);
}

#endif //GAME_MATH_H
