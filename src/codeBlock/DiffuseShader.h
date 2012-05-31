//
//  DiffuseShader.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _DiffuseShader_h
#define _DiffuseShader_h

#include "ShaderBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class DiffuseShader : public ShaderBlock {
		
	protected:
		
		Color diffuse;
		
	public:
		
		DiffuseShader(const string _name, const Color _diffuse, const string _colorSpace = "") {
			type = "diffuse";
			name = _name;
			diffuse = _diffuse;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			stream.push("shader");
			stream.write("name", name);
			stream.write("type", type);
			
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
