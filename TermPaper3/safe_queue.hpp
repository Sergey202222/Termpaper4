#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>

class safe_queue
{
public:
	void push(std::packaged_task<void()>);
	void pop();
private:
	std::queue<std::packaged_task<void()>> _queue;
	std::mutex mtx;
	std::condition_variable cv;
	bool update;
};

#endif