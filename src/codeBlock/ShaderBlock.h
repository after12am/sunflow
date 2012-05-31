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

namespace sf {
	
	class ShaderBlock : public BaseBlock {
		
	public:
		
		string colorSpace;
		
		virtual Color getColor() = 0;
	};
}

#endif
