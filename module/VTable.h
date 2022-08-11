// VTable.h
#pragma once

#include <cstdint>
#include "Memory.h"

namespace VTable
{
	auto estimate_count( std::uint64_t* vmt ) -> size_t
	{
		auto method_count = 0;
		for ( auto idx = 0;; method_count++, idx++ ) { if ( !vmt[ idx ] ) break; }

		return method_count;
	}

	struct Table
	{
		template <size_t idx, typename T> auto get_idx( ) const noexcept -> const T
		{
			return reinterpret_cast< const T* >( this )[ idx ];
		}

		template <size_t off, typename T> auto get_off( ) const noexcept -> const T
		{
			return *reinterpret_cast< const T* >( reinterpret_cast< std::uintptr_t >( this ) + off );
		}
	};
}