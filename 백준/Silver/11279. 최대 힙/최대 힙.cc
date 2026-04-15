#include <iostream>
#include <vector>

using namespace std;

void maximum_heap_insert(vector<int>& heap, int& size, int data) {
	size += 1;
	int index = size;

	while (index != 1 && data > heap[index / 2]) {
		heap[index] = heap[index / 2];
		index /= 2;
	}

	heap[index] = data;
}

int maximum_heap_delete(vector<int>& heap, int& size) {
	if (size == 0) return 0;

	int delData = heap[1];
	int temp = heap[size];
	int parent = 1, index = 2;
	size--;

	while (index <= size) {
		if ((index < size) && (heap[index + 1] > heap[index])) index += 1;
		if (temp >= heap[index]) break;

		heap[parent] = heap[index];
		parent = index;
		index *= 2;
	}

	heap[parent] = temp;

	return delData;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> heap(100001);
	int n, heapSize = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp == 0) cout << maximum_heap_delete(heap, heapSize) << '\n';
		else maximum_heap_insert(heap, heapSize, temp);
	}
}