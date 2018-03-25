#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void thread_func0(int id)
{
    printf("(printf)hello I am thread #%d\n", id);
}

void thread_func1(int id)
{
    cout << "(cout)hello I am thread #"<<id <<endl;
}

void thread_func2(int id)
{
    fprintf(stderr, "(fprintf stderr)hello I am thread #%d\n", id);
}

void thread_func3(int id)
{
    cerr << "(cerr)hello I am thread #"<<id <<endl;
}

void test(function<void(int)> func, int N)
{
    vector<thread> vec;
    for( int i = 0; i < N; ++i) {
	vec.push_back(thread(func, i));
    }
    for( int i = 0; i < N; ++i) {
	vec[i].join();
    }
}


int main()
{
    int N;
    cout << "num of threads to test(e.g. 100): ";
    cin >> N;
    
    cout << "------ testing printf ------" << endl;
    test(thread_func0, N);

    cout << "------ testing cout------" << endl;
    test(thread_func1, N);
    
    cout << "------ testing fprintf stderr------" << endl;
    test(thread_func2, N);

    cout << "------ testing cerr------" << endl;
    test(thread_func3, N);

}
