#include "driver.hpp"
#include "parser.hpp"

Driver::Driver ()
  : trace_scanning (false), trace_parsing (false)
{
  variables["one"] = 1;
  variables["two"] = 2;
}

Driver::~Driver ()
{
}

int
Driver::parse (const std::string &f)
{
  file = f;
  scan_begin ();
  yy::Parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();
  return res;
}

void
Driver::error (const yy::location& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

void
Driver::error (const std::string& m)
{
  std::cerr << m << std::endl;
}



int
main (int argc, char *argv[])
{
  int res = 0;
  Driver driver;

  if(argc == 2 && argv[1] == std::string ("-h"))
  {
      std::cout << "this is help" << std::endl;
      return 0;
  }
  
  for (int i = 1; i < argc; ++i)
    if (argv[i] == std::string ("-p"))
      driver.trace_parsing = true;
    else if (argv[i] == std::string ("-s"))
      driver.trace_scanning = true;
    else if (!driver.parse (argv[i]))
      std::cout << driver.result << std::endl;
    else
      res = 1;
  return res;
}

