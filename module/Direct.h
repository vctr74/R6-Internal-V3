// Direct.h
#pragma once
#include <cstdint>

namespace Direct
{  
	auto ImageBase( ) -> std::uint64_t
	{
		return ( std::uint64_t ) GetModuleHandleW( NULL ); // Detected
	}
}
