function [z,index] = assignment(X,k,t)
% C=rand(12);%Ч�ʾ���C
C=X(:,:,k,t);
n=size(C,1);%����C��������n
index=zeros(n,1);
maxc=max(max(C));
C=maxc-C;
C=C(:);%����Ŀ�꺯��ϵ����������C�����ų�һ�����������ɡ�
A=[];B=[];%û�в���ʽԼ��
Ae=zeros(2*n,n^2);%�����Լ����ϵ������a
for i=1:n
    for j=(i-1)*n+1:n*i
        Ae(i,j)=1;
    end
    for k=i:n:n^2
       Ae(n+i,k)=1;
    end
end
Be=ones(2*n,1);%��ʽԼ���Ҷ���b
Xm=zeros(n^2,1);%���߱����½�Xm
XM=ones(n^2,1);%���߱����Ͻ�XM
[x,z]=linprog(C,A,B,Ae,Be,Xm,XM);%ʹ��linprog���
x=reshape(x,n,n);%��������x�����ų�һ��n�׷���
Assignment=round(x);
for i=1:n
    index(i)=find(Assignment(:,i),1);
end
z=n*maxc-z;
% disp('���Ž����Ϊ:');%���ָ�ɷ���������ֵ
% Assignment=round(x)%ʹ��round������������ȡ��
% disp('���Ž�Ϊ:');
% z
end