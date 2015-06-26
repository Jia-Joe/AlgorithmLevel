pf=zeros(280,11);
If=zeros(40,7);
%%%%%%%%%%%%%%%%%%%%%%≥ı ºªØ%%%%%%%%%%%%%%%%%%%%%%%
lam=lambda;
pmax=1;
Rw=eye(40)*0.0001;
Rv=eye(40)*0.0001;
q=ones(40);
K=zeros(40);
pf(:,1)=ones(280,1)*0.4988;
for i=1:7
    If(:,i)=I(i)*ones(40,1);
end
R=1/2*sqrt(3);
pt=[-R,1.5;R,1.5;-2*R,0;0,0;2*R,0;-R,-1.5;R,-1.5]*1000;
tmp=zeros(40,7);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for T=2:11    
    tempz=findz(pf(:,T-1),ux,uy);
    tz=reshape(tempz,40,7);
    q=q+Rw;
    K=q/(q+Rv);
    If=If+K*(tz-If);
    q=(eye(40)-K)*q;
%       If=If+randn(40,7);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
    for i=1:40
        for k=1:7
           n=(k-1)*40+i;
           N0=sqrt(db2p(-100))*randn();
           tmp(i,k)=sqrt((ux(i,k)-pt(k,1))^2+(uy(i,k)-pt(k,2))^2); 
           pf(n,T)=1/lam(k)-(N0+If(i,k))/gs(tmp(i,k));
           while(~((pf(n,T)<pmax)&&(pf(n,T)>0)))
               if(pf(n,T)<pmax)
                   break;
               end
           end
           

           
        end
    end    

end
tol=printdy3D(pf);