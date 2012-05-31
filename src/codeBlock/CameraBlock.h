//
//  CameraBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _CameraBlock_h
#define _CameraBlock_h

#include "BaseBlock.h"

namespace sf {
	
	class CameraBlock : public BaseBlock {
		
	public:
		
		vec3f eye;
		vec3f target;
		vec3f up;
	};
}

#endif
