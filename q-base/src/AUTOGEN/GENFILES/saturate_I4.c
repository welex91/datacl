
// START FUNC DECL
void
saturate_I4(
    int *X,
    long long n,
    int maxval
    )
// STOP FUNC DECL
{
  for ( long long i = 0; i < n; i++ ) { 
    if ( X[i] > maxval ) { X[i] = maxval; }
  }
}
