// 法1:
// 目标n如果是2的幂，则n的二进制表示为 0b1000...000
// (n-1)的二进制表示为 0b0111...111
// 两者相与的结果为0
function isPowerOfTwo2(n) {
    return n > 0 && (n & (n - 1)) === 0;
}


// 法2:
function isPowerOfTwo(n) {
    return n > 0 && (n & -n) === n;
}

// 法3:
// 在给定的32位有符号整数的范围内，最大的2的幂为 2^30 = 1073741824
// 只需判断n是否是2^30的约数即可
function isPowerOfTwo3(n) {
    const BIG = 1<<30;
    return n > 0 && BIG % n === 0;
}