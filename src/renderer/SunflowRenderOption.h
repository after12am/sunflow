//
//  SunflowRenderOption.h
//  sunflow
//
//  Created by Okami Satoshi on 12/06/01.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _SunflowRenderOption_h
#define _SunflowRenderOption_h

#include <iostream.h>

class SunflowRenderOption {
	
public:
	
	bool nogui;
	bool ipr;
	std::string output;
	std::string formatPath;
	
	SunflowRenderOption() {
		nogui = false;
		ipr = false;
		output = "";
		formatPath = "";
	}
};

#endif
