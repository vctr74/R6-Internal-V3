// RoundManager.h
#pragma once
#include <cstdint>
#include <numeric>

#include "Direct.h" 
#include "DynamicPad.h" 
#include "Offsets.h"
#include "VTable.h"
 
namespace SDK
{
	enum class StateID : std::uint32_t
	{
		RoundSwap = 0,
		OperatorSelection,
		PreperationPhase,
		ActionPhase,
		RoundEnd,
		MainMenu
	};

	namespace Manager
	{
		class _RoundManager
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint32_t, pRoundState, 0xF8 );
			};

			auto RoundState( ) -> StateID
			{
				return static_cast< StateID >( ( ( this->pRoundState ^ 0x98A1F310 ) >> 0x6 ) - 0x27 );
			}
		};

		auto GetRoundManager( ) -> _RoundManager*
		{
			return reinterpret_cast< _RoundManager* >( std::rotl( *( std::uint64_t* ) ( Direct::ImageBase() + Offsets::RoundManager ) + 0x2C797E6189BC6F4D, 0x2D ) + 0x377614FB328C2FA0 );
		}
	}

	inline Manager::_RoundManager* RoundManager;
}