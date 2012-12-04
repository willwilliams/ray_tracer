#pragma once
#include "Precision.h"
#include "Vector3.h"
#include<math.h>
#include<vector>


class Camera
{
public:
	Camera(const Vector3& o, const Vector3& up, const Vector3& d, int nx, int ny, precision alpha_x, precision alpha_y) :
	  origin(o), up_vector(up), direction(d), nx(nx), ny(ny), alpha_x(alpha_x), alpha_y(alpha_y)
	{
		// Calculate pixel directions
		h = (direction % up_vector);
		h.normalise();
		h = h * ((2 * tan(0.5 * alpha_x))/nx);

		v = h % d;
		v.normalise();
		v = v * ((2 * tan(0.5 * alpha_y))/ny);
	}

	// Calculate the direction of a ray given the coordinates and current setup
	Vector3 findDirection(int i, int j)
	{
		Vector3 result = direction + h*(0.5 *nx - i) + v*(0.5*ny - j);
		result.normalise();
		return result;
	}

	int getNx()
	{
		return nx;
	}

	int getNy()
	{
		return ny;
	}

	Vector3 getCameraOrigin()
	{
		return origin;
	}

private:
	// Camera Origin "o"
	Vector3 origin;

	// Camera Normalised Up Vector"u"
	Vector3 up_vector;

	// Camera Direction "d
	Vector3 direction;

	// Screen Resolution
	int nx, ny;

	// Field of view
	precision alpha_x, alpha_y;

	// Single Pixel Directions
	Vector3 h, v;
};