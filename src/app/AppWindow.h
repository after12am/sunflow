//
//  AppWindow.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _AppWindow_h
#define _AppWindow_h

class AppWindow {
	
public:
	
	AppWindow();
	~AppWindow();
	
	int getWidth();
	int getHeight();
	int getFrameRate();
	void setFrameRate(float targetRate);
};

#endif
