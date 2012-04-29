//
//  Log.h
//  sunflow
//
//  Created by Okami Satoshi on 12/02/14.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef sunflow_Log_h
#define sunflow_Log_h

#include <iostream.h>

namespace sf {
	
	class Log {
		
	public:
		
		static void info(std::string message)
		{
			cout << "[SUNFLOW INFO] " << message << endl;
		}
		
		static void warning(std::string message)
		{
			cout << "[SUNFLOW WARNING] " << message << endl;
		}
		
		static void error(std::string message)
		{
			cout << "[SUNFLOW ERROR] " << message << endl;
		}
	};
}

#endif