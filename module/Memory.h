// Memory.h
#pragma once
#include <cstdint>

namespace Memory
{
	inline bool CheckValid( std::uint64_t ptr )
	{
		return ( ptr > 0x00010000 && ptr < 0x7FFFFFFEFFFF );
	}
}