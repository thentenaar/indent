int (*fp ()) ();

register void (*GCForward) () asm ("r16");	/* GC Forwarding code */

main ()
{
  switch (fork ())
    {
    default:
      break;
    }
}

int *
function_2 (var)
     int var;
{
  int *var_1_0;

  var_1_0 = (int *) make_shape_1d (var);

  return (var_1_0);
}
