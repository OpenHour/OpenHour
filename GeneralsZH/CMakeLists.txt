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
add_executable(GeneralsZH WIN32)

set_target_properties(GeneralsZH PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/GeneralsZH/bin")

add_subdirectory(GameEngine)
add_subdirectory(GameEngineDevice)
add_subdirectory(Libraries)
add_subdirectory(Main)

target_include_directories(GeneralsZH PRIVATE
        ${D3D8_INCLUDE_DIR})

target_link_directories(GeneralsZH PRIVATE
        ${D3D8_LIBRARIES}
        ${D3D9_LIBRARIES})

target_link_libraries(GeneralsZH PRIVATE
        Imm32
        ddraw
        dxguid
        dinput8
        d3d8
        d3dx8
        Version
        Vfw32
        WS2_32
        Winmm
        Wmvcore

        zlib
        LZHL::LZHL
        cityhash::cityhash)