#include<bits/stdc++.h>
using namespace std;


int longestSub(int array[]) {
    int counter =0;
    int max_counter =0;
    int s = array.size();


    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            if (array[j] > array[i]) {
                counter++;
                if (counter > max_counter) {
                    max_counter = counter;
                }else {
                    continue;
                }
            }
            counter =0;
        }
    }

    return max_counter;
}