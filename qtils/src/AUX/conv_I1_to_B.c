/*
© [2013] LinkedIn Corp. All rights reserved.
Licensed under the Apache License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may obtain
a copy of the License at  http://www.apache.org/licenses/LICENSE-2.0
 
Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an "AS IS"
BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied.
*/
#include <stdio.h>
#include "constants.h"
#include "macros.h"

/* TODO P2: See if there is a library function call for this */
// START FUNC DECL
int
conv_I1_to_B(
    char *X,
    long long nX,
    char * restrict Y
    )
// STOP FUNC DECL
{
  int status = 0;
  long long n;
  unsigned int uix, uiy;  
  /* Need to deal with fact that nX may not be a multiple of 8  */
  n = ( nX / 8 ) * 8 ; 
  long long xindex = 0;
  long long yindex = 0;
  for ( xindex = 0; xindex < n; ) {
    uiy = 0;
    for ( int j = 0; j < 8; j++ ) { 
      uix = X[xindex++];
#ifdef DEBUG
      if ( ( uix != 0 ) && ( uix != 1 ) ) {
	WHEREAMI; status = -1; continue; 
      }
#endif
      uix = uix << j;
      uiy = uiy | uix;
    }
    Y[yindex++] = uiy;
  }
  int leftover = nX - n;
  for ( ; xindex < nX; ) {
    uiy = 0;
    for ( int j = 0; j < leftover; j++ ) { 
      uix = X[xindex++];
      uix = uix << j;
      uiy = uiy | uix;
    }
    Y[yindex++] = uiy;

  }
  if ( xindex != nX ) { go_BYE(-1); }
  long long chk_yindex;
  chk_yindex = nX / 8;
  if ( ( ( nX / 8 ) * 8 ) != nX ) {
    chk_yindex++;
  }
  if ( yindex != chk_yindex ) { go_BYE(-1); }

BYE: 
  return(status);
}

