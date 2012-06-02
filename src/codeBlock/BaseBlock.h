//
//  BaseBlock.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _BaseBlock_h
#define _BaseBlock_h

#include "BufferStream.h"

class BaseBlock {
	
protected:
	
	string type;
	string name;
	
public:
	
	string getName() { return name; }
	virtual void flush(BufferStream& stream) = 0;
};

#endif
