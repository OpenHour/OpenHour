# Copyright 2025 Open Hour Contributors.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
add_subdirectory(zlib EXCLUDE_FROM_ALL)

# CityHash
add_library(cityhash STATIC)
add_library(cityhash::cityhash ALIAS cityhash)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cityhash/config.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cityhash/src/config.h"
        @ONLY)

target_sources(cityhash PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/cityhash/src/city.cc")

target_include_directories(cityhash PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/cityhash/src")

target_include_directories(cityhash PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}/cityhash/src")

# lzhl
add_library(lzhl
        liblzhl/include/lzhl/lzhl.h
        liblzhl/src/huff.cpp
        liblzhl/src/lz.cpp
        liblzhl/src/lzhl.cpp
        liblzhl/src/_huff.h
        liblzhl/src/_lz.h
        liblzhl/src/_lzhl.h)
add_library(LZHL::LZHL ALIAS lzhl)

target_include_directories(lzhl PUBLIC
        liblzhl/include)