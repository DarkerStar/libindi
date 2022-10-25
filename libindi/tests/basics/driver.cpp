/***********************************************************************
 *                                                                     *
 * This file is part of libindi.                                       *
 *                                                                     *
 * libindi is free software: you can redistribute it and/or modify it  *
 * under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation, either version 3 of the License, or   *
 * (at your option) any later version.                                 *
 *                                                                     *
 * libindi is distributed in the hope that it will be useful, but      *
 * WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 * See the GNU General Public License for more details.                *
 *                                                                     *
 * You should have received a copy of the GNU General Public License   *
 * along with libindi.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                     *
 **********************************************************************/

#include <sstream>
#include <stdexcept>

#include <libindi/version.hpp>
#include <libindi/indi.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace indi;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
