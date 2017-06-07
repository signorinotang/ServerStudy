#include <thread>

class thread_scoped
{
	std::thread t;
public:
	explicit thread_scoped(std::thread t_)
		:t(std::move(t_)) {
			if(!t.joinable()){
				throw std::logic_error("no thread");
			}	
		}
	~thread_scoped() {
		t.join();
	}
	
	thread_scoped(thread_scoped const&) = delete;
	thread_scoped & operator = (thread_scoped const&) = delete;

}

//example
//thread_scoped t(std::thread(fun));
