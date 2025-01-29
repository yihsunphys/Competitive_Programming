int binary_search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid; 
        }
    }
    return -1;
}

// find item greater than or equal to target 
int binary_search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid; 
        }
    }
    return left;
}

int lower_bound(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return left;
}

int upper_bound(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] <= target) {
            left = mid + 1;
        }
    }
    return left;
}

// template
bool is_valid(vector<int> &nums, int i) {
  // Is current position i valid?
}

int binary_search_left(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_valid(nums, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
