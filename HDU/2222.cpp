#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

const int MAX_N = 26;
const int MAX_NODE = 500010;

struct NODE{
    int cnt;
    NODE *Next[MAX_N], *fail;
    NODE()
    {
        cnt = 0;
        fail = NULL;
        memset(Next, 0, sizeof(Next));
    }
}*head;

void Build_trie(char *s,NODE *head)
{
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        int k = s[i] - 'a';
        if( head->Next[k] == NULL )
            head->Next[k] = new NODE();
        head = head->Next[k];
    }
    head->cnt++;
}

queue<NODE*> q;
void Build_fail(NODE *head)
{
    head->fail = NULL;
    q.push(head);
    while( !q.empty() )
    {
        NODE *now = q.front(); q.pop();
        for(int i=0; i<MAX_N; i++)
            if( now->Next[i] )
            {
                NODE *p = now->fail;
                while( p )
                {
                    if( p->Next[i] )
                    {
                        now->Next[i]->fail = p->Next[i];
                        break;
                    }
                    p = p->fail;
                }
                if( p == NULL )
                    now->Next[i]->fail = head;
                q.push(now->Next[i]);
            }
                        
    }
}

int AC_find(NODE *head, char *s)
{
    int len = strlen(s), sum = 0;
    NODE* p = head;
    for(int i=0; i<len; i++)
    {
        int k = s[i] - 'a';
        while( p->Next[k] == NULL && p != head )
            p = p->fail;
        p = p->Next[k] == NULL ? head : p->Next[k];
        
        NODE *tmp = p;
        while( tmp != head && tmp->cnt != -1 )
        {
            sum += tmp->cnt;
            tmp->cnt = -1;
            tmp = tmp->fail;
        }
    }
    return sum;
}

char s[1000005];
char ss[100];
int main()
{
    int n, ncases;

    scanf("%d", &ncases);
    
    while( ncases-- )
    {
        head = new NODE();
        scanf("%d", &n);        
        while( n-- )
        {
            scanf("%s", ss);
            Build_trie(ss, head);
        }
        
        Build_fail( head );
        
        scanf("%s", s);
        int sum = AC_find( head, s);
        printf("%d\n", sum);
    }

return 0;
}
