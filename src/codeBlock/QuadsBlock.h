//
//  QuadsBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _QuadsBlock_h
#define _QuadsBlock_h

#include "MeshBlock.h"
#include "BufferStream.h"

class QuadsBlock : public MeshBlock {
	
public:
	
	QuadsBlock(const string _name) {
		type = "generic-mesh";
		name = _name;
		m.makeScaleMatrix(1, 1, 1);
	}
	
	void flush(BufferStream& stream) {
		stream.push("object");
		stream.write("shader", shader);
		stream.write("transform col");
		
		for (int i = 0; i < 16; i = i + 4) {
			stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
		}
		
		stream.write("type", type);
		stream.write("name", name);
		stream.write("points", int(vertices.size()));
		
		for (int i = 0; i < vertices.size(); i++) {
			stream.write("", vertices[i].x, vertices[i].y, vertices[i].z);
		}
		
		stream.write("triangles", int(vertices.size() - 2));
		
		for (int i = 1; i < vertices.size() - 1; i++) {
			stream.write("", 0, i, i + 1);
		}
		
		stream.write("normals", "none");
		stream.write("uvs", "none");
		stream.pop();
	}
};

#endif
