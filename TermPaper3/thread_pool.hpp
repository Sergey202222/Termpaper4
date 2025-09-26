#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP
#include "safe_queue.hpp"
#include <vector>
#include <thread>

class thread_pool
{
public:
	thread_pool();
    ~thread_pool();
	void submit(std::packaged_task<void()>);
private:
	const int _size{ 8 };
	std::vector<std::thread> ths;
	safe_queue s_queue;
	void work();
};

#endif