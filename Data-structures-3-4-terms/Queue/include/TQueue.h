 //  Copyright by Robert Oganyan
#include <stdexcept>
#ifndef QUEUE_TQUEUE_H
#define QUEUE_TQUEUE_H

 const int MaxQueueSize = 100;

 template <class T>
 class TQueue {
 private:
     T *pmem;
     int memsize; //размер выделенной памяти
     int datacount; //к-во заполненных в очереди элементов
     int last; //индекс последнего элемента очереди
     int first; //индекс первого элемента

 public:
     TQueue() = delete;
      explicit  TQueue(int _size = 20);
     ~TQueue();
     TQueue(const TQueue<T>& t);
     void Push(const T val);
     bool IsFull();
     bool IsEmpty();
     T GetFirst();
     T Get();
 };

 template <class T>
 TQueue<T>::TQueue(int _size) {
         memsize = _size;
         datacount = 0;
         last = -1;
         first = 0;
         if ((memsize < 1) || (memsize > MaxQueueSize)) {
             throw std::runtime_error("Wrong size");
         }
         pmem = new T[memsize];
 }

 template <class T>
 TQueue<T>::~TQueue() {
     if (pmem != nullptr) {
       delete[] pmem;
     }
 }

 template <class T>
 TQueue<T>::TQueue(const TQueue<T>& t) {
     memsize = t.memsize;
     datacount = t.datacount;
     last = t.last;
     first = t.first;
     pmem = nullptr;
     if (t.pmem != nullptr) {
         pmem = new T[memsize];
     }
 }

 template <class T>

 bool TQueue<T>::IsEmpty() {
    return !datacount;
 }

 template <class T>
 bool TQueue<T>::IsFull()
 {
     return datacount == memsize;
 }

 template <class T>
 void TQueue<T>::Push(const T val) {

     if (IsFull()) {
        throw std::runtime_error("Queue is full");;
     }
     if (last == memsize - 1) {
         last = 0;
     }
     else {
         last++;
     }
     pmem[last] = val;
     datacount++;
 }

 template <class T>
 T TQueue<T>::Get()
 {
     if (IsEmpty()) {
         throw std::runtime_error("Queue is empty");
     }
     --datacount;
     T tmp = pmem[first];
     first = (first + 1) % memsize;
     return tmp;
 }

 template<class T>
 T TQueue<T>::GetFirst() {
     if (IsEmpty()) {
       std::runtime_error("Queue is empty");
     }
     return pmem[first];
 }

#endif //QUEUE_TQUEUE_H
