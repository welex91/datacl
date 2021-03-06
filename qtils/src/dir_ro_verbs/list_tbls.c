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
#include "qtypes.h"
#include "dbauxil.h"
#include "meta_globals.h"

extern char *g_docroot;
// START FUNC DECL
int
list_tbls(
	 )
// STOP FUNC DECL
{
  int status = 0;
  for ( int i = 0; i < g_n_tbl; i++ ) { 
    if ( g_tbls[i].name[0] != '\0' ) { /* entry in use */
      fprintf(stdout, "%d,%lld,%s,\"", i, g_tbls[i].nR, g_tbls[i].name); /* open quote */
      pr_disp_name(stdout, g_tbls[i].dispname);
      fprintf(stdout, "\"\n"); /* close quote */
    }
  }
  return(status);
}
