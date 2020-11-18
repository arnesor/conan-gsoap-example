#include "soapcalcProxy.h"
#include "calc.nsmap"

/* the Web service endpoint URL */
const char server[] = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    fprintf(stderr, "Usage: [add|sub|mul|div|pow] num num\n");
    exit(1);
  }
  calcProxy calc(server);
  double a, b, result;
  a = strtod(argv[2], NULL);
  b = strtod(argv[3], NULL);
  switch (*argv[1])
  {
    case 'a':
      calc.add(a, b, result);
      break;
    case 's':
      calc.sub(a, b, result);
      break;
    case 'm':
      calc.mul(a, b, result);
      break;
    case 'd':
      calc.div(a, b, result);
      break;
    case 'p':
      calc.pow(a, b, result);
      break;
    default:
      fprintf(stderr, "Unknown command\n");
      exit(1);
  }
  if (calc.soap->error)
    calc.soap_stream_fault(std::cerr);
  else
    std::cout << "result = " << result << std::endl;
  calc.destroy(); /* clean up */
  return 0;
}