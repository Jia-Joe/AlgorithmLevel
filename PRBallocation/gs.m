

function [ y ] = gs( d )
%GS 此处显示有关此函数的摘要
%   此处显示详细说明
s=lognrnd(0,1.842);

y=1.35*10^7*(d^-3.7)*s;

end