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

#undef NDEBUG
#include <cassert>

import <sstream>;
import <stdexcept>;

import indi;

auto main() -> int
{
	// Basics.
	//
	{
		auto o = std::ostringstream{};
		indi::say_hello(o, "World");
		assert(o.str() == "Hello, World!\n");
	}

	// Empty name.
	//
	try
	{
		auto o = std::ostringstream{};
		indi::say_hello(o, "");
		assert (false);
	}
	catch (std::invalid_argument const& e)
	{
		assert(e.what() == std::string{"empty name"});
	}
}
