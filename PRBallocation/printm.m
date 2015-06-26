function [] = printm( result,pf )
xy=[1.5 2.5 4 5 6 7.5 8.5];

sx=zeros(40,1);
for i=1:10
    for j=1:7
        for ii=1:40;
            nn=result(ii,j,i);
            sx(ii)=pf((j-1)*40+nn,i);
        end
        subplot(3,3,xy(j));
        h=bar(sx);
        %    h = bar3(X+i-1);
        title(['K = ',num2str(j)]);
        colormap cool;
        axis([0 40 0 1]);
        grid off;
        
    end
    if(i==1)
        pause(6);
    else
        pause(0.3);
    end
    
end

end





