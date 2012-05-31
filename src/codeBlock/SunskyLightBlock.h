//
//  SunskyLightBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _SunskyLightBlock_h
#define _SunskyLightBlock_h

#include "LightBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class SunskyLightBlock : public LightBlock {
		
		// sunsky is similar to image-based lighting, 
		// but sunsky does not require image.
		
	public:
		
		// 
		// There isn't a setting in the syntax that controls sun intensity, 
		// but you can instead control the suns direction in terms of angle to the object. 
		// So if the Sunsky direction is at a near 0 degree angle with the object (the sun on the horizon),
		// it will be dark and the sky will be more a sunset color. 
		// If the direction is more high in the sky at around 80 degrees,
		// it will be bright with the sky being white/blue. 
		// Changing the up and east values can also change the look, 
		// but these are more used to change how the Sunsky is 
		// interpreted in different world spaces which might be required in different applications. 
		// 
		// The up and east values in the below example usually work for everyone.
		// 
		// light {
		//   type sunsky
		//   up 0 0 1
		//   east 0 1 0
		//   sundir 0.5 0.2 0.8
		//   turbidity 6.0
		//   samples 128
		// }
		// 
		// see more. http://sfwiki.geneome.net/index.php5?title=Lights#Sunsky
		// 
		
		vec3f up;
		vec3f east;
		vec3f sundir;
		float turbidity;
		int samples;
		
		SunskyLightBlock(const vec3f _up, const vec3f _east, const vec3f _direction, const int _samples, const float _turbidity) {
			type = "sunsky";
			up = _up;
			east = _east;
			sundir = _direction;
			samples = _samples;
			turbidity = _turbidity;
		}
		
		void flush(BufferStream& stream) {
			stream.push("light");
			stream.write("type", type);
			stream.write("up", up.x, up.y, up.z);
			stream.write("east", east.x, east.y, east.z);
			stream.write("sundir", sundir.x, sundir.y, sundir.z);
			stream.write("turbidity", turbidity);
			stream.write("samples", samples);
			stream.pop();
		}
	};
}

#endif
