//
//  PlaneObjectBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _PlaneObjectBlock_h
#define _PlaneObjectBlock_h

#include "MeshBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class PlaneBlock : public MeshBlock {
		
	public:
		
		vec3f p;
		vec3f n;
		
		PlaneBlock(const string _name) {
			type = "plane";
			name = _name;
		}
		
		void flush(BufferStream& stream) {
			stream.push("object");
			stream.write("shader", shader);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("type", type);
			stream.write("p", p.x, p.y, p.z);
			stream.write("n", n.x, n.y, n.z);
			stream.pop();
		}
	};
}

#endif
