// spiral

#include <iostream>
#include <cstdio>
#include <cmath>
#include <time.h> //nanosleep
#include <clocale>

#define PI 3.14159265

wchar_t Space = L' ';
wchar_t SymGeo1= L'*';


// nanosleep parametrs:
	timespec tw = {0, 50000000 };
	timespec tr;
	
	// Display dimensions
const int Cols = 60;
const int Rows = 45;
const float DispRatio = 9/16. ;
const float Ratio = DispRatio* static_cast<float>(Rows)/Cols;

wchar_t Disp[Rows][Cols];

// Axis parametrs
const int AxisXZero = Cols /2;
const int AxisYZero = Rows /2;
wchar_t AxisX = L'-';
wchar_t AxisY = L'|';


void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols);
void FillArr( wchar_t Arr[][Cols], int Rows, int Cols );
void PrintArrInt(int Arr[][Rows][Cols], int Rows, int Cols );


// ---++ Geo ++=--

void AddAxises( wchar_t Arr[][Cols], int Rows, int Cols );
void AddLine( float a, float b);
void AddLineWithRate( float a, float b, int r1, int r2);
void DelLine( float a, float b);
void DelLineWithRate( float a, float b, int r1, int r2);

void AddCircle( float a, float b, float r);
void AddCircle1( float a, float b, float r);
void AddCircle2( float a, float b, float r);
void AddCircle3( float a, float b, float r);

void AddCircle4( float a, float b, float r, int cStart , int length);

using namespace std;

int main(){
	srand(time(0));
  
   for ( int DegS = 0; DegS < 72000; DegS -= 30 ){
            FillArr(Disp, Rows, Cols);
    	   
    	   int Radius = 1;
    	  int DegreeS = DegS;
    	  while ( Radius < 30){ 
   	AddCircle4(0,0,Radius, DegreeS, 90);
   	
   	Radius += 1;
   	DegreeS += 30;
    	  }
    			 system("cls");
    		PrintArr(Disp, Rows, Cols);
           nanosleep(&tw, &tr);
   }
  
	return 0;
}

// Geo functions

void AddAxises( wchar_t Arr[][Cols], int Rows, int Cols ){
	// draw axis Y
	for (int i = 0; i < Rows; i++){
		Arr[ i ][ AxisXZero ] = AxisY;
	}

	// draw axis X
		for (int j = 0; j < Cols; j++){
			Arr[ AxisYZero ][ j ] = AxisX;
		}
		
}

// y = a*x + b
void AddLine( float a, float b){
	int i = 0;
	int j = 0;
	int y ; //= -i + AxisYZero;
	int x; // = j - AxisXZero;
	
	 for (int j = 0;  j < Cols; j++){
	 		x = j - AxisXZero;
	 		y = a*x + b;
	 		i = -y + AxisYZero;
if ( i >=0 && i <Rows)Disp[i][j] = SymGeo1;
	 }	
};

void AddLineWithRate( float a, float b, int r1, int r2){
	int i = 0;
	int j = 0;
	int y ; //= -i + AxisYZero;
	int x; // = j - AxisXZero;
	int min = r1 + AxisXZero;
	int max = r2 + AxisXZero;
	
	 for (int j = min;  j <= max; j++){
	 		x = j - AxisXZero;
	 		y = a*x + b;
	 		i = -y + AxisYZero;
if ( i >=0 && i <Rows)Disp[i][j] = SymGeo1;
	 }	
};

void DelLineWithRate( float a, float b, int r1, int r2){
	int i = 0;
	int j = 0;
	int y ; //= -i + AxisYZero;
	int x; // = j - AxisXZero;
	int min = r1 + AxisXZero;
	int max = r2 + AxisXZero;
	
	 for (int j = min;  j <= max; j++){
	 		x = j - AxisXZero;
	 		y = a*x + b;
	 		i = -y + AxisYZero;
if ( i >=0 && i <Rows)Disp[i][j] = Space;
	 }	
};

void DelLine( float a, float b){
	int i = 0;
	int j = 0;
	int y ; //= -i + AxisYZero;
	int x; // = j - AxisXZero;
	
	 for (int j = 0;  j < Cols; j++){
	 		x = j - AxisXZero;
	 		y = a*x + b;
	 		i = -y + AxisYZero;
if ( i >=0 && i <Rows)Disp[i][j] = Space;
	 }	
};


