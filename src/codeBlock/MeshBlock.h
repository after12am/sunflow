//
//  MeshBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _MeshBlock_h
#define _MeshBlock_h

#include "sunflow.h"
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
			type = "generic-mesh";
			name = "generic-mesh";
			shader = SHADER_NONE;
			m.makeScaleMatrix(0.001, 0.001, 0.001);
		}
	};
}


namespace sf {
	
	class BoxObjectBlock : public MeshBlock {
		
	public:
		
		BoxObjectBlock() {
			type = "generic-mesh";
			name = "\"Box\"";
		}
		
		~BoxObjectBlock() {
			
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
		
		~BoxInstanceBlock() {
			
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


namespace sf {
	
	class PlaneObjectBlock : public MeshBlock {
		
	public:
		
		vec3f p;
		vec3f n;
		
		PlaneObjectBlock() {
			type = "object";
		}
		
		~PlaneObjectBlock() {
			
		}
		
		void flush(BufferStream& stream)
		{
			stream.push("object");
			stream.write("shader", shader);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("type", "plane");
			stream.write("p", p.x, p.y, p.z);
			stream.write("n", n.x, n.y, n.z);
			stream.pop();
		}
	};
}


namespace sf {
	
	class SphereObjectBlock : public MeshBlock {
		
	public:
		
		SphereObjectBlock() {
			type = "object";
			name = "sphere";
			m.makeScaleMatrix(1, 1, 1);
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("object");
			stream.write("shader", shader);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("type", "sphere");
			stream.write("name", name);
			stream.pop();
		}
	};
}


namespace sf {
	
	class QuadsObjectBlock : public MeshBlock {
		
	public:
		
		QuadsObjectBlock() {
			name = "\"Quads\"";
			type = "generic-mesh";
			m.makeScaleMatrix(1, 1, 1);
		}
		
		~QuadsObjectBlock() {
			
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("object");
			stream.write("shader", shader);
			stream.write("transform col");
			
			for (int i = 0; i < 16; i = i + 4) {
				stream.write("", m.getPtr()[i], m.getPtr()[i + 1], m.getPtr()[i + 2], m.getPtr()[i + 3]);
			}
			
			stream.write("type", type);
			stream.write("name", "\"Quads\"");
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
}

#endif
