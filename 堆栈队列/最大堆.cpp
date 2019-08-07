#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;


template<typename Item>
class MaxHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        //k对应位置的结点有孩子节点
        while( 2*k <= count ){
            //判断左右孩子是否存在
            int j = 2*k; // 在此轮循环中,data[k]和data[j]交换位置
            //如果右孩子节点的元素较大，则该节点与右孩子节点的元素交换
            if( j+1 <= count && data[j+1] > data[j] )
                j += 1;
            // data[j] 是 data[2*k]和data[2*k+1]中的最大值
            //如果data[k] >= data[j]，那么不需要交换
            if( data[k] >= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];

        swap( data[1] , data[count] );
        count --;
        shiftDown(1);

        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[1];
    }

};


int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));
    for( int i = 0 ; i < 15 ; i ++ ){
        maxheap.insert( rand()%100 );
    }

    while( !maxheap.isEmpty() )
        cout<<maxheap.extractMax()<<" ";
    cout<<endl;

    return 0;
}