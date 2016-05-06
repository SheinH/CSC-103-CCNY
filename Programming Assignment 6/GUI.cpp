
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include <iostream>
#include <vector>
#include <algorithm>
//------------------------------------------------------------------------------
namespace ProgWindow {
	const int height = 500;
	const int width = 500;
	const Point tl = Point(100,100);
};
bool contains(const Rectangle& rect, const Point& p1){
	const Point p2 = rect.point(0);
	bool x = p1.x >= p2.x && p1.x <= p2.x + rect.width();
	bool y = p1.y >= p2.y && p1.y <= p2.y + rect.height();
	return x && y;
}
vector<Point> cornerPoints(const Rectangle& r){
	int x1 = r.point(0).x;
	int x2 = x1 + r.width();
	int y1 = r.point(0).y;
	int y2 = y1 + r.height();
	vector<Point> p {Point(x1,y1),Point(x2,y1),Point(x1,y2),Point(x2,y2)};
	// Returns vector with points: top left, top right, bottom left, bottom right
	return p;
}
bool overlap(const Rectangle& r1, const Rectangle& r2){
	vector<Point> pts = cornerPoints(r1);
	for(int i = 0; i < pts.size(); i++){
		if(contains(r2,pts[i]))
			return true;
	}
	return false;
}
void addRect(Simple_window& win,vector<Rectangle*>& rectangles, vector<Rectangle*>& overlaps, int sidelength){

	int x = rand() % (ProgWindow::width - sidelength);
	int y = rand() % (ProgWindow::height - sidelength);
	Rectangle* newRect = new Rectangle(Point(x,y),sidelength,sidelength);
    newRect->set_color(Color::dark_red);
    newRect->set_fill_color(Color::dark_red);
    win.attach(*newRect);
    for(int i = 0; i < rectangles.size(); i++){
    	Rectangle& r1 = *newRect;
    	Rectangle& r2 = *rectangles[i];
    	if(!overlap(r1,r2)){
    		break;
    	}
    	vector<Point> p1 = cornerPoints(r1);
    	vector<Point> p2 = cornerPoints(r2);
    	Rectangle* overlap;
    	int xval[] = {p1[0].x,p1[3].x,p2[0].x,p2[3].x};
    	int yval[] = {p1[0].y,p1[3].y,p2[0].y,p2[3].y};
    	sort(xval,xval + 4);
    	sort(yval,yval + 4);
    	Point tl(xval[1],yval[1]);
    	int w = xval[2] - xval[1];
    	int h = yval[2] - yval[1];
    	overlap = new Rectangle(tl,w,h);
    	overlap->set_color(Color::white);
    	overlap->set_fill_color(Color::white);
    	win.attach(*overlap);
    	overlaps.push_back(overlap);
    }
	rectangles.push_back(newRect);
}
bool display_squares(Simple_window& win){
	vector<Rectangle*> rectangles;
	vector<Rectangle*> overlaps;
	int sidelength;
	cout << "Enter a sidelength foor the squares: ";
	cin >> sidelength;
	if(sidelength <= 0){
		return false;
	}
	for(int i = 0;i < 3;i++){
		addRect(win,rectangles,overlaps,sidelength);
	}
	win.wait_for_button();
	//Cleanup
	for(int i = 0; i < rectangles.size(); i++){
		win.detach(*rectangles[i]);
		delete rectangles[i];
	}
	for(int i = 0; i < overlaps.size(); i++){
		win.detach(*overlaps[i]);
		delete overlaps[i];
	}
	return true;
}
int main(int argc,char* argv[])
{
	srand(time(0));
	using namespace Graph_lib;
	   // our graphics facilities are in G  raph_  lib   // make a simple window
	Simple_window win(ProgWindow::tl,ProgWindow::width,ProgWindow::height,"Programming Assignment #6");
    while(display_squares(win)){}
    return 0;
}

//------------------------------------------------------------------------------
