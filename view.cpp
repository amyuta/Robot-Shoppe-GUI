#include "view.h"
#include "line.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <vector>
using namespace std;
void View::draw() {
	// Allow base class draw to operate
	Fl_Box::draw();
	// Draw the lines
	for (Line l : lines) {
		fl_color(FL_RED);
		fl_line(l.x1(), l.y1(), l.x2(), l.y2());
	}
}
bool View::saved() {
	return !dirty;
}

void View::new_program() { lines.clear(); dirty = false; }


bool View::dataDownload() {
	return !dirty;
}
