//
//  BoxObjectBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _BoxObjectBlock_h
#define _BoxObjectBlock_h

#include "MeshBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class BoxObjectBlock : public MeshBlock {
		
	public:
		
		BoxObjectBlock() {
			type = "generic-mesh";
			name = "\"Box\"";
		}
		
		void flush(BufferStream& stream) {
			
			static const float vertex[][3] = {
				{  0.5f,  0.5f,  0.5f },
				{  0.5f, -0.5f,  0.5f },
				{ -0.5f, -0.5f,  0.5f },
				{ -0.5f,  0.5f,  0.5f },
				
				{ -0.5f,  0.5f, -0.5f },
				{ -0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f, -0.5f },
				{  0.5f,  0.5f, -0.5f }
			};
			
			static const int index[][3] = {
				{ 0, 3, 2 },
				{ 0, 2, 1 },
				
				{ 2, 3, 4 },
				{ 2, 4, 5 },
				
				{ 3, 0, 7 },
				{ 3, 7, 4 },
				
				{ 0, 1, 6 },
				{ 0, 6, 7 },
				
				{ 1, 2, 5 },
				{ 1, 5, 6 },
				
				{ 5, 4, 7 },
				{ 5, 7, 6 }
			};
			
			stream.push("object");
			stream.write("shader", shader);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("type", type);
			stream.write("name", name);
			stream.write("points", 8);
			
			for (int i = 0; i < 8; i++) {
				stream.write("", vertex[i][0], vertex[i][1], vertex[i][2]);
			}
			
			stream.write("triangles", 12);
			
			for (int i = 0; i < 12; i++) {
				stream.write("", index[i][0], index[i][1], index[i][2]);
			}
			
//			stream.write("normals", "vertex");
//			for (int i = 0; i < 8; i++) {
//				stream.write("", vertex[i][0], vertex[i][1], vertex[i][2]);
//			}
			
			stream.write("normals", "none");
			stream.write("uvs", "none");
			stream.pop();
		}
	};
}

#endif
