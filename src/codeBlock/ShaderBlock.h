//
//  ShaderBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _ShaderBlock_h
#define _ShaderBlock_h

#include "BaseBlock.h"

class ShaderBlock : public BaseBlock {
	
protected:
	
	string colorSpace;
	
public:
	
	virtual Color getColor() = 0;
};

#endif
