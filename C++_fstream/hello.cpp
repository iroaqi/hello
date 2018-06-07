#include <iostream>
#include <fstream>
#include <sstream>

void write1()
{
	std::ofstream ofs("hello.txt");
	ofs << "hello";
}

void write2()
{
	std::ofstream ofs("world.txt");
	ofs << "w" << std::endl <<
		"o" << std::endl <<
		"r" << std::endl <<
		"l" << std::endl <<
		"d" << std::endl;
}

std::string read1()
{
	std::ifstream ifs("hello.txt");
	std::stringstream ss;
	ss << ifs.rdbuf();
	return ss.str();
}

std::string read2()
{
	std::ifstream ifs("world.txt");
	std::string str;
	for (std::string line; std::getline(ifs, line); ) {
		str += line.substr(0, line.size());
	}
	return str;
}

int main(int argc, char * argv[])
{
	write1();
	write2();
	std::cout << read1() << " " << read2() << std::endl;
	return 0;
}
