function [ y,tol ] = dp( X )
%DP �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
n=size(X,1);
wrv=zeros(n,n);
wri=zeros(n,n);
y=zeros(n,1);
for i=n:1
    x=X(:,i);
    [vmax,imax]=max(x);
end
end

