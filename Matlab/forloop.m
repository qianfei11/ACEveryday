for j = 1:1:10
    num(j) = 1 / (j + 1);
end
sum = 0;
for t=num
    sum = sum + t;
end
disp(sum);