/*
 * PointSet.h
 * The header file for the class PointSet
 */

#ifndef POINTSET_H
#define POINTSET_H

const int MAX_NUM_POINTS = 5;
#include "Point3D.h"
class PointSet
{
	public:
		PointSet();	//Default constructor
		PointSet(const PointSet& s);	//Copy constructor
		PointSet(const Point3D points[], int numPoints);	// Other constructor

		void addPoint(const Point3D& p);	//add a 3D point p(x,y,z) to the set; output (cout) the message "Insufficient array space" and do nothing else if there are already MAX_NUM_POINTS number of points
		void removeFirstPoint(); //remove the first point (the one with the smallest index) from the set; output (cout) the message "No points" and do nothing else if the set has no points at all
		void removeAll(); //remove all points
		bool contains(const Point3D& p) const;	//return true if the given 3D point p(x,y,z) is in the set; return false otherwise
		void print() const;	// print the list of 3D points in the set

	private:
		int numPoints;
		Point3D points[MAX_NUM_POINTS];

};

#endif
