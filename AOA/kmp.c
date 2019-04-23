#include <stdio.h>
#include <string.h>
char txt[50],pat[50];
int M,N,lps[50];

void computeLPSArray();
void KMPSearch()
{
	M = strlen(pat);
	N = strlen(txt);
	computeLPSArray();

	int i = 0;
	int j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M)
        {
			printf("Found pattern at index %d \n", i - j);
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i])
        {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray()
{
	int j = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[j])
        {
			lps[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)     //when j is ahead of zero
            {
				j = lps[j - 1];

            }
			else    //when j has not gone ahead of 0, lps[i]=0 and and i++
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{

	printf("Enter the text String:");
	gets(txt);
	printf("Enter the pattern String:");
	gets(pat);
	KMPSearch(pat, txt);
	return 0;
}
