#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> characters;
void solution(int idx, int vowel, int consonant, vector<int> &acc, int &length)
{
    acc.push_back(idx);

    if (characters[idx] == 'a' || characters[idx] == 'e' || characters[idx] == 'i' || characters[idx] == 'o' || characters[idx] == 'u')
        vowel++;
    else
        consonant++;

    if (acc.size() == length)
    {
        if (vowel >= 1 && consonant >= 2)
        {
            for (int i = 0; i < length; i++)
            {
                printf("%c", characters[acc[i]]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = idx + 1; i < characters.size(); i++)
        {
            solution(i, vowel, consonant, acc, length);
        }
    }

    acc.pop_back();
}
int main()
{
    int L, C;
    vector<int> tmp;
    char buffer;
    scanf("%d %d", &L, &C);

    characters.assign(C, ' ');

    for (int i = 0; i < C; i++)
    {
        scanf("%c", &buffer);
        scanf("%c", &characters[i]);
    }

    sort(characters.begin(), characters.end());

    for (int i = 0; i < C; i++)
    {
        solution(i, 0, 0, tmp, L);
    }
    return 0;
}