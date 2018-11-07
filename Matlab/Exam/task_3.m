x = 0:8/100:8;
y = 0.5*x.*(x<=2) + 1.5-0.25*x.*(x>2&x<=6) + 0.5.*(x>=6);
figure;
hold on;
title('TASK-3');
plot(x, y, 'r-');