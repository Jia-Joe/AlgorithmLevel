function main()
% 现要画出其分组3维柱状图。
% 最简单的写法如下：

clc; clear all; close all;
label1 = {'张三', '李四', '王二', '胡汉三'};%标签
label2 = {'合格率','次品率','废品率'};%标签
Z = rand(3, 4);
hb = bar3(Z);
renderCDataByHeight(hb, false);
colorbar;
set(gca, 'xticklabel', label1);
set(gca, 'yticklabel', label2);
view([-28, 40])
%文字标注
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