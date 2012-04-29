//
//  GLRenderer.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _GLRenderer_h
#define _GLRenderer_h

#include "sunflow.h"

namespace sf {
	
	class GLRenderer {
		
		
	public:
		GLRenderer() {
			
		}
		
		~GLRenderer() {
			
		}
		
		int getWindowWidth();
		int getWindowHeight();
		
		void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far);
	};
}

#endif
