//
//  MeshBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _MeshBlock_h
#define _MeshBlock_h

#include "BaseBlock.h"
#include <vector.h>


namespace sf {
	
	class MeshBlock : public BaseBlock {
		
	public:
		
		vector<vec3f> vertices;
		vector<vec3f> indices;
		vector<vec3f> norms;
		string shader;
		matrix4x4 m;
		
		MeshBlock() {
			shader = "none";
			m.makeScaleMatrix(0.001, 0.001, 0.001);
		}
	};
}

#endif
