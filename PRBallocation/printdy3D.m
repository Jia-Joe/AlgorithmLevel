function [tol] = printdy3D( pf )
xy=[1.5 2.5 4 5 6 7.5 8.5];
tol=zeros(11,7);
for i=1:11
    X=pf(:,i);
    Xr=reshape(X,40,7);
    for j=1:7
        Xs=Xr(:,j);
        tol(i,j)=sum(Xs);
        sx=(reshape(Xs,10,4))';
        subplot(3,3,xy(j));
        h=bar3(sx);
        %    h = bar3(X+i-1);
        title(['K = ',num2str(j)]);
        colormap cool;
        axis([0 11 0 5 0 1]);
        for k = 1:length(h)
            zdata = get(h(k),'ZData');
            set(h(k),'CData',zdata,...
                'FaceColor','interp')
        end
        grid on;
        
    end
    if(i==1)
        pause(6);
    else
        pause(0.03);
    end
    
end

end





