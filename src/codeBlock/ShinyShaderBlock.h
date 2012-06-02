//
//  ShinyShaderBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _ShinyShaderBlock_h
#define _ShinyShaderBlock_h

#include "DiffuseShader.h"
#include "BufferStream.h"

class ShinyShaderBlock : public DiffuseShader {
	
public:
	
	// 元の色の反射割合を示す反射係数
	// 0 反射しない 1 全反射
	float refl;
	
	
	ShinyShaderBlock(const string _name, const Color _diffuse, const float _refl, const string _colorSpace = "internal") : DiffuseShader(_name, _diffuse, _colorSpace) {
		type = "shiny";
		refl = _refl;
	}
	
	void flush(BufferStream& stream) {
		stream.push("shader");
		stream.write("name", name);
		stream.write("type", type);
		
		if (colorSpace == "internal") {
			stream.write("diff", diffuse.r, diffuse.g, diffuse.b);
		} else {
			// sRGB nonlinear
			// sRGB linear
			// XYZ
			stream.push("diff");
			stream.write("\"" + colorSpace + "\"", diffuse.r, diffuse.g, diffuse.b);
			stream.pop();
		}
		
		stream.write("refl", refl);
		stream.pop();
	}
};

#endif
