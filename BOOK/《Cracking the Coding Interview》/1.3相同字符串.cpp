﻿

// 


// __________________________ 1.3 __________________________
/*
	给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
*/
// __________________________ 解决思路 __________________________

/*首先我们要问清楚细节
	01: 是否区分大小写。
	02：是否要考虑空白字符
	03：核定字符集的大小，是不是 ASCII 编码
*/

// 解法01：排序字符串：对两个字符串用O(nlogn)的时间去进行排序，然后再用O(n)的时间比较它们是否相等即可。

// 解法02：检查两个字符串的各个字符数是否相同。	
/*
	由于组成变位词的字符是一模一样的， 因此我们可以先统计每个字符串中各个字符出现的次数， 然后看这两个字符串中各字符出现次数是否一样。
	如果是，则它们是一对变位词。 这需要开一个辅助数组来保存各字符的出现次数。我们可以开一个大小是256的整数数组， 遍历第一个字符串时，
	将相应字符出现的次数加1；遍历第二个字符串时， 将相应字符出现的次数减1。最后如果数组中256个数都为0，说明两个字符串是一对变位词。 
	(第1个字符串中出现的字符都被第2个字符串出现的字符抵消了)， 如果数组中有一个不为0，说明它们不是一对变位词。
*/	
	

// __________________________ 实现细节 __________________________

// 	解法02 的实现。
// 只用了1个辅助数组。而且只用了2次 for 循环。O(2n)	

bool compareEqual(char *a,char *b)
{
	if(strlen(a) != strlen(b))return false;

	int com[256];
	memset(com, 0, sizeof(com));	

	for( int i = 0; i<strlen(a)  ; ++i )
	{
		com[(int)a[i]]++;
	}

	for( int i = 0; i<strlen(a)  ; ++i )
	{
		if( --com[(int)b[i]] < 0 )return false;
	}

	return true;
}








// __________________________ 用了 2个数组的笨方法  __________________________
int a[256],b[256];

// 统计每个字符串中字符出现的次数
void statistics(char *str,int *orc)
{
	int len = strlen(str);
	for(int i = 0;i<len;++i)
	{
		int j = (int )str[i];
		++orc[j];
	}
}

// 比较两个数组 是否相同
bool compare()
{
	bool equal = true;
	for(int i = 0;i<255;i++)
	{
		if( a[i] != b[i])
		{
			equal = false;
			break;
		}
	}

	return equal;
}


// 
// 
