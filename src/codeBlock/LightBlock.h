//
//  LightBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _LightBlock_h
#define _LightBlock_h

#include "sunflow.h"
#include "BaseBlock.h"

namespace sf {
	
	class Light : public BaseBlock {
		
		
	public:
		
		string colorSpace;
		
		Light() {
			type = "light";
			name = "light";
		}
	};
}

namespace sf {
	
	class PointLight : public Light {
		
	public:
		
		vec3f position;
		Color color;
		float power;
		
		PointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace) {
			
			position = _position;
			color = _color;
			power = _power;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& fstream) {
			
			fstream.push("light");
			fstream.write("type", "point");
			fstream.push("color");
			fstream.write("\"" + colorSpace + "\"", color.r, color.g, color.b);
			fstream.pop();
			fstream.write("power", power);
			fstream.write("p", position.x, position.y, position.z);
			fstream.pop();
		}
	};
}

#endif
