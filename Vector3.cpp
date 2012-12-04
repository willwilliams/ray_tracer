#include "Vector3.h"

Vector3::Vector3(precision xi, precision yi, precision zi) :
x(xi), y(yi), z(zi) {
}

void Vector3::negateVector()
{
    x = -x;
    y = -y;
    z = -z;
}

precision Vector3::sqrMagnitude()
{
    return (x * x + y * y + z * z);
}

precision Vector3::magnitude()
{
    return prec_sqrt(x * x + y * y + z * z);
}

void Vector3::normalise()
{
	precision mag = magnitude();
    if (mag!= 0) {
        x = x / mag;
        y = y / mag;
        z = z / mag;
    }
}

Vector3 Vector3::componentProduct(const Vector3& vec)
{
    return Vector3(x * vec.x, y * vec.y, z * vec.z);
}

void Vector3::componentProductApply(const Vector3& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
}

precision Vector3::scalarProduct(const Vector3& vec)
{
    return ((x * vec.x) + (y * vec.y) + (z * vec.z));
}

Vector3 Vector3::vectorProduct(const Vector3& vec)
{
    return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y
        - y * vec.x);
}

precision Vector3::angleBetween(Vector3& vec2)
{
    return acos(scalarProduct(vec2) / (magnitude()
        * vec2.magnitude()));
}