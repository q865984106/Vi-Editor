#pragma once

template<class ItemType>
class Point {
public:
	Point();
	Point(const ItemType, const ItemType);
	void setX(const ItemType);
	void setY(const ItemType);
	ItemType getX()const;
	ItemType getY()const;
	void display()const;
private:
	ItemType mX;
	ItemType mY;
};
#include"Point.cpp";