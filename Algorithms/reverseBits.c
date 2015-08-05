uint32_t reverseBits(uint32_t n) {
    uint32_t result=0;
    for(int i=0; i<32; i++){   // 注意要把32bit全部处理，不能用 while(n)
        result = (result <<1) + (n & 0x1);  // 取出最低位；
        n >>= 1;     // 逐位扫描
    }
    return result;
}
