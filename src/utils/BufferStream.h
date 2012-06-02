//
//  BufferStream.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _BufferStream_h
#define _BufferStream_h

#include <sstream>
#include <iostream.h>
#include "Constants.h"

class BufferStream {
	
private:
	
	std::ostringstream osstream;
	std::string filePath;
	
	int depth;
	
	// delete sc file
	void clear();
	
	float omit(float v);
	
public:
	
	BufferStream() {
		depth = 0;
	}
	
	~BufferStream() {
		depth = 0;
		osstream.clear();
		//clear();
	}
	
	/// output as sc file and clear osstream buffer
	void save(string name);
	
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

#endif
