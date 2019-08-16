#pragma once
#include<iostream>
#include<vector>

template<typename T> void vectorOut(const std::vector<T>& v) {
	for (auto iter = v.begin(); iter != v.end() ;iter++) {
		if (iter + 1 != v.end()) {
			std::cout << *iter << ", ";
		}
		else {
			std::cout << *iter << std::endl;
		}
	}
}

template<typename T> void vectorOut(const std::vector<T>& v, int n) {
	int cnt = 0;
	for (auto iter = v.begin(); iter != v.end() && cnt != n;iter++, cnt++) {
		if (iter + 1 != v.end() && cnt+1 != n) {
			std::cout << *iter << ", ";
		}
		else {
			std::cout << *iter << std::endl;
		}
	}
}
