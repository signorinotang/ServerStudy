#pragma once
#include <exception>
#include <memory>  //for std::shard_ptr<>
#include <mutex>
#include <stack>

class empty_stack : std::exception {
	std::string msg_ = "empty_stack";
public:
	const char * what() const noexcept {
		return msg_.c_str();
	}
};

template<typename T>
class thread_safe_stack {
	std::stack<T> data;
	mutable std::mutex m;


};

