year = input('please input the year: ');
if mod(year, 4) == 0 || mod(year, 100) ~= 0
    disp('ya');
elseif mod(year, 400) == 0
    disp('ya')
else
    disp('nop')
end