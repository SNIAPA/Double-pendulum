#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "draw.h"

  
constexpr float MATH_PI = 3.1415926535;

using namespace std;



int main(){

  
  clock_t c_last = clock();
  clock_t c_now;
  
  char canvas[HEIGHT/dH][WIDTH/dW];

  constexpr float
	m1 = 3,
	l1 = 100,
	m2 = 3,
	l2 = 100,
	g = 9.8,
	fps = 300.0f,
	dt = 1.0f/fps;
  
  float
	accumulator = 0.0f,
	O1 = 2.0f*MATH_PI/3.0f,
	O2 = 2.0f*MATH_PI/3.0f,
	w1 = 0.0f,
	w2 = 0.0f;
		
  while(true){
	c_now = clock();

	if(c_now - c_last > dt){

	  
	  for (int i = 0; i < HEIGHT/dH; i++){
		for (int j = 0; j < WIDTH/dW; j++){
		  canvas[i][j] = ' ';
		}
	  }

	  for (int i = 0; i < HEIGHT/dH-1; i++) canvas[i][WIDTH/dW-1] = '\n';

	  
	  c_last = c_now;

	  float
		alfa1=(  -g*(2*m1 +m2 )*sin(O1 )-g*m2 *sin(O1 -2*O2 )-2*m2 *sin(O1 -O2 )*(w2 *w2 *l2 +w1 *w1 *l1 *cos(O1 -O2 ))  )/(  l1 *(2*m1 +m2 -m2 *cos(2*O1 -2*O2 ))  ),
		alfa2=(  2*sin(O1 -O2 )  )*(  w1 *w1 *l1 *(m1 +m2 ) + g*(m1 +m2 )*cos(O1 ) + w2 *w2 *l2 *m2 *cos(O1 -O2 )  )/l2 /(  2*m1 +m2 -m2 *cos(2*O1 -2*O2 )  );

	  
	  w1 +=10*dt*alfa1;
	  w2 +=10*dt*alfa2;
	  O1 +=10*dt*w1;
	  O2 +=10*dt*w2;
				

	  
	  

	  
	  float
		X12 = round( l1 * sin(O1)),
		Y12 = round(-l1 * cos(O1)),
		X22 = round( l2 *(sin(O1) + sin(O2)  )),
		Y22 = round(-l2 *(cos(O1) + cos(O2)  ));

	  
	  
	  pos
		pos11 = pos(WIDTH/2,HEIGHT/2),
		pos12 = pos(-X12 + WIDTH/2,-Y12 + HEIGHT/2),	  
		pos22 = pos(-X22 + WIDTH/2,-Y22 + HEIGHT/2);
	  
	  drawLine(canvas, pos11,pos12,'#');
	  drawLine(canvas, pos12,pos22,'#');
	  puts(canvas[0]);
	  moveCursor(0,0);
	}
	
  }
  
  
}

