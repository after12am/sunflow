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

namespace sf {
	
	class BaseBlock {
		
	protected:
		
		string type;
		
	public:
		
		string name;
		
		virtual void flush(BufferStream& stream) = 0;
	};
}

#endif
