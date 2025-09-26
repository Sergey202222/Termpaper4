#include "thread_pool.hpp"
#include <chrono>

using namespace std::chrono;


thread_pool::thread_pool()
{
	ths = std::vector<std::thread>(_size);
	for (int index{}; index < ths.size(); ++index)
	{
		ths[index] = std::thread(&thread_pool::work, this);
	}
}

thread_pool::~thread_pool()
{
	for (int index{}; index < ths.size(); ++index)
	{
		ths[index].join();
	}
}

void thread_pool::submit(std::packaged_task<void()> package)
{
	std::this_thread::sleep_for(1s);
	s_queue.push(std::move(package));
}

void thread_pool::work()
{
	s_queue.pop();
}