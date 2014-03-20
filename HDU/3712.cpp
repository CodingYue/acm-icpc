#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#define pi acos(-1)
#define eps 1e-9
using namespace std;
struct Point
{
    double x,y;
    int id;
    int flag;
    Point(){}
    Point(double x0,double y0):x(x0),y(y0){};
};
struct Line
{
    Point a,b;
    int ind;
    Line(){}
    Line(Point a0,Point b0):a(a0),b(b0){};
};
int Sig(double a)
{
    return a<-eps?-1:a>eps;
}
Point operator -(Point a,Point b)
{
    Point ret;
    ret.x=a.x-b.x;
    ret.y=a.y-b.y;
    return ret;
}
Point operator+(Point a,Point b)
{
    Point ret;
    ret.x=b.x+a.x;
    ret.y=b.y+a.y;
    return ret;
}
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int Is_inter(Line l1,Line l2)
{
    double r1=Xmult(l1.a,l1.b,l2.a);
    double r2=Xmult(l1.a,l1.b,l2.b);
    return Sig(r1*r2)<0;
}
Point Intersection(Line u,Line v)
{
    Point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/
        ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}
int cmp(Point a,Point b)
{
    return a.y>b.y;
}
Line Get_sx(Line l)
{
    Point tmp;
    tmp.x=l.b.y-l.a.y;
    tmp.y=l.a.x-l.b.x;
    return Line(Point(0,0),tmp);
}
double Get_ange(Line l)
{
    double ange=atan2(l.b.y-l.a.y,l.b.x-l.a.x);
    if(ange<0)
        ange+=pi;
    return ange;
}
double pow(double a)
{
    return a*a;
}
Point Get_xz1(double sa,double ang1,double ang2,Point vab,double n2)
{
    double sin_a=sin(sa);
    double si=sin_a*sqrt(1-pow(sin_a/n2))-sqrt(1-pow(sin_a))*sin_a/n2;//
    double ci=sqrt(1-pow(si));
    double x=vab.x;
    double y=vab.y;
    if(Sig(ang1-ang2)==0)
        return vab;
    if(Sig(ang1-ang2)<0)//逆时针
    {
        vab.x=x*ci-y*si;
        vab.y=x*si+y*ci;
    }
    else//顺时针
    {
        vab.x=x*ci+y*si;
        vab.y=-x*si+y*ci;
    }
    return vab;
}
Point Get_xz2(double sa,double ang1,double ang2,Point vab,double n2)
{
    double sin_a=sin(sa);
    double si=n2*sin_a*sqrt(1-pow(sin_a))-sqrt(1-pow(sin_a*n2))*sin_a;//
    double ci=sqrt(1-pow(si));
    double x=vab.x;
    double y=vab.y;
    if(Sig(ang1-ang2)==0)
        return vab;
    if(Sig(ang1-ang2)>0)//逆时针f
    {
        vab.x=x*ci-y*si;
        vab.y=x*si+y*ci;
    }
    else//顺时针
    {
        vab.x=x*ci+y*si;
        vab.y=-x*si+y*ci;
    }
    return vab;
}
int Judge(Point a,Point b,Point c)
{
    return !(a.x>=min(b.x,c.x) && a.x<=max(b.x,c.x)
            && a.y>=min(b.y,c.y) && a.y<=max(b.y,c.y));
}
int main()
{
    //freopen("in","r",stdin);
    int t;
    double n2;
    int inter_n;
    Point inter[5];
    Point p[5];
    Line l[5];
    Line lab;
    Point vab;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&lab.a.x,&lab.a.y,&lab.b.x,&lab.b.y);
        vab=lab.b-lab.a;
        for(int i=0;i<3;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        scanf("%lf",&n2);
        for(int i=0;i<2;i++)
            for(int j=i+1;j<3;j++)
                l[3-i-j]=Line(p[i],p[j]);
        inter_n=0;
        for(int i=0;i<3;i++)
        {
            if(Is_inter(lab,l[i]))
            {
                Point pp=Intersection(lab,l[i]);
                inter[inter_n]=Intersection(lab,l[i]);
                if(Judge(lab.a,lab.b,pp))//判定他发射的方向是否正确
                {
                    inter[inter_n].id=i;
                    inter[inter_n++].flag=0;
                }
            }
        }
        if(inter_n==0)//没有严格交点 说明他不会与任何边相交
        {
            if(lab.a.y<=lab.b.y)
                printf("Error\n");
            else
            {
                Point pp=Intersection(lab,Line(Point(0,0),Point(1,0)));
                printf("%.3f\n",pp.x);
            }
        }
        else//有交点 但是还要求有没有直接穿过的点
        {
            //求有没有直接穿过的点
            for(int i=0;i<3;i++)
                if(!Sig(Xmult(lab.a,lab.b,p[i])) )
                {
                    inter[inter_n]=p[i];
                    inter[inter_n].id=i;//标记他是直接穿过的点
                    inter[inter_n++].flag=1;
                }
            Line sx;
            Point p1,p2,p0;
            double ang1,ang2,sa;
            sort(inter,inter+inter_n,cmp);
            if(inter[0].flag!=1)
            {
                sx=Get_sx(l[inter[0].id]);//找到法向量
                p1=inter[0];//找到第一个接触点
                ang1=Get_ange(lab);//求出其角度
                ang2=Get_ange(sx);
                sa=fabs(ang1-ang2);
                vab=Get_xz1(sa,ang1,ang2,vab,n2);
                //printf("%.3lf %.3lf\n",vab.x,vab.y);
                //找第二条边 进行第二次折射
                int ind;
                lab=Line(p1,p1+vab);
                if(Sig(Xmult(lab.a,lab.b,p[inter[0].id]))!=0)//第二个点没有被直接穿过
                {
                    for(int i=0;i<3;i++)//知道第二个折射点
                    {
                        if(i==inter[0].id)
                            continue;
                        if(Is_inter(lab,l[i]))
                        {
                            ind=i;
                            break;
                        }
                    }
                    sx=Get_sx(l[ind]);//找到法向量
                    ang1=Get_ange(lab);//求出其角度
                    ang2=Get_ange(sx);
                    sa=fabs(ang1-ang2);
                    vab=Get_xz2(sa,ang1,ang2,vab, n2);
                    p2=Intersection(lab,l[ind]);
                    lab=Line(p2,p2+vab);
                    //printf("%.3lf %.3lf\n",vab.x,vab.y);
                }
            }
            else//==-1 直接跳过第一步折射 进入第二步骤折射 交点一定是第二个点 inter[1]
            {
                //    printf("111\n");
                sx=Get_sx(l[inter[1].id]);//找到法向量
                ang1=Get_ange(lab);//求出其角度
                ang2=Get_ange(sx);
                sa=fabs(ang1-ang2);
                vab=Get_xz2(sa,ang1,ang2,vab,n2);
                p2=inter[1];
                lab=Line(p2,p2+vab);
            }
            if(Sig(vab.y)>=0)
            {
                printf("Error\n");
            }
            else
            {
                Point p0=Intersection(lab,Line(Point(0,0),Point(1,0)));
                printf("%.3f\n",p0.x);
            }
        }
    }
    return 0;
}
