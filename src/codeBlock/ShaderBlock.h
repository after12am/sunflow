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
		
	protected:
		
		Color diffuse;
		
	public:
		
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

namespace sf {
	
	class ShinyShaderBlock : public DiffuseShader {
		
	public:
		
		// 元の色の反射割合を示す反射係数
		// 0 反射しない 1 全反射
		float refl;
		
		
		ShinyShaderBlock(const string _name, const Color _diffuse, const float _refl, const string _colorSpace) : DiffuseShader(_name, _diffuse, _colorSpace) {
			refl = _refl;
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("shader");
			stream.write("name", name);
			stream.write("type", "shiny");
			
			if (colorSpace != "") {
				stream.push("diff");
				stream.write("\"" + colorSpace + "\"", diffuse.r, diffuse.g, diffuse.b);
				stream.pop();
			} else {
				stream.write("diff", diffuse.r, diffuse.g, diffuse.b);
			}
			
			stream.write("refl", refl);
			stream.pop();
		}
	};
}

#endif
