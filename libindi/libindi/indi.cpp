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

module indi;

import <ostream>;
import <stdexcept>;

namespace indi {

auto say_hello(std::ostream& o, std::string_view n) -> void
{
	if (n.empty())
		throw std::invalid_argument{"empty name"};

	o << "Hello, " << n << "!\n";
}

} // namespace indi
