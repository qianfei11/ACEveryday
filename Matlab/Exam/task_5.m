t = 0:2*pi/49:2*pi;
y1 = sin(2*t-0.3);
y2 = 3*cos(t+0.5);
figure;
hold on;
title('TASK-5');
plot(t, y1, 'r-o');
plot(t, y2, 'b:*');