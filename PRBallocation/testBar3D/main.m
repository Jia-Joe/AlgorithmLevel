function main()
% ��Ҫ���������3ά��״ͼ��
% ��򵥵�д�����£�

clc; clear all; close all;
label1 = {'����', '����', '����', '������'};%��ǩ
label2 = {'�ϸ���','��Ʒ��','��Ʒ��'};%��ǩ
Z = rand(3, 4);
hb = bar3(Z);
renderCDataByHeight(hb, false);
colorbar;
set(gca, 'xticklabel', label1);
set(gca, 'yticklabel', label2);
view([-28, 40])
%���ֱ�ע
for i = 1:size(Z,1)
    for j = 1:size(Z,2)
        text(j, i, Z(i,j)+0.01, num2str(Z(i,j)));
    end
end
pause(0.5);
renderCDataByHeight(hb, true);
pause(0.5);
renderCDataByHeight(hb, true);
colormap spring; 