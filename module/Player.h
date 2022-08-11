// Player.h
#pragma once
#include <cstdint>
#include <numeric>

#include "Direct.h" 
#include "DynamicPad.h" 
#include "Offsets.h"
#include "VTable.h"

namespace SDK
{ 
	namespace Player
	{
		class _PawnComponent;
		class _ActorDescriptor;
		class _WeaponManager;

		class _Entity
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint64_t, pPawnComponent, 0x38 );
			};

			auto PawnComponent( ) -> _PawnComponent*  
			{
				if ( !this->pPawnComponent )
					return {};

				return reinterpret_cast< _PawnComponent* >( ( ( this->pPawnComponent - 0x46 ) ^ 0x7F ) + 0x4B10EB6F874EE4C7 );
			} 
		};

		class _PawnComponent
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint64_t, pActorDescriptor, 0x18 );
			};

			auto ActorDescriptor( ) -> _ActorDescriptor*  
			{
				if ( !this->pActorDescriptor )
					return {};

				return reinterpret_cast< _ActorDescriptor* >( ( ( this->pActorDescriptor - 0x64 ) ^ 0x47A9D613D41EBE75 ) - 0x12 );
			} 
		};

		class _ActorDescriptor // base entity
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint64_t, pComponentList, 0xD8 );  
				MEMBER( std::uint8_t, pComponentListSize, 0xE0 );  
				MEMBER( std::uint8_t, pWeaponIndex, 0x221 ); 
			};
			 
			auto GetComponent( std::uint8_t idx ) -> std::uint64_t
			{
				if ( idx > this->pComponentListSize )
					return {};

				return *( std::uint64_t* ) ( this->pComponentList + ( idx * sizeof( std::uint64_t ) ) );
			}

			auto ActiveWeapon( ) -> _WeaponManager*  
			{     
				auto CurrentWeapon = std::rotl( *( std::uint64_t* ) ( ( *( std::uint64_t* ) ( ( *( std::uint64_t* ) ( ( *( uint64_t* ) ( this->GetComponent( this->pWeaponIndex ) + 0x68 ) ^ 0x4310901AECDBC648i64 ) + 0x702BB7122605A1Ci64 ) ) + 0x1B0 ) ) + 0x268 ) - 0x6B88C874D9CB6D0Ai64, 0x2E ) - 0x8855542A312108Bi64; // Lets not talk about this...
				
				if ( !CurrentWeapon )
					return { }; 

				return reinterpret_cast< _WeaponManager* >( CurrentWeapon );
			} 
		};

		class _WeaponManager
		{
		public:
			union
			{
				VTable::Table* vtable;
				MEMBER( std::uint32_t, pWeaponSpread, 0x30 );
			};

			auto Shoot( ) -> void	// Shoot Wrapper
			{
				reinterpret_cast						// call
					< void( __fastcall* )( __int64 ) >	// declaration
					( Direct::ImageBase( ) + 0x788690 )	// address
					( ( __int64 ) this );				// parameter
			}
			auto SetSpread( std::uint32_t value ) ->void
			{
				this->pWeaponSpread = std::rotr<uint32_t>( std::rotr<uint32_t>( *( uint32_t* ) ( &value ), 24 ) + 1992768509, 1 );
			}
		};
	}
}
