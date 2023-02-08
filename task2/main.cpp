#include <iostream>
#include <fstream>

bool check_least_and_most_sign_bits(unsigned int);
void print_bits_count(unsigned int);
int binary_search(const int*, const int, int);
int recursive_binary_search(const int*, int, int, int);
void reverse_char_array(char* char_arr);
int count_of_arr_index_el_div(const int*, int);
bool isNumber(std::string);
std::string string_to_camel_case(std::string);
int sum_of_nums_in_file(std::string);
void camel_case_in_file(std::string, std::string);

int main(){
	camel_case_in_file("test", "test2");
    return 0;
}


bool check_least_and_most_sign_bits(unsigned int num){
    if((bool)(num & 1u<<31) == (num & 1)){
		return true;
	}
	return false;
}

void print_bits_count(unsigned int num){
    int one_count = 0;
	int zero_count = 0;
    while(num){
        if(num % 2 == 0) ++zero_count;
        if(num % 2 == 1) ++one_count;
		num /= 2; 
    }
	std::cout << "1 bit count: " << one_count << std::endl;
	std::cout << "0 bit count: " << zero_count << std::endl;
}

int binary_search(const int* arr, const int SIZE, int el){
	int st = 0;
	int end = SIZE - 1;
	int pivot;
	while (end >= st){
		pivot = (end + st) / 2;
		if (arr[pivot] < el){
        	st = pivot + 1;
        }
		if (arr[pivot] > el){
			end = pivot - 1;
		}
		if(arr[pivot] == el){
			return pivot;
		}
    }
	return -1;
}

int recursive_binary_search(const int* arr, int st, int end, int el){
	int pivot = (end + st) / 2;
	if (end >= st){
		if (arr[pivot] > el){
			return recursive_binary_search(arr, st, pivot - 1, el);
		}
		if (arr[pivot] < el){
			return recursive_binary_search(arr, pivot + 1, end, el);
		}
		return pivot;	
	}
	return -1;
}

void reverse_char_array(char* char_arr){
	char* tmp = char_arr;
	while (*(tmp+1))
	{
		++tmp;	
	}
	while (tmp > char_arr)
	{
		std::swap(*tmp, *char_arr);
		--tmp;
		++char_arr;
	}
	
}


int count_of_arr_index_el_div(const int* arr, int size){
	int count = 0;
	for(int i = 1; i < size; ++i){
		if(arr[i] % i == 0) count++;
	}
	return count;
}

std::string string_to_camel_case(std::string letter){
	for(int i = 0; i < letter.size(); ++i){
		if(i == 0 || (char)letter[i-1] == 32){
			char tmp = (char)letter[i];
			if(tmp >= 97 && tmp <= 122){
				letter[i] = tmp - 32;
			}
		}
	}
	return letter;
}

bool isNumber(std::string str){
	for(int i = 0; i < str.length(); ++i){
		if (!isdigit(str[i])){
			return false;
		}
	}
	return true;
} 

int sum_of_nums_in_file(std::string file_name){
	std::ifstream file;
	file.open(file_name);
	int sum = 0;
	std::string s;
	for(file >> s; !file.eof(); file >> s){
			if(isNumber(s)){
				sum += stoi(s);
				std::cout << s << std::endl;
		}
	} 
	file.close();
	return sum;
}

void camel_case_in_file(std::string in_file, std::string o_file){
	std::ifstream ini_file{in_file};
	std::ofstream out_file{o_file};
	if (ini_file && out_file){
		std::string s;
		for(ini_file >> s; !ini_file.eof(); ini_file >> s){
			if((char)s[0] >= 97 && (char)s[0] <= 122){
				s[0] = (char)s[0] - 32;
			}
			out_file << s << " ";
		} 
	}
}