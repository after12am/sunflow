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
		
		
		ShaderBlock() {
			type = "shader";
			name = SHADER_NONE;
		}
	};
}

#endif
