#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "RYGLeds.h"
#include "Seg7.h"
#include "Switches.h"
#include "AtoD.h"
#include "LED.h" // note type lcd fix later
#include "stdio.h"
#include "math.h"


byte CounterTop = 0;
word CounterBottom = 0;

///* use this to comment out if not using switches
void DoDowns(byte DebounceResult) 
{
// check special combos first in if
// then single standards va switches as else(can drop else if not required)
/*
    if(swTop+ swBottom == DebounceResult)
    {
    }
    else */
    switch(DebounceResult) 
    {
      case swCenter:
      break;
      case swRight:
      break;
      case swBottom:
      break;
      case swLeft:
      break;
      case swTop:
      break;
    }
}

void DoHeld(byte DebounceResult) 
{   
// check special combos first in if
// then single standards va switches as else(can drop else if not required)
    /*if(swTop+ swBottom == DebounceResult)
    {
    }
    else)*/                                        
     switch(DebounceResult) 
    {
      case swCenter:
      break;
      case swRight:
      break;
      case swBottom:
      break;
      case swLeft:
      break;
      case swTop:
      break;
    }  
}
//*/
// check special combos first in if
// then single standards va switches as else(can drop else if not required)
void DoUp(byte DebounceResult) 
{
    /*if(swTop+ swBottom == DebounceResult)
    {
    }
    else*/
      switch(DebounceResult) 
    {
      case swCenter:
      break;
      case swRight:
      break;
      case swBottom:
      break;
      case swLeft:
      break;
      case swTop:
      break; 
    }
}



void main(void) {
  /* put your own code here */


  
	//EnableInterrupts;
	
	LedRYGInIt();
	Seg7InIt();
	lcdInIt();
	lcdSetRowCol(0, 0);
	lcdString("Allmost done!");
	
	ATD0InIt();
	
	InItSwitch(&DoDowns, &DoHeld, &DoUp);
	ChangeButtonDelay(250 , 100);
	


  for(; ;) {
  //ButtonCheck();
  
  //Delay(1000);
  Delay(100);
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
