#ifndef __VIEW_H
#define __VIEW_H 201610
#include "line.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <vector>
using namespace std;
//
// Simple lines in a window
//
class View : public Fl_Box {
	vector<Line> lines;
	bool dirty = true; // set true to demo Exit dialog
	bool saveData = true;
public:
	// Call base constructor
	View(int X, int Y, int W, int H)
		: Fl_Box(X, Y, W, H) { }
	// Draw the lines any time FLTK needs to refresh the widget
	void draw() override;
	// Determine if any lines haven't been saved
	bool saved();
	bool dataDownload();
	void new_program();

	
};
#endif
