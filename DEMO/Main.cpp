#include <Window.h>
#include <Memory_Pool.h>

int main()
{
	std::string name("Half life 3");
	Chunked_Memory_Pool<4> testpool (100000);
	Xohat::Window MainWindow(name, 1024, 768, false);
	while(true){}
	return 0;
}