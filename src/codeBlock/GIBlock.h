//
//  GIBlock.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _GIBlock_h
#define _GIBlock_h

#include "BaseBlock.h"
#include "sunflow.h"

namespace sf {
	
	class GIBlock : public BaseBlock {
		
	public:
		
		GIBlock() {
			type = "gi";
			name = "gi";
		}
	};
}

namespace sf {
	
	class AmbientOcclusionBlock : public GIBlock {
		
	public:
		
		Color bright;
		Color dark;
		int samples;
		float maxdist;
		string colorSpace;
		
		AmbientOcclusionBlock(Color _bright, Color _dark, int _samples, float _maxdist, string _colorSpace) {
			
			bright = _bright;
			dark = _dark;
			samples = _samples;
			maxdist = _maxdist;
			colorSpace = _colorSpace;
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("gi");
			stream.write("type", "ambocc");
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
