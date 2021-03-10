// libtermcolor: termcolor.h
// Copyright (C) 2021 Ethan Uppal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef _LIBTERMCOLOR_TERMCOLOR_H
#define _LIBTERMCOLOR_TERMCOLOR_H

#include <stdbool.h>
#include <stdio.h>

// A type describing an libtermcolor error. These are the only value returned by
// the tcol_fprintf and tcol_printf functions. You may assume any nonzero value
// is an error and use tcol_errorstr to display a diagnostic.
enum term_color_error_t {
    TermColorErrorNone = 0,
    TermColorErrorAllocationFailed = 1,
    TermColorErrorPrintingFailed = 2,
    TermColorErrorInvalidColor = 3,
    TermColorErrorUnterminatedColor = 4,
    TERM_COLOR_ERROR_COUNT
};

// Returns a human-readable string describing the given libtermcolor error.
const char* tcol_errorstr(const enum term_color_error_t err);

// By default libtermcolor will use color. However this behavior can be manually
// overridden using this function.
void tcol_override_color_checks(bool enable_color);

// Printfs the colorized format string to the specified stream.
int tcol_fprintf(FILE* stream, const char* fmt, ...);

// Printfs the colorized format string to the standard output.
int tcol_printf(const char* fmt, ...);

#endif /* _LIBTERMCOLOR_TERMCOLOR_H */
