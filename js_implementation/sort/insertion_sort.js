function insertion_sort(nums = [], n = nums.length) {
    for (let i = 0; i < n; ++i) {
        console.log("排序前",nums);
        for (let j = i; j > 0 && nums[j] < nums[j-1]; --j) {
            // swap
            nums[j] = nums[j] + nums[j-1];
            nums[j-1] = nums[j] - nums[j-1];
            nums[j] = nums[j] - nums[j-1];
            console.log("排序中 i:",i,"j:",j,nums)
        }
        console.log("排序后",nums)
    }
}

{
    var nums = [38, 27, 43, 3, 9, 82];
    console.log(nums);
    insertion_sort(nums);
    console.log(nums);
}
