#ifndef SHAPES_H
#define SHAPES_H
//~ #include "shapes.cpp"
#include "Canvas.h"

///////////////////////////  Shape  ///////////////////////////

class Shape {
public:

  //EFFECTS: creates a shape with initial position (0,0)
  Shape() : xPos(0), yPos(0) {}

  //EFFECTS: returns the area of this Shape
  virtual double area() const = 0;

  //MODIFIES: canvas
  //EFFECTS: draws this shape onto canvas at its current position
    virtual void draw(Canvas *canvas) const = 0;

  //MODIFIES: xPos, yPos
  //EFFECTS: sets the position of this shape
  void setPosition(double xPos_in, double yPos_in){
    xPos = xPos_in;
    yPos = yPos_in;
  }

  double get_xPos() const { return xPos; }
  double get_yPos() const { return yPos; }

private:
  
  double xPos; // The x position of this shape
  double yPos; // The y position of this shape

};

/////////////////////////  End Shape  /////////////////////////



//////////////////////////  Ellipse  //////////////////////////

class Ellipse : public Shape{
public:
  Ellipse();	
  //REQUIRES: xRad_in, yRad_in are non-negative
  //EFFECTS: creates an Ellipse with given x and y radii
  Ellipse(double xRad_in, double yRad_in);
  
  //EFFECTS: returns the area of this Ellipse
  virtual double area() const;

  //MODIFIES: canvas
  //EFFECTS: draws this shape onto canvas
  virtual void draw(Canvas *canvas) const;

private:
  double xRad;  //Half the x-axis of the ellipse
  double yRad;  //Half the y-axis of the ellipse

};

///////////////////////// End Ellipse ////////////////////////



///////////////////////////////////////////////////////////////
//               DO NOT MODIFY ABOVE THIS LINE               //
///////////////////////////////////////////////////////////////



//////////////////////////  Circle  //////////////////////////

class Circle: public Ellipse{

	public:
	
		Circle (double R_in);	
		virtual double area() const;
		virtual void draw(Canvas *canvas) const;
	
	
	private:
		double R;
	};


///////////////////////// End Circle /////////////////////////



////////////////////////  Rectangle  /////////////////////////

class Rectangle: public Shape{
	private:
		double width;
		double height;
	public:
		Rectangle(double width_in,double height_in);
		virtual double area() const;
		virtual void draw(Canvas *canvas) const;
		
	};

//////////////////////// End Rectangle //////////////////////





#endif /* SHAPES_H */
