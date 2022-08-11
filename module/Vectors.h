#pragma once

#include <cstdint>
#include <xmmintrin.h>
#include <math.h>

namespace std
{
	class vec2_t
	{
	public:
		float x, y;

		inline vec2_t( )
		{
			x = y = 0.f;
		}

		inline vec2_t( float _x, float _y )
		{
			x = _x; y = _y;
		}
	};

	class vec3_t
	{
	public:
		float x, y, z;

		inline vec3_t( )
		{
			x = y = z = 0.f;
		}

		inline vec3_t( float _x, float _y, float _z )
		{
			x = _x; y = _y; z = _z;
		}

		vec3_t operator-( vec3_t v )
		{
			vec3_t ret;
			ret.x = this->x - v.x;
			ret.y = this->y - v.y;
			ret.z = this->z - v.z;
			return ret;
		}
		vec3_t operator*( float f )
		{
			vec3_t ret;
			ret.x = this->x * f;
			ret.y = this->y * f;
			ret.z = this->z * f;
			return ret;
		}

		vec3_t operator-( float f )
		{
			vec3_t ret;
			ret.x = this->x - f;
			ret.y = this->y - f;
			ret.z = this->z - f;
			return ret;
		}

		vec3_t operator/( float f )
		{
			vec3_t ret;
			ret.x = this->x / f;
			ret.y = this->y / f;
			ret.z = this->z / f;
			return ret;
		}

		void normalize( )
		{
			while ( this->x > 180.0f ) {
				this->x -= 360.0f;
			}
			while ( this->x < -180.0f ) {
				this->x += 360.0f;
			}
			while ( this->y > 180.0f ) {
				this->y -= 360.0f;
			}
			while ( this->y < -180.0f ) {
				this->y += 360.0f;
			}
			this->z = 0.0f;
		}

		inline float dot( vec3_t v )
		{
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}

		inline float angle( vec3_t dst )
		{
			float _x = this->x - dst.x; //calculating number to square in next step
			float _y = this->y - dst.y;
			float dist;

			dist = pow( _x, 2 ) + pow( _y, 2 );       //calculating Euclidean distance
			dist = sqrt( dist );

			return dist;
		}
	};

	class vec4_t
	{
	public:
		float x, y, z, w;

		inline vec4_t( )
		{
			x = y = z = w = 0.f;
		}

		inline vec4_t( float _x, float _y, float _z, float _w )
		{
			x = _x; y = _y; z = _z; w = _w;
		}
	};
}
 
