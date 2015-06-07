wr=zeros(40,40,7,11);
for t=1:11;
%t=2;
for k=1:7;
    for f=1:40
       for m=1:40
           N0=sqrt(db2p(-100))*randn();
           pg=pG(k,m,f,d,t,pf);
           tmp=0;
           for i=1:7
               if(k~=i)
                   tmp=tmp+pg(i);
               end
           end
           wr(m,f,k,t)=log(1+pg(k)/(N0+tmp))/log(2);
       end
    end
end
end