#include "Points.h"
#include <math.h>
#include <iostream>


double Distance(const Point3D  point)
{
	double d = sqrt(point.m_x * point.m_x + point.m_y * point.m_y + point.m_z * point.m_z);
	return d;
}

void Swap(Point3D * A, Point3D * B)
{
	Point3D temp = *A;
	*A = *B;
	*B = temp;
}

//randomShuffle
void Sort(Point3D * p_Points, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (Distance(p_Points[j]) < Distance(p_Points[i]))
		Swap(p_Points + j, p_Points + i);
	}
}

void Print(const Point3D * p_Points, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << "(" << p_Points[i].m_x << ", " << p_Points[i].m_y << ", " << p_Points[i].m_z 
		<< ") \t = " << Distance(p_Points[i]) << std::endl;
