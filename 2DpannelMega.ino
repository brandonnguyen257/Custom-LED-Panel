#include <FastLED.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_COLS 30
#define NUM_ROWS 10

#define DATA_ROW0 0
#define DATA_ROW1 1
#define DATA_ROW2 2
#define DATA_ROW3 3
#define DATA_ROW4 4
#define DATA_ROW5 5
#define DATA_ROW6 6
#define DATA_ROW7 7
#define DATA_ROW8 8
#define DATA_ROW9 9
#define snakeBodyLength 5

CRGB leds[NUM_ROWS][NUM_COLS];
char pulseAction=1;
char colorAction=1;
char snakeVertical=0;
CRGB currColor;


typedef struct Point{
  int row;
  int col;
  CRGB color;
}Point;

Point snakeBody[snakeBodyLength];

void setup() {
  FastLED.addLeds<WS2812B,DATA_ROW0,GRB>(leds[0],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW1,GRB>(leds[1],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW2,GRB>(leds[2],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW3,GRB>(leds[3],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW4,GRB>(leds[4],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW5,GRB>(leds[5],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW6,GRB>(leds[6],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW7,GRB>(leds[7],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW8,GRB>(leds[8],NUM_COLS);
  FastLED.addLeds<WS2812B,DATA_ROW9,GRB>(leds[9],NUM_COLS);
  currColor.setRGB(255,0,0);

  for(int i=0;i<snakeBodyLength;i++){
    snakeBody[snakeBodyLength-i-1]={0,i,CRGB::White};
  }
  snakeBody[0].color=CRGB::Red;
  FastLED.setBrightness(50);
}

void inc_color(){
  
  switch(colorAction){

    case 1:
      currColor.green+=5;
      if(currColor.green==255){
        colorAction=2;
      }
      break;
      
    case 2:
      currColor.red-=5;
      if(currColor.red==0){
        colorAction=3;
      }
      break;

    case 3:
      currColor.blue+=5;
      if(currColor.blue==255){
        colorAction=4;
      }
      break;

    case 4:
      currColor.green-=5;
      if(currColor.green==0){
        colorAction=5;
      }
      break;
      
    case 5:
      currColor.red+=5;
      if(currColor.red==255){
        colorAction=6;
      }
      break;

    case 6:
      currColor.blue-=5;
      if(currColor.blue==0){
        colorAction=1;
      }
      break;    
  }
  
}

CRGB random_color(){
  CRGB color;
  color.red=rand()%255;
  color.blue=rand()%255;
  color.green=rand()%255;
  return color;
}

void iterateColorWheel(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=currColor;
    }
  }
  FastLED.show();
  inc_color();
  delay(30);
}

void strobe(){
  for(int row=0;row<NUM_ROWS;row++){  //for loop each row
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }  
  FastLED.show();
  delay(100);
  
  FastLED.clear();
  FastLED.show();
  delay(100);   
}

void clockWiseStrobe(int currDelay){
  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);
}

void counterClockWiseStrobe(int currDelay){

  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  
  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);
}

void crissCrossStrobe(int currDelay){

  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);

  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);


  
  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(currDelay);
  FastLED.clear();
  FastLED.show();
  delay(currDelay);
}

void snake(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
      FastLED.show();
      delay(30);            
    }
  }
  FastLED.clear();
  FastLED.show();
  delay(30);
}

void verticalSnake(){
  for(int col=0;col<NUM_COLS;col++){
    for(int row=0;row<NUM_ROWS;row++){
      leds[row][col]=CRGB::White;
      FastLED.show();
      delay(30);
    }
  }
  FastLED.clear();
  FastLED.show();
  delay(30);
}

void rowStrobe(){
  for(int row=0;row<NUM_ROWS;row+=2){
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White; 
      leds[row+1][col]=CRGB::White; 
    }
      FastLED.show();
      delay(100);   
      FastLED.clear();
      FastLED.show();
      delay(100); 
  }
}

void leftRightStrobe(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(100);
  FastLED.clear();
  FastLED.show();
  delay(100);
  
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=NUM_COLS/2;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }  
  FastLED.show();
  delay(100);
  FastLED.clear();
  FastLED.show();  
  delay(100);
}

