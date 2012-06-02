//
//  SphereBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _SphereBlock_h
#define _SphereBlock_h

#include "MeshBlock.h"
#include "BufferStream.h"

class SphereBlock : public MeshBlock {
	
public:
	
	SphereBlock(const string _name) {
		type = "sphere";
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
		stream.pop();
	}
};

#endif
