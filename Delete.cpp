#include<bits/stdc++.h>
using namespace std;
class heap
{
	public:
		int arr[100];
		int size;
		heap()
		{
			size = 0;
			arr[0] = -1;
		}
		void insert(int n)
		{
			size++;
			int index = size / 2;
			arr[index] = n;
			while(index>1)
			{
				int parent = index / 2;
				if(arr[parent]<arr[index])
				{
					swap(arr[parent], arr[index]);
					index = parent;
				}
				else
				{
					return;
				}
			}
		}
		void dindex()
		{
			if(size==0)
			{
				cout << "Heap Is empty";
				return;
			}
			arr[1] = arr[size];
			size--;
			int i = 1;
			while(size>i)
			{
				int leftindex=2*i;
				int rightindex = 2 * i + 1;
				if(leftindex<size && arr[i]<arr[leftindex])
				{
					swap(arr[i], arr[leftindex]);
					i = leftindex;
				}
				else if(rightindex<size && arr[i]<arr[rightindex])
				{
					swap(arr[i], arr[rightindex]);
					i = rightindex;
				}
				else
				{
					return;
				}

			}
		}
		void print()
		{
			for (int i = 1; i <= size;i++)
			{
				cout << arr[i] << " ";
			}
		}
};
int main()
{
	heap h;
	h.insert(54);
	h.insert(53);
	h.insert(55);
	h.insert(52);
	h.insert(50);
	h.dindex();
	h.print();
	return 0;
}