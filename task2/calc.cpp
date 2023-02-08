#include <iostream>
#include <map>

float sum(float, float);
float sub(float, float);
float mul(float, float);
float div(float, float);
float (*sum_p)(float, float);
float (*sub_p)(float, float);
float (*mul_p)(float, float);
float (*div_p)(float, float);
float calc(float, float, char);

int main(){
    std::cout << calc(5,4,'+');
    return 0;
}

float calc(float a, float b, char operation){
    sum_p = &sum;
	sub_p = &sub;
	mul_p = &mul;
	div_p = &div;
	std::map <char, float (*)(float, float)> m;
	m['+'] = sum_p;
	m['-'] = sub_p;
	m['*'] = mul_p;
	m['/'] = div_p;
    float res = m[operation](a, b);
    return res;
}

float sum(float a, float b){
	return a + b;
}

float sub(float a, float b){
	return a - b;
}

float mul(float a, float b){
	return a * b;
}

float div(float a, float b){
	if(b == 0) return 0; 
	return a/b;
}