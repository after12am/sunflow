//
//  ShaderBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _ShaderBlock_h
#define _ShaderBlock_h

#include "BaseBlock.h"
#include "sunflow.h"

namespace sf {
	
	class ShaderBlock : public BaseBlock {
		
	public:
		
		string colorSpace;
		
		ShaderBlock() {
			type = "shader";
			name = SHADER_NONE;
		}
		
		virtual Color getColor() = 0;
	};
}

namespace sf {
	
	class DiffuseShader : public ShaderBlock {
		
	public:
		
		Color diffuse;
		
		DiffuseShader(const string _name, const Color _diffuse, const string _colorSpace) {
			
			name = _name;
			diffuse = _diffuse;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("shader");
			stream.write("name", name);
			stream.write("type", "diffuse");
			
			if (colorSpace != "") {
				stream.push("diff");
				stream.write("\"" + colorSpace + "\"", diffuse.r, diffuse.g, diffuse.b);
				stream.pop();
			} else {
				stream.write("diff", diffuse.r, diffuse.g, diffuse.b);
			}
			
			stream.pop();
		}
		
		Color getColor() {
			return diffuse;
		}
	};
}

#endif
