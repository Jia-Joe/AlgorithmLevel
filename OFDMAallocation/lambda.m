p0=0.6651;
s=sum(gs0);
I=ones(7,1);
lambda=ones(7,1);
for i=1:7
    N0=sqrt(db2p(-100))*randn();
    I(i)=(s-gs0(i))*p0;
    tmp=(N0+I(i))/gs0(i);
    lambda(i)=1/(p0+tmp);
end