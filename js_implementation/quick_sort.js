// 第一位为key
function quick_sort(arr, l = 0, r = arr.length) {
    var first = l, last = r - 1, key = arr[first];

    if (l + 1 >= r) return;

    {
        // 一遍逼近完成，使所有小于等于key的值位于key的左边，所有大于等于key的值位于key的右边
        // 而key左侧的所有值或右侧的所有值是否是递增的，目前不用管，会在递归中解决
        while (first < last) {
            while (first < last && arr[last] >= key) {
                last-- // 右值大于等于key，last指针向左递减，朝向key中间值方向逼近
            }
            arr[first] = arr[last]; // last递减后的 arr[last] 小于key，将其放置到第1位，原arr[first]值已保存在key中无需担心
            // 继续从左侧开始
            while (first < last && arr[first] <= key) {
                first++ // 左值小于等于key，first指针向右递增，朝向key中间值方向逼近
            }
            arr[last] = arr[first]; // 左值大于key，交换到右侧
        }
        arr[first] = key; // 此时first=last，已逼近直至抵达到了中间位置，不管中间值是什么，将其默认填充为key值
    }

    quick_sort(arr, l, first);
    quick_sort(arr, first + 1, r);
}

// 最后一位为key
function quick_sort_swap(arr, l = 0, r = arr.length) {
    var first = l, last = r - 1, key = arr[last];

    if (l + 1 >= r) return;

    while (first < last) {
        while (first < last && arr[first] <= key) {
            first++
        }
        arr[last] = arr[first];
        while (first < last && arr[last] >= key) {
            last--
        }
        arr[first] = arr[last];
    }
    arr[first] = key;

    quick_sort(arr, l, first);
    quick_sort(arr, first + 1, r);
}


{
    const a = [3,1,2,4,5];
    console.log(a);
    quick_sort(a);
    console.log(a);
}
{
    const a = [3,1,2,4];
    console.log(a);
    quick_sort(a);
    console.log(a);
}
{
    const a = [9,2,4,1,5,6,8,7,3];
    console.log(a);
    quick_sort(a, 0, 9);
    console.log(a);
}
{
    const a = [2,1];
    console.log(a);
    quick_sort(a, 0, 2);
    console.log(a);
}
{
    const a = [2,1];
    console.log(a);
    quick_sort(a); // 测试函数默认值填充
    console.log(a);
}
{
    const a = [2,1];
    console.log(a);
    quick_sort_swap(a); // 测试函数默认值填充
    console.log(a);
}
{
    const a = [9,2,4,1,5,6,8,7,3];
    console.log(a);
    quick_sort_swap(a, 0, 9);
    console.log(a);
}