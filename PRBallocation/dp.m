function [ y,tol ] = dp( X )
%DP 此处显示有关此函数的摘要
%   此处显示详细说明
n=size(X,1);
wrv=zeros(n,n);
wri=zeros(n,n);
y=zeros(n,1);
for i=n:1
    x=X(:,i);
    [vmax,imax]=max(x);
end
end

