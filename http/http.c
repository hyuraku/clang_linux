#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

static void
log_exit(char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fputc('\n', stderr);
  va_end(ap);
  exit(1);
}
