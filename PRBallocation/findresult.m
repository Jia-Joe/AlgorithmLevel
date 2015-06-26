result=zeros(40,7,11);
opr=zeros(11,7);

for t=1:11
    for k=1:7
        [opr(t,k),result(:,k,t)] = assignment(wr,k,t);
        
    end
end