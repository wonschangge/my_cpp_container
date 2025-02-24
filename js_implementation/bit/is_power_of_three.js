// 法1:
function isPowerOfThree(n) {
    while (n !== 0 && n % 3 == 0) {
        n = Math.floor(n / 3);
    }
    return n === 1;
}

// 法2:
// 在给定的32位有符号整数的范围内，最大的3的幂为 3^19 = 1162261467
// 只需判断n是否是3^19的约数即可
function isPowerOfThree2(n) {
    return n > 0 && 1162261467 % n === 0;
}