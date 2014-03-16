#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Figure {
	virtual bool contains(double x, double y) = 0;
};
struct Rectangle : public Figure {
	double x1, y1, x2, y2;
	Rectangle(double _x1, double _y1, double _x2, double _y2) : 
		x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
	bool contains(double x, double y) {
		return x > x1 && x < x2 && y > y2 && y < y1;
	}
};
struct Circle : public Figure {
	double xc, yc, rr;
	Circle(double _xc, double _yc, double _r) :
		xc(_xc), yc(_yc), rr(_r*_r) {}
	bool contains(double x, double y) {
		return (x-xc)*(x-xc) + (y-yc)*(y-yc) < rr;
	}
};

int main()
{
	vector<Figure *> figures;
	string line;
	while (getline(cin, line) && line != "*") {
		char type;
		double a, b, c, d;
		if (sscanf(line.c_str(), "%c%lf%lf%lf%lf", &type, &a, &b, &c, &d) == 5)
			figures.push_back(new Rectangle(a, b, c, d));
		else 
			figures.push_back(new Circle(a, b, c));
	}

	for (int i = 1; getline(cin, line) && line != "9999.9 9999.9"; i++) {
		double x, y;
		sscanf(line.c_str(), "%lf%lf", &x, &y);
		bool isContained = false;
		for (int j = 0; j < figures.size(); j++)
			if (figures[j]->contains(x, y)) {
				isContained = true;
				printf("Point %d is contained in figure %d\n", i, j+1);
			}
		if (!isContained)
			printf("Point %d is not contained in any figure\n", i);
	}

	return 0;
}