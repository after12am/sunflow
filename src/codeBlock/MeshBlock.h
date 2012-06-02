//
//  MeshBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _MeshBlock_h
#define _MeshBlock_h

#include "BaseBlock.h"
#include <vector.h>

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

#endif
