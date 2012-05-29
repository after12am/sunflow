//
//  CameraBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _CameraBlock_h
#define _CameraBlock_h

#include "BaseBlock.h"
#include "sunflow.h"


// abstract camera class
namespace sf {
	
	class CameraBlock : public BaseBlock {
		
	public:
		
		CameraBlock() {
			type = "camera";
			name = "camera";
		}
	};
}

// pinhole camera
namespace sf {
	
	class PinholeCameraBlock : public CameraBlock {
		
	public:
		
		vec3f eye;
		vec3f target;
		vec3f up;
		float fov;
		float aspect;
		
		PinholeCameraBlock(const vec3f _eye, const vec3f _target, const vec3f _up, const float _fov, const float _aspect) {
			
			name = "pinhole";
			eye = _eye;
			target = _target;
			up = _up;
			fov = _fov;
			aspect = _aspect;
		}
		
		void flush(BufferStream& stream) {
			
			stream.push("camera");
			stream.write("type", name);
			stream.write("eye", eye.x, eye.y, eye.z);
			stream.write("target", target.x, target.y, target.z);
			stream.write("up", up.x, up.y, up.z);
			stream.write("fov", fov);
			stream.write("aspect", aspect);
			stream.pop();
		}
	};
}

#endif
