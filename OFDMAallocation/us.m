function [o1,o2] = us(x,y)
%US 随机产生位于六边形内的点，六边形中心坐标为（x，y）
%   此处显示详细说明
r=0.9;
L = linspace(pi/6,(2+1/6)*pi,7);
xv = x+cos(L)';yv = y+sin(L)';
while(1)
    x1=x-r+2*r*rand();
    y1=y-r+2*r*rand();
    if(abs(x1-x)>0.02&&abs(y1-y)>0.02&&inpolygon(x1,y1,xv,yv))
        break;
    end
end
o1=x1;
o2=y1;
end

