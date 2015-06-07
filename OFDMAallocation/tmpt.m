oprs=zeros(10,1);
for i=1:10
    oprs(i)=sum(opr(i,:));
end


bar(foprs);
hold on
bar(oprs);