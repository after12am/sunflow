//
//  BufferStream.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _BufferStream_h
#define _BufferStream_h

#include <sstream>
#include <iostream.h>

namespace sf {
	
	class BufferStream {
		
	private:
		
		std::ostringstream osstream;
		
		int depth;
		
		// delete sc file
		void clear();
		
		float omit(float v);
		
	public:
		
		std::string filePath;
		
		BufferStream()
		{
			depth = 0;
			
			char buf[1024];
			getcwd(buf, sizeof(buf));
			std::string ss = buf;
			setPath(ss + "/output.sc");
		}
		
		~BufferStream()
		{
			depth = 0;
			
			osstream.clear();
			
			//clear();
		}
		
		/// output as sc file and clear osstream buffer
		void save();
		
		// set sc file path
		void setPath(std::string path);
		
		// get sc file path
		std::string getPath();
		
		// output osstream buffer to console
		void dump();
		
		// output buffer to stream
		void push(const std::string name);
		void writeIndent(int depth);
		void write(const std::string name);
		void write(const std::string name, const std::string v1);
		void write(const std::string name, const int v1);
		void write(const std::string name, const float v1);
		void write(const std::string name, const int v1, const int v2);
		void write(const std::string name, const float v1, const float v2);
		void write(const std::string name, const int v1, const int v2, const int v3);
		void write(const std::string name, const float v1, const float v2, const float v3);
		void write(const std::string name, const int v1, const int v2, const int v3, const int v4);
		void write(const std::string name, const float v1, const float v2, const float v3, const float v4);
		void pop();
	};
}

#endif
