//
//  PinholeCameraBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/05/31.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _PinholeCameraBlock_h
#define _PinholeCameraBlock_h

#include "CameraBlock.h"
#include "BufferStream.h"

class PinholeCameraBlock : public CameraBlock {
	
public:
	
	float fov;
	float aspect;
	
	PinholeCameraBlock(const vec3f _eye, const vec3f _target, const vec3f _up, const float _fov, const float _aspect) {
		type = "pinhole";
		eye = _eye;
		target = _target;
		up = _up;
		fov = _fov;
		aspect = _aspect;
	}
	
	void flush(BufferStream& stream) {
		stream.push("camera");
		stream.write("type", type);
		stream.write("eye", eye.x, eye.y, eye.z);
		stream.write("target", target.x, target.y, target.z);
		stream.write("up", up.x, up.y, up.z);
		stream.write("fov", fov);
		stream.write("aspect", aspect);
		stream.pop();
	}
};

#endif
