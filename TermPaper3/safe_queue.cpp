#include "safe_queue.hpp"

void safe_queue::push(std::packaged_task<void()> package)
{
	std::unique_lock<std::mutex> lgmx(mtx);
	update = true;
	_queue.push(std::move(package));
	cv.notify_one();
	lgmx.unlock();
}

void safe_queue::pop()
{
	std::unique_lock<std::mutex> lck(mtx);
	while (!update) cv.wait(lck);
	_queue.front()();
	_queue.pop();
	update = false;
	lck.unlock();
}