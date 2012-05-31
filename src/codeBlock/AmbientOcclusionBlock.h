//
//  AmbientOcclusionBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _AmbientOcclusion_h
#define _AmbientOcclusion_h

#include "GlobalIlluminationBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class AmbientOcclusionBlock : public GlobalIlluminationBlock {
		
	public:
		
		Color bright;
		Color dark;
		int samples;
		float maxdist;
		string colorSpace;
		
		AmbientOcclusionBlock(const Color _bright, const Color _dark, const int _samples, const float _maxdist, const string _colorSpace) {
			type = "ambocc";
			bright = _bright;
			dark = _dark;
			samples = _samples;
			maxdist = _maxdist;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			stream.push("gi");
			stream.write("type", type);
			stream.push("bright");
			stream.write("\"" + colorSpace + "\"", bright.r, bright.g, bright.b);
			stream.pop();
			stream.push("dark");
			stream.write("\"" + colorSpace + "\"", dark.r, dark.g, dark.b);
			stream.pop();
			stream.write("samples", samples);
			stream.write("maxdist", maxdist);
			stream.pop();
		}
	};
}

#endif
