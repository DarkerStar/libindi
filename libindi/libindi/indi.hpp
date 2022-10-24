#pragma once

#include <iosfwd>
#include <string>

#include <libindi/export.hpp>

namespace indi
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBINDI_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
