#include <cassert>
#include <cmath>
#include "shapes.h"

using namespace std;
const double PI = 3.14159;

//////////////////////////  Ellipse  //////////////////////////

Ellipse::Ellipse(double xRad_in, double yRad_in)
  : xRad(xRad_in), yRad(yRad_in) {}
Ellipse::Ellipse()
  : xRad(0), yRad(0) {}
double Ellipse::area() const {
  return PI * xRad * yRad;
}

void Ellipse::draw(Canvas *canvas) const{
  // Iterate through the grid of (x,y) pixel coordinates
  // in the canvas.
  for(int x = 0; x < CANVAS_WIDTH; ++x){
    for(int y = 0; y < CANVAS_HEIGHT; ++y){

      // The ellipse contains the point (x,y) if and only if
      // ((x-xPos)/xRad)^2 + ((y-yPos)/yRad)^2 <= 1

      double xDiff = x - get_xPos();
      double yDiff = y - get_yPos();

      if( (xDiff/xRad)*(xDiff/xRad) + (yDiff/yRad)*(yDiff/yRad) <= 1 ){
        // If the pixel is contained in the ellipse, set it to true
        canvas->setPixel(x, y, true);
      }
    }
  }
}
        
///////////////////////// End Ellipse /////////////////////////



//////////////////////////  Circle  //////////////////////////

Circle::Circle(double R_in)
	: R(R_in) {}
		
double Circle::area() const {
  return PI * R*R;
}	

void Circle::draw(Canvas *canvas) const{
  // Iterate through the grid of (x,y) pixel coordinates
  // in the canvas.
  for(int x = 0; x < CANVAS_WIDTH; ++x){
    for(int y = 0; y < CANVAS_HEIGHT; ++y){

      // The ellipse contains the point (x,y) if and only if
      // ((x-xPos)/xRad)^2 + ((y-yPos)/yRad)^2 <= 1

      double xDiff = x - get_xPos();
      double yDiff = y - get_yPos();

      if( (xDiff)*(xDiff) + (yDiff)*(yDiff) <= R*R ){
        // If the pixel is contained in the ellipse, set it to true
        canvas->setPixel(x, y, true);
      }
    }
  }
}
   
///////////////////////// End Circle /////////////////////////



////////////////////////  Rectangle  /////////////////////////

Rectangle::Rectangle(double width_in,double height_in)
	:width(width_in),height(height_in) {}
	
double Rectangle::area() const {
  return width*height;
}		

void Rectangle::draw(Canvas *canvas) const{
  // Iterate through the grid of (x,y) pixel coordinates
  // in the canvas.
  for(int x = 0; x < CANVAS_WIDTH; ++x){
    for(int y = 0; y < CANVAS_HEIGHT; ++y){

      // The ellipse contains the point (x,y) if and only if
      // ((x-xPos)/xRad)^2 + ((y-yPos)/yRad)^2 <= 1

      double xDiff = abs(x - get_xPos());
      double yDiff = abs(y - get_yPos());

      if( xDiff<=width/2&&yDiff<=height/2){
        // If the pixel is contained in the ellipse, set it to true
        canvas->setPixel(x, y, true);
      }
    }
  }
}

//////////////////////// End Rectangle //////////////////////





















