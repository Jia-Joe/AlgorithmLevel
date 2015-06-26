function renderCDataByHeight(hb, interp)
% hbΪbar3���ص���ά��״ͼ���,
% ��hb�ĸ����Ӱ��߶���ȾCData���ԣ�
% interpָ���Ƿ񽥱�(Ĭ��Ϊfalse)
% interp==true:ÿ�����Ӵ��µ�����ɫ����
% interp==false:ÿ������һ����ɫ
% hb�о������������������,hb(j)Ϊ��j�����ݵľ��
if nargin == 1
    % interpĬ��ֵ
    interp=false;
end
if interp == true
    %ÿ�����Ӵ��µ�����ɫ����
    shading interp;
    for j = 1 : length(hb)
        % ��Zdata����ȥ���Cdata����
        zdata = get(hb(j), 'Zdata');
        set(hb(j), 'Cdata', zdata);
        % ���ñ�����ɫ
        set(hb, 'EdgeColor', [0.5 0.5 0.5]);
    end
else
    % ÿ������һ����ɫ
    for j = 1:length(hb)
        % ����hb(j)��Cdata����
        % ����CData��ֵcdata�����滻���ֵ
        % cdata����ZData�Ļ������޸Ķ���
        cdata = get(hb(j), 'ZData');
        % cdata��������6������������
        m = size(cdata,1)/6;
        % ���cdata
        for i = 1:m
            % ����cdata��(i,j)���ݶ�Ӧ��6��
            % ����6�е�ֵ�����(i,j)���ݵ�ֵ
            vij = cdata((i-1)*6+2,2);%����cdata(ZData)�л��(i,j)���ݵ�ֵ
            cdata((i-1)*6+1:(i-1)*6+6,:) = vij;%(i,j)���ݶ�Ӧ��6��������
        end
        set(hb(j), 'Cdata', cdata);%��cdata����Cdata����
    end
end