void topBottomStrobe(){
  for(int row=0;row<NUM_ROWS/2;row++){
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(100);
  FastLED.clear();
  FastLED.show();
  delay(100);
  for(int row=NUM_ROWS/2;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS;col++){
      leds[row][col]=CRGB::White;
    }
  }
  FastLED.show();
  delay(100);
  FastLED.clear();
  FastLED.show();
  delay(100);
}

void randomStrobe(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS/2;col++){
      leds[row][rand()%NUM_COLS]=CRGB::White;
    }
  }
  FastLED.show();
  delay(100);
  FastLED.clear();
  FastLED.show();
}

void alternateStrobe(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS;col+=2){
      leds[row][col]=CRGB::White;
    }
  }  
  FastLED.show();
  delay(30);
  FastLED.clear();
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=0;col<NUM_COLS;col+=2){
      leds[row][col-1]=CRGB::White;
    }
  } 
  FastLED.show();
  delay(30);
  FastLED.clear();
}

void shiftLeds(){
  for(int row=0;row<NUM_ROWS;row++){
    for(int col=NUM_COLS-1;col>=0;col--){
      leds[row][col]=leds[row][col-1];
    }
  }
}

void pulse5(){
  CRGB tempColor=random_color();
  switch(pulseAction){
    case 1: 
      
      for(int i=0;i<5;i++){
        for(int row=0;row<NUM_ROWS;row++){
          leds[row][0]=tempColor;
        }
        FastLED.show();
        delay(30);
        shiftLeds();
      }
      pulseAction=2;
      break;

    case 2:
      for(int i=0;i<5;i++){
        for(int row=0;row<NUM_ROWS;row++){
          leds[row][0]=CRGB::Black;
        }
        FastLED.show();
        delay(30);
        shiftLeds();
      }
      pulseAction=1;
      break;
  }
}

void rowXrow_pulse5(){
  CRGB tempColor=random_color();
  
  
  for(int row=0;row<NUM_ROWS;row++){  //iterate through every row to pulse5
    for(int i=0;i<5;i++){ //pulses 5 tempColor leds
      leds[row][0]=tempColor;
      for(int temp=0;temp<NUM_ROWS;temp++){ //every row besides current row pulses black
        if(temp!=row){
          leds[temp][0]=CRGB::Black;
        }
      }
      FastLED.show();
      delay(30);
      shiftLeds();
    }
  }


}

void randomRow_pulse5(){
  CRGB tempColor=random_color();  //selects random color
  int currentRow=rand()%NUM_ROWS;  //selects random row to pulse5

  
  for(int i=0;i<5;i++){ //for loop to pulse5
    leds[currentRow][0]=tempColor;    
      for(int temp=0;temp<NUM_ROWS;temp++){ //every row besides current row pulse1 black
        if(temp!=currentRow){
          leds[temp][0]=CRGB::Black;
        }
      }    
    FastLED.show();
    delay(30);
    shiftLeds();
  }
  
  //pulse1 every row black for cases where currentRow is the same in 2 consecutive loops
  for(int row=0;row<NUM_ROWS;row++){
    leds[row][0]=CRGB::Black;
  }
  FastLED.show();
  delay(30);
  shiftLeds();
}

void wave(){

  
  for(int row=1;row<NUM_ROWS-1;row++){
    leds[row][0]=currColor;
    inc_color();
    for(int tempRow=0;tempRow<NUM_ROWS;tempRow++){
      if(tempRow!=row){
        leds[tempRow][0]=CRGB::Black;
      }
    }
    FastLED.show();
    shiftLeds();
    delay(30);
  }

  for(int row=NUM_ROWS-1;row>=0;row--){
    leds[row][0]=currColor;
    inc_color();
    for(int tempRow=0;tempRow<NUM_ROWS;tempRow++){
      if(tempRow!=row){
        leds[tempRow][0]=CRGB::Black;
      }
    }
    FastLED.show();
    shiftLeds();
    delay(30);
  }


  
}

void wave2(){

  for(int row=0;row<4;row++){
    leds[(NUM_ROWS/2)-row][0]=currColor;
    inc_color();
    for(int tempRow=0;tempRow<NUM_ROWS;tempRow++){
      if(tempRow!=row){
        leds[tempRow][0]=CRGB::Black;
      }
    }
    FastLED.show();
    shiftLeds();
    delay(30);
  }


}

