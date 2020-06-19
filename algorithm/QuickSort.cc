#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
  int x = arr[low];
  int i = low;
  for(int j = low+1; j<=high; ++j) {
    if (arr[j] <= x) {
      i++;
      std::swap(arr[j], arr[i]);
    }
  }
  std::swap(arr[i], arr[low]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pos = partition(arr, low, high);
    quickSort(arr, low, pos-1);
    quickSort(arr, pos+1, high);
  }
}

void test_partition() {
  int arr[] = { 3, 4, 1, 5, 2 };
  std::cout << partition(arr, 0, 4) << std::endl;
  std::cout << arr[partition(arr, 0, 4)] << std::endl;
}

int main(int argc, char const *argv[]) {
  std::cout << "start \n";
  int arr[] = { -2, 4, 1, 2, 0, 8, 3, 1, 5, 10 };
  // test_partition();
  // std::cout << sizeof(arr)/sizeof(int) << std::endl;
  quickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
  for (auto const& e : arr) {
    std::cout << e << ", ";
  }
  return 0;
}


