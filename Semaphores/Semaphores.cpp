// Semaphores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
using namespace std;

int semaphore = 1;
int shared_resource = 0;

void Wait(int *S);
void Signal(int *S);
void process_1();
void process_2();

int main()
{
    int x;

    thread thread_1 = thread(process_1);
    thread thread_2 = thread(process_2);
    
    thread_2.join();
    thread_1.join();

    cout << shared_resource << endl;
    cin >> x;
}

void Wait(int* S)
{
    while (*S <= 0); //No operation
    *S = *S - 1;
}

void Signal(int* S)
{
    *S = *S + 1;
}

void process_1()
{
    Wait(&semaphore);
    cout << "Process(1) starts its execution !! Semaphore = "<< semaphore << endl;
    shared_resource += 2;
    //PIECE OF CODE

    Signal(&semaphore);  //release the lock
    cout << "Process(1) release the lock !! Semaphore = "<< semaphore << endl;
}

void process_2()
{
    Wait(&semaphore);
    cout << "Process(2) starts its execution !! Semaphore = " << semaphore << endl;
    shared_resource = 10;
    //PIECE OF CODE

    Signal(&semaphore);  //release the lock
    cout << "Process(2) release the lock !! Semaphore = "<< semaphore << endl;
}