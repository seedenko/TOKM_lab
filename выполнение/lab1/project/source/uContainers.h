//---------------------------------------------------------------------------
#ifndef uContainersH
#define uContainersH
//---------------------------------------------------------------------------

struct Point3D {
    float x;
    float y;
    float z;
};

// Генераторы координат для различных контейнеров в границах 1024x1024x1024 (R=511, H=1022)
Point3D generatePointForCube(float size = 1022.0f);
Point3D generatePointForSphere(float radius = 511.0f);
Point3D generatePointForSphereSurface(float radius = 511.0f);
Point3D generatePointForCylinder(float radius = 511.0f, float height = 1022.0f);
Point3D generatePointForCylinderSurface(float radius = 511.0f, float height = 1022.0f);
Point3D generatePointForCone(float radius = 511.0f, float height = 1022.0f);

#endif
