int hammingWeight(uint32_t n) {

    int num=0;

    while (n){

        if (n & 0x1)  // 取出最低位；

            num++;

        n >>= 1;     // 逐位扫描

    }

    return num;

}
