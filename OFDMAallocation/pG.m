function [y] = pG(k,m,f,d,t,pf)
%PG 第k个小区第m个用户分配到第f个PRB块时的pG
%   此处显示详细说明
y=zeros(1,7);
%mi=(k-1)*40+m;
%fi=(k-1)*40+f;
for i=1:7
    fi=(i-1)*40+f;
    y(i)=pf(fi,t)*gs(d(m,i,k));
end
end

