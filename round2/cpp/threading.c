#include <iostream>
#include <thread>
#include <mutex>

struct CriticalSection {
  std::mutex m;
};

void thread_function(int x, int y, CriticalSection &m)
{
  std::lock_guard<std::mutex> lockGuard(m.m);//https://www.modernescpp.com/index.php/prefer-locks-to-mutexes
  for(int i=0; i< (x); i++)
    std::cout << "thread function: "<<x <<", " <<y<<std::endl;
}

class thread_obj {
public:
    void operator()(int x,int y, int z, CriticalSection  &m)
    {
        std::lock_guard<std::mutex> lockGuard(m.m);
        for (int i = 0; i < x; i++)
            std::cout << "Thread using function"
                  " object as  callable:"<<x <<y <<z <<std::endl;
    }
};


int main()
{

  CriticalSection m;

  std::thread t((&thread_function),10,20,std::ref(m));   // t starts running
  std::thread t1((thread_obj()),10,20,30,std::ref(m));   // t starts running

  std::cout << "main thread\n";
  t.join();   // main thread waits for the thread t to finish
  t1.join();   // main thread waits for the thread t to finish
  return 0;
}
