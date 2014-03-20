#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 410
struct Line{
    int flag;
    double x,y1,y2;
    Line(){}
    Line(double x_,double y1_,double y2_,int flag_):x(x_),y1(y1_),y2(y2_),flag(flag_){}
}line[N];
double y[N];
struct Point{
    double x,y;
}point[N];
struct node{
    int cover,l,r;
    double lf,rf,len;
}tree[2000];
void build(int p,int l,int r){
    tree[p].cover=tree[p].len=0;
    tree[p].l=l;tree[p].r=r;
    if (l+1==r){
        tree[p].lf=y[l];tree[p].rf=y[r];
        return;
    }
    int mid=(l+r)>>1;
    build(2*p,l,mid);
    build(2*p+1,mid,r);
    tree[p].lf=tree[2*p].lf;tree[p].rf=tree[2*p+1].rf;
}
void update(int p){
    if (tree[p].cover>0)tree[p].len=tree[p].rf-tree[p].lf;
    else  
        if (tree[p].l==tree[p].r)tree[p].len=0;
        else tree[p].len=tree[2*p].len+tree[2*p+1].len;
}
void modify(int p,double i,double j,int flag){
    int l=tree[p].l,r=tree[p].r;
    double lf=tree[p].lf,rf=tree[p].rf;
    if (i==j)return;
    if (i==lf&&j==rf){
        tree[p].cover+=flag;update(p);
        return;
    }
    int mid=(l+r)>>1;
    if (j<=y[mid])modify(2*p,i,j,flag);
    else if (i>=y[mid])modify(2*p+1,i,j,flag);
    else{
        modify(2*p,i,y[mid],flag);modify(2*p+1,y[mid],j,flag);
    }
    update(p);
}
int n,cases;
bool cmp_(const Line &a,const Line &b){
    return a.x<b.x;
}
int main(){
    //freopen("input.txt","r",stdin);
    while (scanf("%d",&n),n){
        int k=0,l=0;
        while (n--){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            y[k++]=y1;y[k++]=y2;
            line[l++]=Line(x1,y1,y2,1);
            line[l++]=Line(x2,y1,y2,-1);
        }
        sort(y,y+k);
        build(1,0,k-1);
        sort(line,line+l,cmp_);
        modify(1,line[0].y1,line[0].y2,line[0].flag);
        double ans=0;
        for (int i=1;i<l;i++){
            ans+=(line[i].x-line[i-1].x)*tree[1].len;
            modify(1,line[i].y1,line[i].y2,line[i].flag);
        }
        printf("Test case #%d\n",++cases);
          printf("Total explored area: %.2lf\n\n",ans);
      }
      return 0;
}
            
        
    
        