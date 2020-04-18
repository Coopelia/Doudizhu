#pragma once
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>

class DFSCard
{
public:
	int n, ans, a[14],first[14], first_1[14], first_2[14], first_flag;
	DFSCard();
	int work(int* x);
	void add_to_dfs(int* x,int n);
	void dfs(int* x, int step);
	void getFirst();
	void clear();
};