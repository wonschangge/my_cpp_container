function bubble_sort(nums=[], n=nums.length) {
    var swapped;
    for (var i = 1; i < n; ++i) {
        console.log("排序前",nums);
        swapped = false;
        for (var j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j-1]) {
                // swap
                nums[j] = nums[j] + nums[j-1];
                nums[j-1] = nums[j] - nums[j-1];
                nums[j] = nums[j] - nums[j-1];
                swapped = true;
            }
            console.log("排序中 i:",i,"j:",j,nums)
        }
        console.log("排序后",nums)
        if (!swapped) break;
    }
}

{
    var nums = [38, 27, 43, 3, 9, 82];
    console.log(nums);
    bubble_sort(nums);
    console.log(nums);
}
