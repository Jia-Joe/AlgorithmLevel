d=zeros(40,7,7);
%%%%第k个小区内第i个用户到第j个基站的距离%%%%
for k=1:7
    for i=1:40
        for j=1:7
            d(i,j,k)=sqrt((ux(i,k)-pt(j,1))^2+(uy(i,k)-pt(j,2))^2); 
        end
    end
end

