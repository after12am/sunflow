//
//  BaseBlock.h
//  
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _BaseBlock_h
#define _BaseBlock_h

#include "BufferStream.h"
#include <iostream.h>

using namespace std;

namespace sf {
	
	class BaseBlock {
		
	public:
		
		string type;
		string name;
		
		virtual ~BaseBlock() {
			
		}
		
		virtual void flush(BufferStream& stream) = 0;
	};
}

#endif
