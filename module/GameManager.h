// GameManager.h
#pragma once
#include <cstdint>
#include <numeric>

#include "Direct.h" 
#include "DynamicPad.h" 
#include "Offsets.h"
#include "VTable.h"

#include "Player.h"

namespace SDK
{
	namespace Manager
	{
		class _GameManager
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint64_t, pControllerList, 0x70 );
			};  

			auto ControllerList( ) -> std::uint64_t
			{
				return this->pControllerList - 0x4A;
			}

			auto Controller( auto idx ) -> SDK::Player::_Entity*
			{
				return *reinterpret_cast< SDK::Player::_Entity** >( ( this->ControllerList( ) + ( idx * 8i64 ) ) );
			}
		};

		auto GetGameManager( ) -> _GameManager*  
		{ 
			return reinterpret_cast< _GameManager* >( std::rotl( *( uint64_t* ) ( Direct::ImageBase( ) + Offsets::GameManager ) - 0x24, 0x1A ) );
		}
	} 

	inline Manager::_GameManager* GameManager;
}