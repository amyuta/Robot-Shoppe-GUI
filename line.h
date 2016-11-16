#ifndef __LINE_H
#define __LINE_H 201610
class Line { // Define a line from (x1, y1) to (x2, y2)
public:
	Line(double p_x1, double p_y1, double p_x2, double p_y2)
		: _x1{ p_x1 }, _y1{ p_y1 }, _x2{ p_x2 }, _y2{ p_y2 } { }
	double x1() { return _x1; }
	double y1() { return _y1; }
	double x2() { return _x2; }
	double y2() { return _y2; }
private:
	double _x1, _y1, _x2, _y2;
};
#endif