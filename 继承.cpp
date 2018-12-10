#include <iostream>

using namespace std;

class shape
{
public:
	void setWidth(int w)
	{
		width = w;
	}

	void setHight(int h)
	{
		hight = h;
	}

protected:
	int width;
	int hight;
};

class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
	}

};

class Rectangle : public shape, public PaintCost
{
public:
	int getArea()
	{
		return (width * hight);
	}
};
/*
int main()
{
	Rectangle Rect;

	Rect.setWidth(5);
	Rect.setHight(4);

	int area = Rect.getArea();
	//输出面积
	cout << "the total area: " << Rect.getArea() << endl;

	//输出总花费
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;

	return 0;
}
*/