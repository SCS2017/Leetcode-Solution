/*
算法步骤：

1）利用给定数组创建一个堆H[0..n-1]（我们这里使用最小堆），输出堆顶元素

2）以最后一个元素代替堆顶，调整成堆，输出堆顶元素

3）把堆的尺寸缩小1

4） 重复步骤2，直到堆的尺寸为1
*/

/***************************************************************************
 *  @file       main.cpp
 *  @author     MISAYAONE
 *  @date       25  March 2017
 *  @remark     25  March 2017 
 *  @theme      Heap Sort 
 ***************************************************************************/
 
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
 
//辅助交换函数
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
 
//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度
void Heap_build(int a[],int root,int length)
{
	if (root * 2 + 1 < length)//左子结点下标不能超出数组的长度
	{
		int lchild = root * 2 + 1;//flag保存左右节点中最大值的下标
		int rchild = lchild + 1;//根节点的右子结点下标
		if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
		{
			if (a[rchild] > a[lchild])//找出左右子结点中的最大值
			{
				lchild = rchild;
			}
		}
		if (a[root] < a[lchild])
		{
			//交换父结点和比父结点大的最大子节点
			Swap(a[root], a[lchild]);
			//从此次最大子节点的那个位置开始递归建堆
			Heap_build(a, lchild, length);
		}
	}
}
 
void Heap_sort(int a[],int len)
{
	for (int i = len / 2; i >= 0; --i)  //从最后一个非叶子节点的父结点开始建堆
	{
		Heap_build(a, i, len);
	}
 
	for (int j = len-1; j > 0; --j)  //j表示数组此时的长度，因为len长度已经建过了，从len-1开始
	{
		Swap(a[0], a[j]);  //交换首尾元素,将最大值交换到数组的最后位置保存
		Heap_build(a, 0, j);  //去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
	}
 
}
int main()
{
	clock_t Start_time = clock();
	int a[10] = {12, 45, 748, 12, 56, 3, 89, 4, 48, 2};
	Heap_sort(a, 10);
 	for (size_t i = 0; i != 10; ++i)
 	{
 		cout << a[i] << " ";
 	}
	clock_t End_time = clock();
	cout << endl;
	cout << "Total running time is: " << static_cast<double>(End_time-Start_time)/CLOCKS_PER_SEC*1000 << " ms" << endl;
	return 0;
}
