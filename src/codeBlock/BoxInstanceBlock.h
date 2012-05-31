//
//  BoxInstanceBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _BoxInstanceBlock_h
#define _BoxInstanceBlock_h

#include "MeshBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class BoxInstanceBlock : public MeshBlock {
		
	protected:
		
		string geometry;
		
	public:
		
		BoxInstanceBlock() {
			type = "instance";
			name = "\"Box\"";
			geometry = "\"Box\"";
			m.makeScaleMatrix(1, 1, 1);
		}
		
		void flush(BufferStream& stream) {
			stream.push("instance");
			stream.write("name", name);
			stream.write("geometry", geometry);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("shader", shader);
			stream.pop();
		}
	};
}

#endif
