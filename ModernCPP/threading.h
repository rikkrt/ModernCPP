#pragma once

#include <iostream>
#include <thread>
#include <future>

namespace moderncpp { 
	namespace threading {

		void work(std::promise<int> * promObj)
		{
			std::cout << "Inside Thread #" << std::this_thread::get_id() << std::endl;
			std::cout << "Doing work..." << std::endl;
			promObj->set_value(35);
		}

		void futurePromiseExample()
		{
			std::cout << "Inside Thread #" << std::this_thread::get_id() << std::endl;
			std::cout << "Setting promise and future..." << std::endl;
			std::promise<int> promiseObj;
			std::future<int> futureObj = promiseObj.get_future();
			std::thread th(work, &promiseObj);
			std::cout << "Future value is now: " << futureObj.get() << std::endl;
			th.join();
		}

		double factorial(unsigned int limit)
		{
			double ret = 1;
			for (unsigned int n = 1; n <= limit; ++n)
				ret *= n;
			return ret;
		}

		void asyncExample(const int fact_1, const int fact_2)
		{
			auto future1 = std::async(factorial, fact_1);
			auto future2 = std::async(factorial, fact_2);
			double result = future1.get() + future2.get();

			std::cout << fact_1 << "! + " << fact_2 << "! = " << result << std::endl;
		}
	}
}