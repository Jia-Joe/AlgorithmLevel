function [z,index] = assignment(X,k,t)
% C=rand(12);%效率矩阵C
C=X(:,:,k,t);
n=size(C,1);%计算C的行列数n
index=zeros(n,1);
maxc=max(max(C));
C=maxc-C;
C=C(:);%计算目标函数系数，将矩阵C按列排成一个列向量即可。
A=[];B=[];%没有不等式约束
Ae=zeros(2*n,n^2);%计算等约束的系数矩阵a
for i=1:n
    for j=(i-1)*n+1:n*i
        Ae(i,j)=1;
    end
    for k=i:n:n^2
       Ae(n+i,k)=1;
    end
end
Be=ones(2*n,1);%等式约束右端项b
Xm=zeros(n^2,1);%决策变量下界Xm
XM=ones(n^2,1);%决策变量上界XM
[x,z]=linprog(C,A,B,Ae,Be,Xm,XM);%使用linprog求解
x=reshape(x,n,n);%将列向量x按列排成一个n阶方阵
Assignment=round(x);
for i=1:n
    index(i)=find(Assignment(:,i),1);
end
z=n*maxc-z;
% disp('最优解矩阵为:');%输出指派方案和最优值
% Assignment=round(x)%使用round进行四舍五入取整
% disp('最优解为:');
% z
end