/*
  Author: Angelo Sanches
  Board:  mc9s12xdp512(nait)
  Perpous: SCI (Com) C
  Created: 3/11/16 
  
  -------------UseLog-------------
  ->last is template
  Modified:<version:Date>
  Reason:
  ----------Change Log------------
  ->last is template
  Log:<Reason/Modified> Optional log Optional log in case of compliations
*/

#include "ComSCI.h"

Byte WaitReadByte(byte* Out)
{
  byte Count = 0;
  while(SCI0SR1<7 && Count < 0xFF)
    Count++;
  if (Count < 0xFF)
  {
     *Out = SCI0DRL; 
     return 0;
  }
  return 0xFF;
}


Byte ReadByte(void)
{
  if (!(0xDF & SCI0SR1))
    return SCI0DRL;
}

byte WaitSendByte(byte SendOut)
{
  byte Count = 0;
  while(SCI0SR1<7 && Count < 0xFF)
    Count++;
  if (Count < 0xFF)
  {
     SCI0DRL = SendOut;
     return 0;
  }
  return 0xFF;
}

byte SendByte(byte SendOut)
{
  if(SCI0SR1<7)
  return 0xFF;
  SCI0DRL = SendOut;
}


byte ReadString(char* String, byte* OutSize)
{
  word Break = 0;
  *OutSize = 0;
  while(String[*OutSize] != 0x00 && String[*OutSize] != '\0')
  {
    while(!WaitSendByte(String[*OutSize])&& Break < 0xFFFF)
    Break++;
    *OutSize = *OutSize +1; 
  }
  if (Break < 0xFFFF)
    return 0;
  return 0xFF;
}

byte ReadBytes(byte* Out, byte Number)
{
  word Break =0;
  byte Count = 0;
  for(Count = 0; Count< Number; Count++)
  {
    while(!WaitSendByte(Out[Count])&& Break < 0xFFFF)
    Break++;
  }
  if (Break < 0xFFFF)
    return 0;
  return 0xFF;
}


byte SendString(char* String)
{
  byte i =0;
  Word Break = 0;
  while(String[i] != 0x00 && String[i] != '\0')
  {
    while(!WaitSendByte(String[i]) && Break < 0xFFFF)
    Break++;
    i++; 
    
  }
  if (Break < 0xFFFF)
    return 0;
  return 0xFF;
}


byte SendBytes(byte* String, byte Number)
{
  byte Count;
  byte Break = 0;
  for(Count = 0; Count< Number; Count++)
  {
    while(!WaitSendByte(String[Count])&& Break < 0xFFFF)
    Break++;
  }
  if (Break < 0xFFFF)
    return 0;
  return 0xFF;
}



