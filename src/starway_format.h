/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2025 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <cstdint>
#include <cassert>

namespace Stockfish {

struct __attribute__((packed)) StarwayEntry
{
public:

    bool isWhiteStm;

    std::uint64_t occupied;

    // 4 bits per piece for a max of 32 pieces
    // lsb of the 4 bits is piece color, other 3 bits is piece type
    unsigned __int128 pieces;

    std::uint8_t whiteKingSquare, blackKingSquare, whiteQueenSquare, blackQueenSquare;

    std::int16_t stmScore;

    std::int8_t stmWdl; // -1, 0, 1 for loss, draw, win, respectively
};

static_assert(sizeof(StarwayEntry) == 32);

}