void colXcol_strobe(){
  for(int col=0;col<NUM_COLS;col++){
    for(int row=0;row<NUM_ROWS;row++){
      leds[row][col]=CRGB::White;
    }
    FastLED.show();
    delay(30);
    FastLED.clear();
    FastLED.show();
    delay(30);
  }
}

void WiseBroAnimate(){
  int col=0;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  
  col=1;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=2;
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=3;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=4;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;

  col=5;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=6;
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=7;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=8;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;

  col=10;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=11;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=12;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=13;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;

  col=13;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=13;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=14;

  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;

  FastLED.show();
  delay(700);
  FastLED.clear();
  col=13;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  
  col=14;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=15;
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=16;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=17;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;

  col=18;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=19;
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=20;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;

  col=21;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;

  col=23;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=24;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=25;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=26;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;

  col=27;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=28;
  leds[0][col]=CRGB::White;
  leds[1][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[8][col]=CRGB::White;
  leds[9][col]=CRGB::White;
  
  col=29;

  leds[1][col]=CRGB::White;
  leds[2][col]=CRGB::White;
  leds[3][col]=CRGB::White;
  leds[4][col]=CRGB::White;
  leds[5][col]=CRGB::White;  
  leds[6][col]=CRGB::White;
  leds[7][col]=CRGB::White;
  leds[8][col]=CRGB::White;
  FastLED.show();
  delay(700);
  FastLED.clear();
}


void WBanimate(int index,CRGB color,int tempDelay){
  int col=0+index;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[2][col]=color;
  
  col++;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;

  col++;
  leds[6][col]=color;
  leds[7][col]=color;
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;

  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[2][col]=color;

  col++;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;

  col++;
  leds[6][col]=color;
  leds[7][col]=color;
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;

  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[2][col]=color;

  col++;

  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[2][col]=color;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[6][col]=color;
  leds[7][col]=color;
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[8][col]=color;
  leds[9][col]=color;

  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;
  leds[0][col]=color;
  leds[1][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[8][col]=color;
  leds[9][col]=color;
  
  col++;

  leds[1][col]=color;
  leds[2][col]=color;
  leds[3][col]=color;
  leds[4][col]=color;
  leds[5][col]=color;  
  leds[6][col]=color;
  leds[7][col]=color;
  leds[8][col]=color;

  FastLED.show();
  delay(tempDelay);
  FastLED.clear();  
}

void WBmoving(){
  for(int i=0;i<13;i++){
    WBanimate(i,currColor,100);
    inc_color();
  }
  for(int i=13;i>0;i--){
    WBanimate(i,currColor,100);
    inc_color();
  }
}

void chasingSnake(){
  displaySnake();

  Point prevHead=snakeBody[0];
  if(snakeVertical==0){
    snakeBody[0].row++;
    if(snakeBody[0].row==NUM_ROWS-1){
      snakeVertical=1;
    }
  }
  else{
    snakeBody[0].row--;
    if(snakeBody[0].row==0){
      snakeVertical=0;
    }
  }
  //snakeBody[4].row++;
  snakeBody[0].col++;
  
  updateSnakeBody(prevHead);
  FastLED.show();
  delay(50);
  FastLED.clear();
}

void randomChasingSnake(){
  displaySnake();

  Point prevHead=snakeBody[0];
  updateSnakeHead();
  updateSnakeBody(prevHead);
  FastLED.show();
  delay(100);
  FastLED.clear();
}

void displaySnake(){
  for(int i=0;i<snakeBodyLength;i++){
    Point temp=snakeBody[i];
    leds[temp.row][temp.col]=temp.color;
  }  
}

void updateSnakeHead(){
  
  Point prevHead=snakeBody[0];
  int flag=1;
  while(flag){
    int direction=(rand()%4)+1;
    if(direction==1){//up
      Point tempCheck={snakeBody[0].row+1,snakeBody[0].col,CRGB::White};
      if(snakeCollideCheck(tempCheck) && boundaryCheck(tempCheck)){
        snakeBody[0]=tempCheck;
        flag=0;
      }
    }
    else if(direction==2){//down
      Point tempCheck={snakeBody[0].row-1,snakeBody[0].col,CRGB::White};
      if(snakeCollideCheck(tempCheck) && boundaryCheck(tempCheck)){
        snakeBody[0]=tempCheck;
        flag=0;
      }      
    }
    else if(direction==3){//left
      Point tempCheck={snakeBody[0].row,snakeBody[0].col-1,CRGB::White};
      if(snakeCollideCheck(tempCheck) && boundaryCheck(tempCheck)){
        snakeBody[0]=tempCheck;
        flag=0;
      }       
    }
    else if(direction==4){//right
      Point tempCheck={snakeBody[0].row,snakeBody[0].col+1,CRGB::White};
      if(snakeCollideCheck(tempCheck) && boundaryCheck(tempCheck)){
        snakeBody[0]=tempCheck;
        flag=0;
      }       
    }    
  }
}

int snakeCollideCheck(Point tempCheck){
  for(int i=0;i<snakeBodyLength;i++){
    if(snakeBody[i].row==tempCheck.row && snakeBody[i].col==tempCheck.col){
      return 0;
    }
  }
  return 1;
}

int boundaryCheck(Point tempCheck){
  if(tempCheck.row>=NUM_ROWS || tempCheck.row<0){
    return 0;
  }
  if(tempCheck.col>=NUM_COLS || tempCheck.col<0){
    return 0;
  }
  return 1;
}

void updateSnakeBody(Point prevHead){
  Point prev=prevHead;
  Point temp=prevHead;
  for(int i=1;i<snakeBodyLength;i++){
    temp=snakeBody[i];
    snakeBody[i].row=prev.row;
    snakeBody[i].col=prev.col;
    //snakeBody[i].color=prev.color;
    prev=temp;
  }  
  snakeBody[0].color=CRGB::Red;
}



void PorterLogo(CRGB color,int tempDelay){
  int row=0;
  leds[row][0]=color;
  leds[row][1]=color;
  leds[row][2]=color;
  leds[row][3]=color;
  leds[row][27]=color;
  leds[row][28]=color;
  leds[row][29]=color;

  row++;//1
  leds[row][0]=color;
  leds[row][1]=color; 
  leds[row][11]=color; 
  leds[row][19]=color; 
  leds[row][28]=color;
  leds[row][29]=color; 

  row++;//2
  leds[row][0]=color;
  leds[row][10]=color; 
  leds[row][12]=color;
  leds[row][18]=color;   
  leds[row][20]=color;
  leds[row][29]=color; 

  row++;//3
  leds[row][0]=color;
  leds[row][9]=color;
  //leds[row][11]=color;
  leds[row][13]=color;
  leds[row][17]=color;
  //leds[row][19]=color;
  leds[row][21]=color;
  leds[row][29]=color; 

  row++;//4
  leds[row][0]=color;
  leds[row][4]=color;
  leds[row][5]=color;
  leds[row][6]=color;
  leds[row][8]=color;
  //leds[row][10]=color;
  leds[row][11]=color;
  //leds[row][12]=color;
  leds[row][14]=color;
  leds[row][16]=color;
  //leds[row][18]=color;
  leds[row][19]=color;
  //leds[row][20]=color;
  leds[row][22]=color;
  leds[row][24]=color;
  leds[row][25]=color;
  leds[row][26]=color;
  leds[row][29]=color;

  row++;//5
  leds[row][0]=color;
  leds[row][4]=color;
  leds[row][5]=color;
  leds[row][6]=color;
  leds[row][9]=color;
  //leds[row][11]=color;
  leds[row][13]=color;
  leds[row][17]=color;
  //leds[row][19]=color;
  leds[row][21]=color;
  leds[row][24]=color;
  leds[row][25]=color;
  leds[row][26]=color;
  leds[row][29]=color;

  row++;//6
  leds[row][0]=color;
  leds[row][10]=color;
  leds[row][12]=color;
  leds[row][18]=color;
  leds[row][20]=color;
  leds[row][29]=color;

  row++;//7
  leds[row][0]=color;
  leds[row][11]=color;
  leds[row][19]=color;
  leds[row][29]=color;
  
  row++;
  leds[row][0]=color;
  leds[row][1]=color;
  leds[row][28]=color;
  leds[row][29]=color;

  row++;
  leds[row][0]=color;
  leds[row][1]=color;
  leds[row][2]=color;
  leds[row][27]=color;
  leds[row][28]=color;
  leds[row][29]=color;
  FastLED.show();
//  delay(tempDelay);
//  FastLED.clear();
//  FastLED.show();
//  delay(100);
}

void diamondMiddleDotWave(){
  char middle=NUM_ROWS/2;
  
  for(int i=0;i<middle;i++){
    leds[i][0]=currColor;
    leds[NUM_ROWS-i-1][0]=currColor;
    
    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=i && row!=NUM_ROWS-i-1){
        leds[row][0]=CRGB::Black;
      }
    }
    if(i==0){
      leds[middle][0]=currColor;
      leds[middle-1][0]=currColor;
    }
    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }

  for(int i=1;i<middle;i++){
    leds[middle+i][0]=currColor;
    leds[middle-i-1][0]=currColor;

    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=middle+i && row!=middle-i-1){
        leds[row][0]=CRGB::Black;
      }
    }
    if(i==middle-1){
      leds[middle][0]=currColor;
      leds[middle-1][0]=currColor;
    }
    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }
}

