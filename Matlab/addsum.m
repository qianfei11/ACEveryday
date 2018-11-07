n = input('please input n: ');
% i = 1;
% sum = 0;
% while i <= n
%     sum = sum + (1 ./ i .^ 2);
%     i = i + 1;
% end
% disp(sum);
i = 1:n;
t = 1 ./ i .^ 2;
y = sum(t);
disp(y);