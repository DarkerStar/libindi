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

import <cstring>;
import <type_traits>;

import indi;

auto main() -> int
{
	// indi::lib_version
	assert((std::is_same_v<std::remove_cvref_t<decltype(indi::lib_version)>, unsigned long long>));

	// indi::lib_version_major
	// indi::lib_version_minor
	// indi::lib_version_patch
	assert(indi::lib_version_major >= 0);
	assert(indi::lib_version_minor >= 0);
	assert(indi::lib_version_patch >= 0);

	// indi::lib_version_str
	assert(indi::lib_version_str != nullptr);
	assert(std::strlen(indi::lib_version_str) > 0);

	// indi::lib_version_full
	assert(indi::lib_version_full != nullptr);
	assert(std::strlen(indi::lib_version_full) > 0);
}
