function [ SUM ] = CSIE( initial, N )
%CISE Summary of this function goes here
%   Detailed explanation goes here

SUM = 1;
for i = initial : (N + initial -1 )
    SUM = SUM * i;
    
end

