a = [1, 2, 3; 4, 5, 6];
b = [7, 8, 9; 10, 11, 12];
try
    c = a * b;
catch
    c = a .*b;
end
disp(c);
disp(lasterr);