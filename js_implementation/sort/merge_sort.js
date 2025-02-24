function merge_sort(nums, l = 0, r = nums.length, tmp = []) {
    if (l + 1 >= r) return;

    // divide
    var m = l + Math.floor((r - l) / 2);
    merge_sort(nums, l, m, tmp);
    merge_sort(nums, m, r, tmp);

    // conquer
    // l代表当前最左边的数的位置，位置不发生变化
    // r代表当前最右边的数的位置，位置不发生变化
    // m代表当前最中间的数的位置（l+(r-1)/2)所得，位置不发生变化
    // p代表指向最左边的数的指针
    // q代表指向最中间的数的指针
    // i代表指向最左边的数的指针
    var p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
            tmp[i++] = nums[p++];
        } else {
            tmp[i++] = nums[q++];
        }
    }
    // 重整nums
    for (i = l; i < r; ++i)
        nums[i] = tmp[i];
}

// {
//     var nums = [38, 27, 43, 3, 9, 82];
//     console.log(nums);
//     merge_sort(nums);
//     console.log(nums);
// }
// {
//     var nums = [38, 27, 43, 3, 9, 82, 10];
//     console.log(nums);
//     merge_sort(nums);
//     console.log(nums);
// }

// while (p < m || q < r) {
//     if (q >= r || (p < m && nums[p] <= nums[q])) {
//         tmp[i++] = nums[p++];
//     } else {
//         tmp[i++] = nums[q++];
//     }
// }

// 11 22 33
// {
//     var nums = [11, 22, 33, 3, 9, 82];
//     console.log(nums);
//     merge_sort(nums);
//     console.log(nums);
// }
// l=1,r=3,m=2, p=1++,q=2,i=1++, tmp=[,22], num=[11,22,33,...]
// l=1,r=3,m=2, p=2++,q=2,i=2++, tmp=[,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=0++,q=1,i=0++, tmp=[11,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=1,q=1++,i=1++, tmp=[11,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=0,q=2++,i=2++, tmp=[11,22,33], num=[11,22,33,...]

// 11 33 22
// {
//     var nums = [11, 33, 22, 3, 9, 82];
//     console.log(nums);
//     merge_sort(nums);
//     console.log(nums);
// }
// l=1,r=3,m=2, p=1,q=2++,i=1++, tmp=[,22], num=[11,33,22,...]
// l=1,r=3,m=2, p=1++,q=3,i=2++, tmp=[,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=0,q=1,i=0++, tmp=[11,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=0,q=1,i=1++, tmp=[11,22,33], num=[11,22,33,...]
// l=0,r=3,m=1, p=0,q=1,i=2++, tmp=[11,22,33], num=[11,22,33,...]

// 22 11 33
// {
//     var nums = [22, 11, 33, 3, 9, 82];
//     console.log(nums);
//     merge_sort(nums);
//     console.log(nums);
// }
// l=1,r=3,m=2, p=1++,q=2,i=1++, tmp=[,11], num=[22,11,33,...]
// l=1,r=3,m=2, p=2++,q=3,i=2++, tmp=[,11,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=0,q=1++,i=0++, tmp=[11,11,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=0++,q=2,i=1++, tmp=[11,22,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=1,q=2++,i=2++, tmp=[11,22,33], num=[11,22,33,...]

// 22 33 11
{
    var nums = [22, 33, 11, 3, 9, 82];
    console.log(nums);
    merge_sort(nums);
    console.log(nums);
}
// l=1,r=3,m=2, p=1,q=2++,i=1++, tmp=[,11], num=[22,33,11,...]
// l=1,r=3,m=2, p=1++,q=3,i=2++, tmp=[,11,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=0,q=1++,i=0++, tmp=[11,11,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=0++,q=2,i=1++, tmp=[11,22,33], num=[22,11,33,...]
// l=0,r=3,m=1, p=1,q=2++,i=2++, tmp=[11,22,33], num=[11,22,33,...]

// 33 11 22

// 33 22 11

