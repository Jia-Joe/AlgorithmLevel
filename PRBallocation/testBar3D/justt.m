function [inde] = justt(tt)
inde=zeros(3,1);
for i=1:3
    inde(i)=find(tt(:,i),1);
end