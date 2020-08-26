#include "Point.h"
#include <iostream>
using namespace std;


template<class ItemType>
Point<ItemType>::Point()
{
	mX = 0;
	mY = 0;

}

template<class ItemType>
Point<ItemType>::Point(const ItemType inx, const ItemType iny)
{
	mX = inx;
	mY = iny;

}

template<class ItemType>
void Point<ItemType>::setX(const ItemType inX)
{
	mX = inX;

}

template<class ItemType>
void Point<ItemType>::setY(const ItemType inY)
{
	mY = inY;

}

template<class ItemType>
ItemType Point<ItemType>::getX() const
{
	return mX;
}
template<class ItemType>
ItemType Point<ItemType>::getY() const
{
	return mY;
}

template<class ItemType>
void Point<ItemType>::display() const
{
	cout << '(' << mX << ',' << mY << ')';

}
