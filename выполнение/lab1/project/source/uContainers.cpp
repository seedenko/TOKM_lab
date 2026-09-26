//---------------------------------------------------------------------------
#include <cstdlib>
#include <cmath>

#pragma hdrstop
#include "uContainers.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

static inline float rand01()
{
    return (float)rand() / (float)RAND_MAX;
}

// 1. Равномерное распределение в кубе 1024x1024x1024 (от -511 до 511)
Point3D generatePointForCube(float size)
{
    Point3D p;
    p.x = (rand01() - 0.5f) * size;
    p.y = (rand01() - 0.5f) * size;
    p.z = (rand01() - 0.5f) * size;
    return p;
}

// 2. Равномерное распределение в объеме шара
Point3D generatePointForSphere(float radius)
{
    Point3D p;
    float phi = 2.0f * M_PI * rand01();
    float cosTheta = 2.0f * rand01() - 1.0f;
    float sinTheta = sqrtf(1.0f - cosTheta * cosTheta);
    // Для равномерной объемной плотности радиус пропорционален кубическому корню
    float r = radius * powf(rand01(), 1.0f / 3.0f);

    p.x = r * sinTheta * cosf(phi);
    p.y = r * sinTheta * sinf(phi);
    p.z = r * cosTheta;
    return p;
}

// 3. Равномерное распределение на поверхности сферы
Point3D generatePointForSphereSurface(float radius)
{
    Point3D p;
    float phi = 2.0f * M_PI * rand01();
    float cosTheta = 2.0f * rand01() - 1.0f;
    float sinTheta = sqrtf(1.0f - cosTheta * cosTheta);

    p.x = radius * sinTheta * cosf(phi);
    p.y = radius * sinTheta * sinf(phi);
    p.z = radius * cosTheta;
    return p;
}

// 4. Равномерное распределение в объеме цилиндра
Point3D generatePointForCylinder(float radius, float height)
{
    Point3D p;
    float phi = 2.0f * M_PI * rand01();
    // Для равномерной плотности по площади сечения r пропорционален корню
    float r = radius * sqrtf(rand01());

    p.x = r * cosf(phi);
    p.y = (rand01() - 0.5f) * height;
    p.z = r * sinf(phi);
    return p;
}

// 5. Равномерное распределение на поверхности цилиндра
Point3D generatePointForCylinderSurface(float radius, float height)
{
    Point3D p;
    float phi = 2.0f * M_PI * rand01();

    p.x = radius * cosf(phi);
    p.y = (rand01() - 0.5f) * height;
    p.z = radius * sinf(phi);
    return p;
}

// 6. Равномерное распределение в объеме конуса
Point3D generatePointForCone(float radius, float height)
{
    Point3D p;
    float h = rand01(); // Высота от основания (0) к вершине (1)
    float currentRadius = radius * (1.0f - h);
    float r = currentRadius * sqrtf(rand01());
    float phi = 2.0f * M_PI * rand01();

    p.x = r * cosf(phi);
    p.y = (h - 0.5f) * height;
    p.z = r * sinf(phi);
    return p;
}
