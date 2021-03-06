template<typename T>
class QueueUsingArrays{
  int size;
  T *data;
  int nextIndex;
  int firstIndex;
  int capacity;
public:
  QueueUsingArrays()
  {
    capacity  = 5;
    data = new T[5];
    size = 0;
    nextIndex = 0;
    firstIndex = -1;
  }


  bool isEmpty(){
    return size==0;
  }
  int getSize(){
    return size;
  }
  T front(){
    if(isEmpty())
    {
      cout <<"Queue Is Empty !!"<<endl;
      return 0;
    }
    return data[firstIndex];
  }
  void enqueue(T element){
    if(size==capacity)
    {
      T *newData = new T [2*capacity];
      int j=0;
      for(int i=firstIndex;i<capacity;i++)
      {
        newData[j] = data[i];
        j++;
      }
      for(int i=0;i<firstIndex;i++)
      {
        newData[j] = data[i];
        j++;
      }

      delete [] data;
      data = newData;
      firstIndex = 0;
      nextIndex = capacity;
      capacity*=2;
    }
    data[nextIndex] = element;
    nextIndex = (nextIndex+1)%capacity;
    if(firstIndex==-1)
    {
      firstIndex++;
    }
    size++;
  }
  T dequeue()
  {
    if(isEmpty())
    {
      cout <<"Queue Is Empty !!"<<endl;
      return 0;
    }
    T ans = data[firstIndex];
    firstIndex = (firstIndex+1)%capacity;
    size--;
    return ans;
  }

};
