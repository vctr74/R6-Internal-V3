// SDK.h
#include "GameManager.h"
#include "RoundManager.h"
 
namespace SDK
{
	namespace Manager
	{
		auto InitializeManagers( ) -> BOOL
		{
			SDK::RoundManager = GetRoundManager( ); 
			if ( !SDK::RoundManager )
			{
				MessageBoxA( 0, x( "RoundManager Invalid" ), x( "InitializeManagers" ), MB_ICONERROR );
				return FALSE;
			}

			SDK::GameManager = GetGameManager( );
			if ( !SDK::GameManager )
			{
				MessageBoxA( 0, x( "GameManager Invalid" ), x( "InitializeManagers" ), MB_ICONERROR );
				return FALSE;
			}
			return TRUE;
		}
	}  
}
