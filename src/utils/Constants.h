//
//  Constants.h
//  quickExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _Constants_h
#define _Constants_h

#define IMPL printf("[FUNCTION NOT IMPLEMENTED YET] %s\n", __PRETTY_FUNCTION__); exit(1);
#define DEFAULT_FRAME_RATE 30

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
#endif
