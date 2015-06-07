function [ y ] = gss(  )
y=zeros(7,1);
R=1/2*sqrt(3);
pt=[-R,1.5;R,1.5;-2*R,0;0,0;2*R,0;-R,-1.5;R,-1.5]*1000;
for i=1:7 
    for j=1:7 
       if(j~=i)
          tmp=sqrt((pt(i,1)-pt(j,1))^2+(pt(i,2)-pt(j,2))^2);
          y(i,1)=y(i,1)+gg(tmp);
       end
    end
end

end
