#include <iostream>
#include <unordered_map>

int rep_count(const int*, const int);

int main(){
    int list[] = {1, 4, 5, 7, 5, 7};
    std::cout << rep_count(list, 6);
    return 0;
}

int rep_count(const int* arr, const int size){
    std::unordered_map<int, int> repeat_count;
    for(int i = 0; i < size; ++i){
        if(repeat_count.count(arr[i]) == 0){
            repeat_count.insert({arr[i], 1});
        }
        else{
            repeat_count[arr[i]]++;
        }
    }
    int count = 0;
    for(auto i = repeat_count.begin(); i != repeat_count.end(); i++){
        if(i -> second > 1) count += i -> second;
    }
    return count;
}