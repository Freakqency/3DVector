#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;
class vec3d {
public:
    float x, y, z;
    vec3d()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    vec3d(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    vec3d(const vec3d& vec);
    void print();
    vec3d operator+(const vec3d& vec);
    vec3d& operator+=(const vec3d& vec);
    vec3d operator-(const vec3d& vec);
    vec3d& operator-=(const vec3d& vec);
    vec3d operator*(float value);
    vec3d& operator*=(float value);
    vec3d operator/(float value);
    vec3d& operator/=(float value);
    vec3d& operator=(const vec3d& vec);
    float dot_product(const vec3d& vec);
    vec3d cross_product(const vec3d& vec);
    float magnitude();
    float square();
    vec3d normalize();
};

vec3d::vec3d(const vec3d& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

void vec3d::print()
{
    cout << x << " " << y << " " << z << endl;
}
vec3d vec3d::operator+(const vec3d& vec)
{
    return vec3d(x + vec.x, y + vec.y, z + vec.z);
}
vec3d& vec3d::operator+=(const vec3d& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}
vec3d vec3d::operator-(const vec3d& vec)
{
    return vec3d(x - vec.x, y - vec.y, z - vec.z);
}
vec3d& vec3d::operator-=(const vec3d& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}
vec3d vec3d::operator*(float value)
{
    return vec3d(x * value, y * value, z * value);
}
vec3d& vec3d::operator*=(float value)
{
    x *= value;
    y *= value;
    z *= value;
    return *this;
}
vec3d vec3d::operator/(float value)
{
    assert(value != 0);
    return vec3d(x / value, y / value, z / value);
}
vec3d& vec3d::operator/=(float value)
{
    assert(value != 0);
    x /= value;
    y /= value;
    z /= value;
    return *this;
}
vec3d& vec3d::operator=(const vec3d& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}
float vec3d::dot_product(const vec3d& vec)
{
    return x * vec.x + vec.y * y + vec.z * z;
}
vec3d vec3d::cross_product(const vec3d& vec)
{
    float ni = y * vec.z - z * vec.y;
    float nj = z * vec.x - x * vec.z;
    float nk = x * vec.y - y * vec.x;
    return vec3d(ni, nj, nk);
}
float vec3d::magnitude()
{
    return sqrt(square());
}

float vec3d::square()
{
    return x * x + y * y + z * z;
}
vec3d vec3d::normalize()
{
    assert(magnitude() != 0);
    *this /= magnitude();
    return *this;
}

int main()
{
    vec3d a = vec3d(5, 10, 15);
    vec3d b = vec3d(20, 25, 30);
    vec3d c = a-b;
    c.print();
}
