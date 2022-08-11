// Cheat.h
#pragma once 
#include <Windows.h> // dangerous
#include <cstdint> 
#include "SDK.h"
   
namespace Cheat
{ 
	auto Run( ) -> void
	{  
		try
		{
			SDK::Manager::InitializeManagers( );

			for ( ;; Sleep( 1 ) )
			{
				auto StateID = SDK::RoundManager->RoundState( ); 
				if ( StateID == SDK::StateID::ActionPhase || StateID == SDK::StateID::PreperationPhase )
				{
					auto Controller = SDK::GameManager->Controller( 0 );
					auto ActiveWeapon = Controller->PawnComponent( )->ActorDescriptor( )->ActiveWeapon( );
					  
					if ( GetAsyncKeyState( VK_MBUTTON ) )  
						ActiveWeapon->Shoot( );

					ActiveWeapon->SetSpread( 0.0f ); 
				}
			}
		}
		catch ( ... )
		{    

		} 
	}
}