%title('协作多小区OFDMA网络布局和用户分布')
R=1/2*sqrt(3);
pt=[-R,1.5;R,1.5;-2*R,0;0,0;2*R,0;-R,-1.5;R,-1.5];
%pt=[R,1.5;2*R,0;R,-1.5;-R,1.5;0,0;-R,-1.5;-2*R,0];
qunliu(0,0,1,1);
ux=zeros(40,7);
uy=zeros(40,7);
ptx=pt(:,1);
pty=pt(:,2);
L = linspace(pi/6,(2+1/6)*pi,7);
xv = cos(L)';yv = sin(L)';
plot(xv,yv,'red');
for i=1:7
    scatter(ptx(i),pty(i),'red','^');
    for j=1:40
        [ux(j,i),uy(j,i)]=us(ptx(i),pty(i));
        scatter(ux(j,i),uy(j,i),'blue','+');
    end
end
ux=ux*1000;
uy=uy*1000;