void diamondWave(){
  char middle=NUM_ROWS/2;
  
  for(int i=0;i<middle;i++){
    leds[i][0]=currColor;
    leds[NUM_ROWS-i-1][0]=currColor;
    
    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=i && row!=NUM_ROWS-i-1){
        leds[row][0]=CRGB::Black;
      }
    }

    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }

  for(int i=1;i<middle;i++){
    leds[middle+i][0]=currColor;
    leds[middle-i-1][0]=currColor;

    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=middle+i && row!=middle-i-1){
        leds[row][0]=CRGB::Black;
      }
    }

    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }
}

void diamondCrossWave(){
  char middle=NUM_ROWS/2;
  
  for(int i=0;i<middle;i++){
    leds[i][0]=currColor;
    leds[NUM_ROWS-i-1][0]=currColor;


    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=i && row!=NUM_ROWS-i-1){
        leds[row][0]=CRGB::Black;
      }
    }          
    


    leds[middle][0]=currColor;
    if(i==middle-1){
      leds[middle][0]=CRGB::White;
    }
    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }

  for(int i=1;i<middle;i++){
    leds[middle+i][0]=currColor;
    leds[middle-i-1][0]=currColor;


    for(int row=0;row<NUM_ROWS;row++){//puts black into every row not being lit
      if(row!=middle+i && row!=middle-i-1){
        leds[row][0]=CRGB::Black;
      }
    }      
    


    leds[middle][0]=currColor;
//    if(i==1){
//      leds[middle][0]=CRGB::White;
//    }    
    inc_color();
    FastLED.show();
    shiftLeds();
    delay(30);
  }  
}

