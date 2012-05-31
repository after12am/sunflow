//
//  ImageBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _ImageBlock_h
#define _ImageBlock_h

#include "BaseBlock.h"
#include "BufferStream.h"

namespace sf {
	
	class ImageBlock : public BaseBlock {
		
	private:
		
		// This affects the point at which the renderer decides to adaptively refine between four pixels 
		// when doing adaptive anti-aliasing.
		// contrast isn't required and the default is usually the right setting.
		float contrast;
		
		
		// Jitter should be turned off (false) when doing animations.
		// because the randomness of jitter makes it very obvious it's on when moving from frame to frame.
		bool jitter;
		
		
	public:
		
		// image size
		vec2f resolution;
		
		
		// anti-aliasing
		// A value of  0 corresponds to 1  sample per pixel. 
		// A value of -1 corresponds to 1  sample every 2 pixels (1 per 2x2 block) 
		// A value of -2 corresponds to 1  sample every 4 pixels (1 per 4x4 block) 
		// A value of -3 corresponds to 1  sample every 8 pixels (1 per 8x8 block)
		// A value of  1 corresponds to 4  samples per pixel (2x2 subpixel grid) 
		// A value of  2 corresponds to 16 samples per pixel (4x4 subpixel grid) 
		// A value of  3 corresponds to 64 samples per pixel (8x8 subpixel grid)
		int aaMin;
		int aaMax;
		
		
		// When used, samples indirectly affect many aspects of the scene,
		// but they directly affect three camera types.
		// 
		//   1 depth of field(dof) camera
		//   2 camera motion blur
		//   3 object motion blur
		// 
		// For getting a smooth results, you try to incluse samples.
		// http://sfwiki.geneome.net/index.php5?title=Image#Samples
		// http://sfwiki.geneome.net/index.php5?title=Cameras#Thinlens
		// http://sfwiki.geneome.net/index.php5?title=Cameras#Camera Motion Blur
		int samples;
		
		
		// Triangle and box are better for previews since they are faster. 
		// The other filters are recommended for final image rendering 
		// (my personal favorite is mitchell).
		// 
		// box             (filter size = 1)
		// triangle        (filter size = 2)
		// gaussian        (filter size = 3)
		// mitchell        (filter size = 4)
		// catmull-rom     (filter size = 4)
		// blackman-harris (filter size = 4)
		// sinc            (filter size = 4) 
		// lanczos         (filter size = 4)
		// bspline         (filter size = 4)
		string filter;
		
		
		ImageBlock(const int _aaMin = 0, const int _aaMax = 0, const int _samples = 4, const string _filter = "triangle") {
			aaMin = _aaMin;
			aaMax = _aaMax;
			samples = _samples;
			// strongly recommend not to change another parameter.
			contrast = 0.1f;
			filter = _filter;
			jitter = false;
		}
		
		void flush(BufferStream& stream) {
			stream.push("image");
			stream.write("resolution", resolution.x, resolution.y);
			stream.write("aa", aaMin, aaMax);
			stream.write("samples", samples);
			stream.write("contrast", contrast);
			stream.write("filter", filter);
			stream.write("jitter", jitter ? "true" : "false");
			stream.pop();
		}
	};
}

#endif
