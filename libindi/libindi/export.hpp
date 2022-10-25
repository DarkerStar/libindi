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

#pragma once

// Normally we don't export class templates (but do complete specializations),
// inline functions, and classes with only inline member functions. Exporting
// classes that inherit from non-exported/imported bases (e.g., std::string)
// will end up badly. The only known workarounds are to not inherit or to not
// export. Also, MinGW GCC doesn't like seeing non-exported functions being
// used before their inline definition. The workaround is to reorder code. In
// the end it's all trial and error.

#if defined(LIBINDI_STATIC)         // Using static.
#  define LIBINDI_SYMEXPORT
#elif defined(LIBINDI_STATIC_BUILD) // Building static.
#  define LIBINDI_SYMEXPORT
#elif defined(LIBINDI_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBINDI_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBINDI_SYMEXPORT
#  endif
#elif defined(LIBINDI_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBINDI_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBINDI_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared libraries
// provided the library only exports functions (in other words, no global
// exported data) and for the shared case the result will be sub-optimal
// compared to having dllimport. If, however, your library does export data,
// then you will probably want to replace the fallback with the (commented
// out) error since it won't work for the shared case.
//
#  define LIBINDI_SYMEXPORT         // Using static or shared.
//#  error define LIBINDI_STATIC or LIBINDI_SHARED preprocessor macro to signal libindi library type being linked
#endif
