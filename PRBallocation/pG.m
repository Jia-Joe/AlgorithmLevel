function [y] = pG(k,m,f,d,t,pf)
%PG ��k��С����m���û����䵽��f��PRB��ʱ��pG
%   �˴���ʾ��ϸ˵��
y=zeros(1,7);
%mi=(k-1)*40+m;
%fi=(k-1)*40+f;
for i=1:7
    fi=(i-1)*40+f;
    y(i)=pf(fi,t)*gs(d(m,i,k));
end
end

