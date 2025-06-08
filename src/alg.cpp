// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
   int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
   int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_count = 1;
            int right_count = 1;
            while (left + 1 < right && arr[left] == arr[left + 1]) {
                ++left_count;
                ++left;
            }
            while (right - 1 > left && arr[right] == arr[right - 1]) {
                ++right_count;
                --right;
            }
            count += left_count * right_count;
            ++left;
            --right;
        } 
        else if (sum < value) {
            ++left;
        } 
        else {
            --right;
        }
    }
    
    return count;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
   int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (target < arr[i]) break; // так как массив отсортирован
        
        // Бинарный поиск target в подмассиве [i+1, len-1]
        int left = i + 1;
        int right = len - 1;
        bool found = false;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                found = true;
                // Найдем все вхождения target
                int low = mid;
                int high = mid;
                
                // Ищем левую границу
                while (low > i + 1 && arr[low - 1] == target) {
                    --low;
                }
                
                // Ищем правую границу
                while (high < len - 1 && arr[high + 1] == target) {
                    ++high;
                }
                
                count += high - low + 1;
                break;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return count;
  return 0;
}
