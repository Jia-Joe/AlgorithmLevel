function [] = dynamic3Dbar()
xy=[1.5 2.5 4 5 6 7.5 8.5];
for i=1:20
    X=10*rand(4,10);
    for j=1:7
        subplot(3,3,xy(j));
        h=bar3(X);
        %    h = bar3(X+i-1);
        title(['K = ',num2str(j)]);
        colormap cool;
        axis([0 11 0 5 0 10]);
        for k = 1:length(h)
            zdata = get(h(k),'ZData');
            set(h(k),'CData',zdata,...
                'FaceColor','interp')
        end
        
        
    end
    if(i==1)
        pause(0.5);
    else
        pause(0.02);
    end
    
end

end

