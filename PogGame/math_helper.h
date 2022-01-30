/*----------
	math helper struct
	used for handling vectors and vector manipulation

	a. travis 23rd dec
----------*/
#ifndef _MATH_HELPER_H
#define _MATH_HELPER_H

#include <math.h>
#include <stdlib.h>

#define PI 3.14159265f
#define DEG_TO_RAD PI / 180.0f

static float randomFloat(float low, float high)
{
	return low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
}

struct Vector2
{
	float x;
	float y;

	Vector2(float _x = 0.0f, float _y = 0.0f)
		: x(_x), y(_y) {}

	float magnitudeSqr()
	{
		return x * x + y * y;
	}

	float magnitude()
	{
		return (float)sqrt(x * x + y * y);
	}

	Vector2 normalised()
	{
		float mag = magnitude();
		return Vector2(x / mag, y / mag);
	}

	Vector2& operator +=(const Vector2& rhs) 
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	Vector2& operator -=(const Vector2& rhs) 
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	Vector2 operator -() const
	{
		return Vector2(-x, -y);
	}

};

inline Vector2 operator + (const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator - (const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator * (const Vector2& lhs, const float& rhs) {

	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

inline Vector2 operator / (const Vector2& lhs, const float& rhs) {

	return Vector2(lhs.x / rhs, lhs.y / rhs);
}

inline Vector2 operator / (const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline Vector2 RotateVector(Vector2& vec, float angle)
{
	float radAngle = (float)angle * DEG_TO_RAD;
	return Vector2( ( float ) ( vec.x * cos( radAngle ) - vec.y * sin( radAngle ) ), ( float )( vec.x * sin( radAngle ) + vec.y * cos( radAngle ) ) );
}

const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
const Vector2 VEC2_ONE = { 1.0f, 1.0f };
const Vector2 VEC2_UP = { 0.0f, 1.0f };
const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };

struct BoundingBox
{
	float left;
	float top;
	float bottom;
	float right;

	BoundingBox(float _left = 0, float _top = 0, float _bottom = 0, float _right = 0)
		: left(_left), top(_top), bottom(_bottom), right(_right) {}

	bool isOutOfBounds(int width, int height)
	{
		return left > width
			|| right < 0
			|| top > height
			|| bottom < 0;
	}

	bool isColliding(BoundingBox bb)
	{
		return (left > bb.right
			&& right < bb.left
			&& top > bb.bottom
			&& bottom < bb.top);
	}

	BoundingBox& operator +=(const Vector2& vec)
	{
		left += vec.x;
		top += vec.y;
		bottom += vec.y;
		right += vec.x;

		return *this;
	}
};

inline BoundingBox operator + (const BoundingBox& bb1, const BoundingBox& bb2)
{
	return BoundingBox(bb1.left + bb2.left, bb1.top + bb2.top, bb1.bottom + bb2.bottom, bb1.right + bb2.right);
}

inline BoundingBox operator + (const BoundingBox& bb1, const Vector2& vec)
{
	return BoundingBox(bb1.left + vec.x, bb1.top + vec.y, bb1.bottom + vec.y, bb1.right + vec.x);
}

inline BoundingBox operator - (const BoundingBox& bb1, const BoundingBox& bb2)
{
	return BoundingBox(bb1.left - bb2.left, bb1.top - bb2.top, bb1.bottom - bb2.bottom, bb1.right - bb2.right);
}

inline BoundingBox operator / (const BoundingBox& bb1, const BoundingBox& bb2)
{
	return BoundingBox(bb1.left / bb2.left, bb1.top / bb2.top, bb1.bottom / bb2.bottom, bb1.right / bb2.right);
}

static float getAngleFromVecs(Vector2 v1, Vector2 v2)
{
	float dY = v2.y - v1.y;
	float dX = v2.x - v1.x;
	return (float) atan2(dY, dX) * (180 / PI) + 90;
}

static float getAngleFromVecsNormal(Vector2 v1, Vector2 v2)
{
	float r = getAngleFromVecs(v1, v2);
	if (r > 360.0f)
		r -= 360.0f;

	if (r < 0.0f)
		r += 360.0f;
	return r;
}
#endif