#include "Points.h"
#include <iostream>

int main()
{
	Point3D A = { 1.7, 0.3, 9.8 };
	Point3D B = { 1.0, 1.2, 6.9 };
	Point3D C = { 1.6, 0.4, 7.0 };

	Point3D points[] = { A, B, C };

	const int size = sizeof(points) / sizeof(Point3D);

	Sort(points, size);

	Print(points, size);

	return 0;
}
