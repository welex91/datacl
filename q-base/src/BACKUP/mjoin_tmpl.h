typedef struct TEXT4 {
  TEXT1 lnk_val;
  long long idx_val;
} TEXT3;

extern int
mjoin_TEXT5(
	  char *src_fld_X,
	  char *src_lnk_X,
	  char *dst_lnk_X,
	  char *nn_src_fld_X,
	  char *nn_src_lnk_X,
	  char *nn_dst_lnk_X,
	  long long src_nR,
	  long long dst_nR,
	  bool *ptr_is_any_null,
	  char *str_meta_data,
	  char **ptr_nn_opfile,
	  int imjoin_op
	  );
extern  int
collect_lnk_idx_vals_TEXT2(
    char *src_lnk_X,
    char *nn_src_lnk_X,
    char *nn_src_fld_X,
    long long src_nR,
    char *dst_lnk_X,
    char *nn_dst_lnk_X,
    long long dst_nR,
      TEXT3 **ptr_src_pair,
      long long *ptr_nn_src_nR,
      TEXT3 **ptr_dst_pair,
      long long *ptr_nn_dst_nR,
      char **ptr_temp_src_X,
      size_t *ptr_temp_src_nX,
      char **ptr_temp_dst_X,
      size_t *ptr_temp_dst_nX
      );
