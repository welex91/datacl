#include <stdio.h>
#include <stdbool.h>
#include "constants.h"
#include "macros.h"
#include "sqlite3.h"
#include "qtypes.h"
#include "fsize.h"
#include "auxil.h"
#include "dbauxil.h"
#include "is_fld.h"
#include "qchown.h"

// START FUNC DECL
int
qchown(
	char *docroot,
	sqlite3 *in_db,
	char *tbl,
	char *fld,
	char *new_val
	)
// STOP FUNC DECL
{
  int status = 0;
  sqlite3 *db = NULL;
  char qstr[4096]; 
  char buf[32];
  bool rslt;
  char *zErrMsg = 0;
  int rc, tbl_id, fld_id;
  //------------------------------------------------
  status = open_db_if_needed(docroot, in_db, &db);
  cBYE(status);
  if ( ( tbl == NULL ) || ( *tbl == '\0' ) ) { go_BYE(-1); }
  zero_string(buf, 32);
  zero_string(qstr, 4096);
  //------------------------------------------------
  status = is_tbl_fld(docroot, db, tbl, fld, &tbl_id, &fld_id, &rslt);
  cBYE(status);
  if ( !rslt ) { 
    fprintf(stderr, "No field [%s] in tbl [%s] \n", fld, tbl);
    go_BYE(-1);
  }
  //------------------------------------------------
  if ( ( new_val = NULL ) || ( strlen(new_val) == 0 ) || 
      ( strlen(new_val) > MAX_LEN_USER_NAME ) ) {
    fprintf(stderr, "owner value not valid \n");
    go_BYE(-1);
  }

  sprintf(qstr, "update fld set owner = %s where id = %d \n", new_val, fld_id);
  rc = sqlite3_exec(db, qstr, NULL, 0, &zErrMsg);
  if( rc != SQLITE_OK ) { handle_sqlite_error(); }
  //------------------------------------------------

 BYE:
  if ( in_db == NULL ) { sqlite3_close(db); }
  return(status);
}
