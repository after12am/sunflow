//
//  PointLightBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _PointLightBlock_h
#define _PointLightBlock_h

#include "LightBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class PointLightBlock : public LightBlock {
		
	public:
		
		vec3f position;
		Color color;
		float power;
		
		PointLightBlock(const vec3f _position, const Color _color, const float _power, const string _colorSpace) {
			type = "point";
			position = _position;
			color = _color;
			power = _power;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			stream.push("light");
			stream.write("type", type);
			stream.push("color");
			stream.write("\"" + colorSpace + "\"", color.r, color.g, color.b);
			stream.pop();
			stream.write("power", power);
			stream.write("p", position.x, position.y, position.z);
			stream.pop();
		}
	};
}

#endif
