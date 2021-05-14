#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <chrono>
#include <algorithm>


#define _USE_MATH_DEFINES

using namespace std;



constexpr unsigned int HEIGHT = 450, WIDTH = 900;
constexpr unsigned int dW = 8, dH = 16;



class pos{
public:  
  float
    x,
	y;

  pos(float newX, float newY){
	x = newX;
	y = newY;
	  
  }
  
};
  


void moveCursor( short x,short y){

  COORD coord = { x, y};
	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
  
}


void drawPoint(char canvas[HEIGHT/dH][WIDTH/dW], pos  Pos, char c ){

  
  if(Pos.x < 0 || Pos.y < 0 || Pos.x > WIDTH || Pos.y > HEIGHT) return;
  canvas[int(round(Pos.y/dH))][int(round(Pos.x/dW))] = c ;
}



void drawLine(char canvas[HEIGHT/dH][WIDTH/dW], pos Pos1, pos Pos2, char c){
  
  // Pos1 is allways on the left
  if(Pos2.x < Pos1.x)
  	swap(Pos1,Pos2);

  
  

  bool reversed = false;

  float
	X1 = Pos1.x,
	Y1 = Pos1.y,
	X2 = Pos2.x,
	Y2 = Pos2.y;
  
  if(abs(Pos1.x - Pos2.x) < abs(Pos1.y - Pos2.y)){
	reversed = true;
	X1 = Pos1.y;
	Y1 = Pos1.x;
	X2 = Pos2.y;
	Y2 = Pos2.x;
  }

  
  pair<float,float> sorted = {min(X1,X2),max(X1,X2)};
  
  float
	B1 = X1-X2,
	B2 = Y1-Y2;
  

  
  if(B2 == 0){
	if(!reversed){
	  for (float i = sorted.first; i < sorted.second;i += dW ) drawPoint(canvas,pos(i,Y1),c);
 	}else{
	  for (float i = sorted.first; i < sorted.second;i += dH ) drawPoint(canvas,pos(Y1,i),c);
	}
  }
  
  float
	B = B2/B1,
	A = -X1*B+Y1;
  
  	if(!reversed){
	  for (float i = sorted.first; i < sorted.second;i += dW ) drawPoint(canvas,pos(i,( i*B + A )),c);
 	}else{
	  for (float i = sorted.first; i < sorted.second;i += dH ) drawPoint(canvas,pos(( i*B + A ),i),c);
	}
  
  // draw pivit points

  
  drawPoint(canvas,{Pos1.x,Pos1.y},'@');
  drawPoint(canvas,{Pos2.x,Pos2.y},'@');
}



