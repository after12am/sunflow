//
//  BaseApp.cpp
//  sunflow
//
//  Created by Okami Satoshi on 12/06/03.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#include "BaseApp.h"
#include <iostream.h>

string getBinDir(int bufSize) {
	char buf[bufSize];
	getcwd(buf, sizeof(buf));
	string ss = buf;
	return ss.c_str();
}