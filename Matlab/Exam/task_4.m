t = 0:0.1:10;
y1 = exp(-0.1*t);
y2 = exp(-0.2*t);
y3 = exp(-0.5*t);
figure;
hold on;
title('TASK-4');
plot(t, y1, 'r-');
plot(t, y2, 'bo');
plot(t, y3, 'g*');