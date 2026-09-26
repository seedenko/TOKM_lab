//---------------------------------------------------------------------------

#include <cstdlib>
#include <cmath>

#pragma hdrstop

#include "uContainers.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
float* generatePointsForCube()
{
	float* coords = new float[3];
	float min = -0.5;
	float max = 0.5;

	for (int i = 0; i < 3; ++i) {
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = max - min;
		float r = random * diff;
		coords[i] = min + r;
	}
	return coords;
}

//---------------------------------------------------------------------------
float* generatePointsForSphereSurface()
{
	float* coords = new float[3];
	float r = 0.5;
	float theta = (((float)rand()) / (float)RAND_MAX) * 2.0 * M_PI;
	float phi = (((float)rand()) / (float)RAND_MAX) * M_PI;

	coords[0] = r * sin(phi) * cos(theta);
	coords[1] = r * sin(phi) * sin(theta);
	coords[2] = r * cos(phi);


	return coords;
}

//---------------------------------------------------------------------------
float* generatePointsForSphere()
{
	float* coords = new float[3];
	float random = ((float)rand()) / (float)RAND_MAX;
	float r = -0.5 + random;

	float theta = (((float)rand()) / (float)RAND_MAX) * 2.0 * M_PI;
	float phi = (((float)rand()) / (float)RAND_MAX) * M_PI;

	coords[0] = r * sin(phi) * cos(theta);
	coords[1] = r * sin(phi) * sin(theta);
	coords[2] = r * cos(phi);

	return coords;
}

//---------------------------------------------------------------------------

float* generatePointsForCylinder()
{
	float radius = 0.4;
	float height = 0.8;
	float* coords = new float[3];
	float angle = static_cast<float>(rand()) / RAND_MAX * 2 * M_PI;
	float r = static_cast<float>(rand()) / RAND_MAX * radius;
	float h = static_cast<float>(rand()) / RAND_MAX * height;

	coords[0] = r * cos(angle);
	coords[1] = h - 0.4;
	coords[2] = r * sin(angle);

    return coords;
}
//---------------------------------------------------------------------------

float* generatePointsForCone()
{
	float* coords = new float[3];
	float height = 1.0;
	float maxRadius = 0.5;

	float h = (float)rand() / RAND_MAX;
	float theta = (float)rand() / RAND_MAX * 2.0 * M_PI;

	float currentRadius = (1.0 - h) * maxRadius;
	float r = sqrt((float)rand() / RAND_MAX) * currentRadius;

	coords[0] = r * cos(theta);
	coords[1] = (h * height) - (height / 2.0);
	coords[2] = r * sin(theta);

	return coords;
}

//---------------------------------------------------------------------------
float* generatePointsForThorus()
{
	float* coords = new float[3];
	float r = 0.5;
	float theta = (((float)rand()) / (float)RAND_MAX) * 2.0 * M_PI;
	float phi = (((float)rand()) / (float)RAND_MAX) * M_PI;

	coords[0] = r * sin(phi) * cos(theta);
	coords[1] = r * sin(phi) * sin(theta);
	coords[2] = r * cos(phi);


	return coords;
}

