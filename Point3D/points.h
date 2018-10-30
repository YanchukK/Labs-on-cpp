#ifndef POINTS3D_H
#define POINTS3D_H

struct Point3D
{
	double m_x, m_y, m_z;
};

double Distance(const Point3D  p_Point);

void Sort(Point3D * p_Points, int size);

void Swap(Point3D * p_Point_A, Point3D * p_Point_B);

void Print(const Point3D * p_Points, int size);

#endif
