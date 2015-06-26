function [z] = findz(p,ux,uy)
%FINDZ 此处显示有关此函数的摘要
%   此处显示详细说明

z=ones(280,1);
R=1/2*sqrt(3);
pt=[-R,1.5;R,1.5;-2*R,0;0,0;2*R,0;-R,-1.5;R,-1.5]*1000;
for k=1:7
    for i=1:40
        tp=0;
        for j=1:7
            if(j~=k)
                n=40*(j-1)+i;
                tmp=sqrt((ux(i,k)-pt(j,1))^2+(uy(i,k)-pt(j,2))^2);
                tp=tp+p(n)*gs(tmp);
            end
        end
        z((k-1)*40+i,1)=tp;
    end
end
end

