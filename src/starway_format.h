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

struct StarwayEntry
{
public:

    // Lsb is set if black to move
    // Highest 7 bits are halfmove clock
    std::uint8_t stmAndHalfmoveClock;

    std::uint64_t occupied;

    // 4 bits per piece for a max of 32 pieces
    // Lsb is set if piece color is black, other 3 bits is piece type (0-5 including both)
    unsigned __int128 pieces;

    // Kings and queens squares (64 if 0 colored queens, 65 if >1 colored queens)
    std::uint8_t wkSq, bkSq, wqSq, bqSq;

    std::int16_t stmScore;
    std::int8_t stmResult; // -1, 0, 1

} __attribute__((packed));

static_assert(sizeof(StarwayEntry) == 32);

}
