//
//  DiffuseShader.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _DiffuseShader_h
#define _DiffuseShader_h

#include "sunflow.h"
#include "ShaderBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class DiffuseShader : public ShaderBlock {
		
	protected:
		
		Color diffuse;
		
	public:
		
		DiffuseShader(const string _name, const Color _diffuse, const string _colorSpace = "internal") {
			type = "diffuse";
			name = _name;
			diffuse = _diffuse;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			stream.push("shader");
			stream.write("name", name);
			stream.write("type", type);
			
			if (colorSpace == COLORSPACE_SRGB_INTERNAL) {
				stream.write("diff", diffuse.r, diffuse.g, diffuse.b);
			} else {
				// sRGB nonlinear
				// sRGB linear
				// XYZ
				stream.push("diff");
				stream.write("\"" + colorSpace + "\"", diffuse.r, diffuse.g, diffuse.b);
				stream.pop();
			}
			
			stream.pop();
		}
		
		Color getColor() {
			return diffuse;
		}
	};
}

#endif
