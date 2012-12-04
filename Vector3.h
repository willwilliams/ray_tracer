#pragma once
#include "Precision.h"
#include <iostream>

using namespace std;

/**
 * Mathematical Vector in 3d
 */
class Vector3 {

public:
    Vector3(precision xi = 0, precision yi = 0, precision zi = 0);

	// Values for the x, y and z compondents
	precision x;
	precision y;
	precision z;

	// Unary negation
	void negateVector();

	// Square Magnitude
	precision sqrMagnitude();

	// Magnitude
    precision magnitude();

	// Normalise
    void normalise();

	// Component Product
    Vector3 componentProduct(const Vector3& vec);

	// Set Component Product
    void componentProductApply(const Vector3& vec);

	// Scalar Product
    precision scalarProduct(const Vector3& vec);

	// Vector Product
    Vector3 vectorProduct(const Vector3& vec);

	// Angle between this vector and given vector
    precision angleBetween(Vector3& vec2);

	/**
	 * Operator Overrides
	 */

	/* 
	
	* OPERATOR

	*/

	// Times through all components
	void operator*=(const precision& multiple) {
		x *= multiple;
		y *= multiple;
		z *= multiple;
	}

	// Times through all components (Vector return)
	Vector3 operator*(const precision& multiple) {
		return Vector3(multiple * x, multiple * y, multiple * z);
	}

	// Scalar Product
	precision operator*(const Vector3& vec) {
		return x * vec.x + y * vec.y + z * vec.z;
	}

	/* 
	
	% OPERATOR

	*/

	// Vector product
	Vector3 operator%(const Vector3& vec) const {
		return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y
				- y * vec.x);
	}

	/* 
	
	+ OPERATOR

	*/

	// Add to all components from another vector
	void operator+=(const Vector3& vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	// Add components
	Vector3 operator+(const Vector3& vec) {
		return Vector3(vec.x + x, vec.y + y, vec.z + z);
	}

	// Add constant to all components
	void operator+=(const precision& val) {
		x += val;
		y += val;
		z += val;
	}

	// Add constant to all components (Vector)
	Vector3 operator+(const precision& val) {
		return Vector3(x + val, y + val, z + val);
	}

	// Subtract another vector from this vector
	void operator-=(const Vector3& vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}

	// Subtract another vector from this vector (Vector)
	Vector3 operator-(const Vector3& vec) {
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}

	// Subtract constant from this vector (Vector)
	void operator-=(const precision& val) {
		x -= val;
		y -= val;
		z -= val;
	}

	// Subtract constant from this vector (Vector)
	Vector3 operator-(const precision& val) {
		return Vector3(x - val, y - val, z - val);
	}

	/* 
	
	<< OPERATOR

	*/

	// Print out the vector's contents
	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
		os << "Vector:-\n[" << vec.x << ", " << vec.y << ", " << vec.z << "]\n";
		return os;
	}
};