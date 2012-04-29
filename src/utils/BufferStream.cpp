
#include "BufferStream.h"
#include <iostream.h>

using namespace sf;


float BufferStream::omit(float v)
{
	return (v * 1000) / 1000.0;
}

void BufferStream::clear()
{
	if (remove(filePath.c_str()) != 0)
	{
		//cout << "[WARNING] sc file not found " << filePath.c_str() << endl;
		return;
	}
	
	cout << "[INFO] delete sc file" << endl;
}

void BufferStream::save()
{
	FILE *fp = fopen(filePath.c_str(), "w");
	
	if (fp == NULL)
	{
		cout << "[ERROR] fopen error " << filePath.c_str() << endl;
		exit(0);
	}
	
	fputs(osstream.str().c_str(), fp);
	fclose(fp);
	
	cout << "[INFO] save sc file" << endl;
	
	// clear buffer
	osstream.str("");
}

void BufferStream::setPath(std::string path)
{
	filePath = path;
	
	cout << "[INFO] change sc file path " << path << endl;
}

std::string BufferStream::getPath()
{
	return filePath;
}

void BufferStream::dump()
{
	cout << "[INFO] show sc file buffer below\n" << endl;
	cout << osstream.str() <<endl;
}

void BufferStream::push(const std::string name)
{
	depth++;
	writeIndent(depth);
	osstream << name << " {" << endl;
}

void BufferStream::writeIndent(int depth)
{
	for (int i = 1; i < depth; i++) osstream << "\t";
}

void BufferStream::write(const std::string name)
{
	writeIndent(depth);
	osstream << "\t" << name << endl;
}

void BufferStream::write(const std::string name, const std::string v1)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << v1 << endl;
}

void BufferStream::write(const std::string name, const int v1)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << v1 << endl;
}

void BufferStream::write(const std::string name, const float v1)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << omit(v1) << endl;
}

void BufferStream::write(const std::string name, const int v1, const int v2)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << v1 << " " << v2 << endl;
}

void BufferStream::write(const std::string name, const float v1, const float v2)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << omit(v1) << " " << omit(v2) << endl;
}

void BufferStream::write(const std::string name, const int v1, const int v2, const int v3)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << v1 << " " << v2 << " " << v3 << endl;
}

void BufferStream::write(const std::string name, const float v1, const float v2, const float v3)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << omit(v1) << " " << omit(v2) << " " << omit(v3) << endl;
}

void BufferStream::write(const std::string name, const int v1, const int v2, const int v3, const int v4)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << v1 << " " << v2 << " " << v3 << " " << v4 << endl;
}

void BufferStream::write(const std::string name, const float v1, const float v2, const float v3, const float v4)
{
	writeIndent(depth);
	osstream << "\t" << name << " " << omit(v1) << " " << omit(v2) << " " << omit(v3) << " " << omit(v4) << endl;
}

void BufferStream::pop()
{
	std::string end = (depth > 1) ? "" : "\n";
	writeIndent(depth);
	osstream << "}" << end << endl;
	depth--;
}
