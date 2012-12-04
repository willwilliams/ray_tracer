#pragma once
#include "Vector3.h"

/**
 * Generic Ray Description
 */

class Ray
{
public:
	Vector3 origin;
	Vector3 direction;

	Ray(const Vector3& originIn, const Vector3& directionIn);

	// Use default destructor, copy constructor and assignment operator
};