// x2 + y2 = r2
void AddCircle( float a, float b, float r){
	int i = 0;
	int j = 0;
	int y ; //= -i + AxisYZero;
	int x; // = j - AxisXZero;
	
	 for (int j = 0;  j < Cols; j++){
	 		x = j - AxisXZero;
	 		if (abs (x) > r) continue;
	 		y = pow((pow(r,2) - pow(x,2)), 0.5);
	 		i = -y + AxisYZero;
if ( i >=0 && i <Rows){
	Disp[i][j] = SymGeo1;
	Disp[Rows - i][j] = SymGeo1;
}
	 }	
};

void AddCircle1( float a, float b, float r){
	int i = 0;
	int j = 0;
	int step = 1;
for ( int c = 0; c < 360; c+= step){
	float Deg = c* PI /180;
    float y = r*sin(Deg);
    float x = r*cos(Deg);
   	i = -y + AxisYZero - b;
       j = x + AxisXZero + a;
       if ( ( i >= 0 && i < Rows) &&
       (j >= 0 && j < Cols) ){
    	Disp[i][j] = SymGeo1;
    	  // system("cls");
    		//PrintArr(Disp, Rows, Cols);
           // nanosleep(&tw, &tr);
       }
}
	 
};

void AddCircle2( float a, float b, float r){
	int i = 0;
	int j = 0;
	int step = 6;
	int offset = 90;
	
for ( int c = 360; c > 0; c-= step){
	float Deg = (c + 90)* PI /180 ;
    float y = r*sin(Deg);
    float x = r*cos(Deg);
   	i = -y + AxisYZero - b;
       j = x + AxisXZero + a;
       if ( ( i >= 0 && i < Rows) &&
       (j >= 0 && j < Cols) ){
    	Disp[i][j] = SymGeo1;
  
    	   system("cls");
    		PrintArr(Disp, Rows, Cols);
           nanosleep(&tw, &tr);
       }
     
}
	 
};

void AddCircle3( float a, float b, float r){
	int i = 0;
	int j = 0;
	int step = 1;
	int offset = 90;
	
for ( int c = 360; c > 0; c-= step){
	float Deg = (c + 90)* PI /180 ;
    float y = r*sin(Deg);
    float x = r*cos(Deg);
   	i = -y + AxisYZero - b;
       j = x + AxisXZero + a;
       if ( ( i >= 0 && i < Rows) &&
       (j >= 0 && j < Cols) ){
    	Disp[i][j] = SymGeo1;
    /*
    if ( x > 0){
      AddLineWithRate(y/x,  0, 0, x);
    }
    else AddLineWithRate(y/x,  0, x,0);
   */
     // AddLine(y/x,0);
    	   system("cls");
    		PrintArr(Disp, Rows, Cols);
           nanosleep(&tw, &tr);
         /*
            if ( x > 0){
      DelLineWithRate(y/x,  0, 0, x);
    }
    else DelLineWithRate(y/x,  0, x, 0);
         */
       }
     
}
	 
};

void AddCircle4( float a, float b, float r, int cStart , int length){
	int i = 0;
	int j = 0;
	int step = 2;
	int offset = 90;
	int repeat = 0;
	
for ( int c = cStart; c > cStart-360; c-= step ){
	float Deg = (c + 90)* PI /180 ;
    float y = r*sin(Deg) * Ratio;
    float x = r*cos(Deg);
   	i = -y + AxisYZero - b;
       j = x + AxisXZero + a;
       if ( ( i >= 0 && i < Rows) &&
       (j >= 0 && j < Cols) ){
    	Disp[i][j] = SymGeo1;
 
    //	   system("cls");
    //		PrintArr(Disp, Rows, Cols);
          // nanosleep(&tw, &tr);
         
         repeat++;
         if (repeat == length/step) break;
   
       }
     
}
	 
};



void FillArr( wchar_t Arr[][Cols], int Rows, int Cols ){
		// fill Disp 
	wchar_t* p = Arr[0];
	for (int i = 0; i < Rows*Cols; i++){
		*p = Space;
		p++;
	}
}

void PrintArr(wchar_t Arr[][Cols], int Rows, int Cols){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			wcout << Arr[i][j] ;
		//	nanosleep(&tw, &tr);
		}
		cout << endl;
	}
}

