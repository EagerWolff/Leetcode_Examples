int singleNumber(int* nums, int numsSize) {
    int gottenSingleNumber = 0;

    for (int i = 0;i < numsSize;++i){
        gottenSingleNumber ^= *(nums + i);
    }

    return gottenSingleNumber;
}