void strobePreset1(){
  int effect=rand()%6;
  if(0==effect){
    leftRightStrobe();
  }
  else if(1==effect){
    strobe();
  }
  else if(2==effect){
    clockWiseStrobe(50);
  }
  else if(3==effect){
    crissCrossStrobe(50);
  }
  else if(4==effect){
    for(int i=0;i<3;i++){
      randomStrobe();
    }
    
  }
  else if(5==effect){
    counterClockWiseStrobe(50);
  }

  strobe();
}

void strobePreset2(){
  for(int i=0;i<3;i++){
    randomStrobe();
  }
  for(int i=0;i<3;i++){
    strobe();
  } 
  for(int i=0;i<2;i++){
    clockWiseStrobe(50);
  } 
  strobe();
  crissCrossStrobe(50);

  for(int i=0;i<3;i++){
    randomStrobe();
  }
  for(int i=0;i<3;i++){
    strobe();
  }  
  topBottomStrobe();
  for(int i=0;i<2;i++){
    counterClockWiseStrobe(50);
  } 
  rowStrobe();
  clockWiseStrobe(50);
  counterClockWiseStrobe(50);
  for(int i=0;i<3;i++){
    strobe();
  }  
  for(int i=0;i<2;i++){
    crissCrossStrobe(50);
  }   
}

void movingEffectPreset1(){
//  }
  for(int i=0;i<10;i++){
    randomRow_pulse5();
  }  
  for(int i=0;i<10;i++){
    wave();
  }  
  for(int i=0;i<20;i++){
    diamondMiddleDotWave();
  }   
}
void loop() {
  wave();
}
