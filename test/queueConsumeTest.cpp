//C++ file
/***********************************************
#
#      Filename: queueConsumeTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-09-28 17:19:44
#**********************************************/
#include <iostream>
#include <queue>
#include "mutex"
#include <condition_variable>
#include <future>
#include <unistd.h>

using namespace std;


template <typename F, typename... Args>
auto real_async(F&& f, Args&&... args)-> std::future<typename std::result_of<F(Args...)>::type>
{
    using _Ret = typename std::result_of<F(Args...)>::type;
    auto _func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    std::packaged_task<_Ret()> tsk(std::move(_func));
    auto _fut = tsk.get_future();
    std::thread thd(std::move(tsk));
    thd.detach();
    return _fut;
}

std::mutex mm;
std::condition_variable cv;

#define NUM 1024
int main()
{
    char str[NUM]; 
    for (int i = 0; i < NUM; ++i)
    {
        str[i] = 'x';
    }
    cout << str << endl;
    std::queue<std::string> *m_qq = new queue<std::string>();

    sleep(2);
    real_async([m_qq, str](){
        while (1) 
        {
            std::unique_lock<std::mutex> lock(mm); 
            if (m_qq->size() >= 2500)
            {
                cout << "m_qq is full" << endl;
                m_qq->pop();
            }
            m_qq->push(string((char*)str, NUM));
            cout << "size: " << m_qq->size() << endl;
            if (m_qq->size() >= 2)
                cv.notify_all();

            usleep(40000);  // 40ms
        }
    }); 

    // getchar();
    // sleep(5);
    while (1)
    {
        std::unique_lock<std::mutex> lock(mm); 
        if (m_qq->empty())
        {
            cout << "queue is empty..." << endl;
            cv.wait(lock);
        }
        
        std::string str = m_qq->front();
        cout << "consume queue: " << str << endl;
        m_qq->pop();
        // usleep(20000);
    }
    


	return 0;
}

