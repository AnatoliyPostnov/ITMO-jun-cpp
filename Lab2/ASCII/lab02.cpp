#include <iostream>
#include "shapes.h"
#include "shapes.cpp"
#include "Canvas.h"
#include "Canvas.cpp"
using namespace std;


// TASKS 1 AND 2 - ADD/MODIFY CODE IN MAIN AS DIRECTED
int main(){
	
//////////////////////////  Ellipse  //////////////////////////

  //~ //Shape 1
  //~ Ellipse e1(3,5);
  //~ e1.setPosition(15,15);

  //~ //Array of pointers to the shapes
  //~ const int NUM_SHAPES = 1;
  //~ Ellipse* shapes[NUM_SHAPES] = {&e1};

  //~ //Draw the shapes to the canvas
  //~ Canvas c;
  //~ int i = 0;
  //~ for(Ellipse **s = shapes; s < shapes + NUM_SHAPES; ++s){
    //~ cout << "Area of shape " << ++i << ": " << (*s)->area() << endl; 
    //~ (*s)->draw(&c);
  //~ }
  //~ //Print out the canvas
  //~ c.print();
 
 //////////////////////////  Circle  //////////////////////////
  
  //Shape 1
  Circle e2(3);
  e2.setPosition(15,15);
  //Array of pointers to the shapes
  const int NUM_SHAPES = 1;
  Circle* shapes[NUM_SHAPES] = {&e2};
  //Draw the shapes to the canvas
  Canvas c;
  int i = 0;
  for(Circle **s = shapes; s < shapes + NUM_SHAPES; ++s){
    cout << "Area of shape " << ++i << ": " << (*s)->area() << endl; 
    (*s)->draw(&c);
  }
  //Print out the canvas
  c.print();
  
  ////////////////////////  Rectangle  /////////////////////////
  
  //~ Rectangle e2(5,3);
  //~ e2.setPosition(4,15);
  //~ //Array of pointers to the shapes
  //~ const int NUM_SHAPES = 1;
  //~ Rectangle* shapes[NUM_SHAPES] = {&e2};
  //~ //Draw the shapes to the canvas
  //~ Canvas c;
  //~ int i = 0;
  //~ for(Rectangle **s = shapes; s < shapes + NUM_SHAPES; ++s){
    //~ cout << "Area of shape " << ++i << ": " << (*s)->area() << endl; 
    //~ (*s)->draw(&c);
  //~ }
  //~ //Print out the canvas
  //~ c.print();
  
}
