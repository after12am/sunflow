//
//  Constants.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _Constants_h
#define _Constants_h

#define IMPL printf("[FUNCTION NOT IMPLEMENTED YET] %s\n", __PRETTY_FUNCTION__); exit(1);
#define FRAME_RATE 30

// relative path from bin directory
#define SUNFLOW_FILE_PATH "../../../lib"
#define SUNFLOW_COMMAND "sunflow"
#define SUNFLOW_SC ".sc"


// contribute
#include "ofMath.h"
#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"
#include "ofQuaternion.h"
#include "ofMatrix3x3.h"
#include "ofMatrix4x4.h"

namespace sf {
	
	// set alias
	typedef ofVec2f vec2f;
	typedef ofVec3f vec3f;
	typedef ofVec4f vec4f;
	typedef ofQuaternion quaternion;
	typedef ofMatrix3x3 matrix3x3;
	typedef ofMatrix4x4 matrix4x4;
}

namespace sf {
	
	class Color {
		
	public:
		
		float r;
		float g;
		float b;
		float a;
		
		Color(const float _r = 0.f, const float _g = 0.f, const float _b = 0.f, const float _a = 0.f) {
			r = _r;
			g = _g;
			b = _b;
			a = _a;
		}
	};
}

#endif
