/*
**	Copyright 2025 OpenHour Contributors & Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// FILE: Compression.h ///////////////////////////////////////////////////////
// Author: Matthew D. Campbell
//////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __COMPRESSION_H__
#define __COMPRESSION_H__

enum CompressionType
{
	COMPRESSION_MIN = 0,
	COMPRESSION_NONE = COMPRESSION_MIN,
	COMPRESSION_REFPACK,
	COMPRESSION_MAX = COMPRESSION_REFPACK,
	COMPRESSION_NOXLZH,
	COMPRESSION_ZLIB1,
	COMPRESSION_ZLIB2,
	COMPRESSION_ZLIB3,
	COMPRESSION_ZLIB4,
	COMPRESSION_ZLIB5,
	COMPRESSION_ZLIB6,
	COMPRESSION_ZLIB7,
	COMPRESSION_ZLIB8,
	COMPRESSION_ZLIB9,
	COMPRESSION_BTREE,
	COMPRESSION_HUFF,
};

class CompressionManager
{
public:

	static bool isDataCompressed( const void *mem, int len );
	static CompressionType getCompressionType( const void *mem, int len );

	static int getMaxCompressedSize( int uncompressedLen, CompressionType compType );
	static int getUncompressedSize( const void *mem, int len );

	static int compressData( CompressionType compType, void *src, int srcLen, void *dest, int destLen ); // 0 on error
	static int decompressData( void *src, int srcLen, void *dest, int destLen ); // 0 on error

	static const char *getCompressionNameByType( CompressionType compType );

	// For perf timers, so we can have separate ones for compression/decompression
	static const char *getDecompressionNameByType( CompressionType compType );

	static CompressionType getPreferredCompression( void );
};

#endif // __COMPRESSION_H__
