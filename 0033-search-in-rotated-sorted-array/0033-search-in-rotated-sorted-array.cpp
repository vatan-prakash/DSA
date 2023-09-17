// class Solution {
// public:
    
// int getpivot(vector<int>& arr, int n) {
//     int s = 0;
//     int e = n - 1;
    
//     while (s < e) {
//         int mid = s + (e - s) / 2;
//         if (arr[mid] >= arr[0]) {
//             s = mid + 1;
//         } else {
//             e = mid;
//         }
//     }
//     return s;
// }

                                        
//     int binarysearch(vector<int>& arr, int s, int e, int key){
//     int start=s;
//     int end=e;
//     int mid=(start+end)/2;
//     while (s<=e){
//             if(arr[mid]==key) return mid;
//             if (key>arr[mid]) start=mid+1;
//             else end=mid-1;
//             mid=(start+end)/2;
//     }   
//     return -1;
//     }
    
//   int search(vector<int>& arr, int target) {
//     int n = arr.size();
//     int pivot = getpivot(arr, n);
    
//     if (target >= arr[pivot] && target <= arr[n - 1]) {
//         return binarysearch(arr, pivot, n - 1, target);
//     } else {
//         return binarysearch(arr, 0, pivot - 1, target); // You should return the result here.
//     }
// }

// };
class Solution {
public:
    int binarySearch(vector<int>& arr, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int pivot = left;

        if (target >= arr[pivot] && target <= arr[n - 1]) {
            return binarySearch(arr, pivot, n - 1, target);
        } else {
            return binarySearch(arr, 0, pivot - 1, target);
        }
    }
};
