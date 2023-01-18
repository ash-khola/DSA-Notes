// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// Solution:

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int ind_of_smaller_than_next= -1;
    int smaller_than_next;

    for(int i = n-1; i>=1; i--) {
        if(nums[i] > nums[i-1]){
            smaller_than_next = nums[i-1];
            ind_of_smaller_than_next = i-1;
            break;
        }
    }

    if(ind_of_smaller_than_next == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    int index_of_just_greater = ind_of_smaller_than_next + 1;
    int just_greater = nums[index_of_just_greater];

    for(int i = ind_of_smaller_than_next; i < n; i++) {
        if(nums[i] > smaller_than_next) {
            if(just_greater > nums[i]) {
                just_greater = nums[i];
                index_of_just_greater = i;
            }
        }
    }

    swap(nums[ind_of_smaller_than_next], nums[index_of_just_greater]);
    sort(nums.begin() + ind_of_smaller_than_next + 1, nums.end());

    return;
}