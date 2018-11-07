t = 0:pi/10:6*pi;
y = 1-exp(-0.3*t).*cos(0.7*t);
figure
subplot(3,2,1),plot(t,y);title('normal');
subplot(3,2,2),plot(t,y,'gd');title('gd')
subplot(3,2,3),plot(t,y,'k:');title('k:');
subplot(3,2,4),plot(t,y,'b:*');title('b:*');
subplot(3,2,5),plot(t,y,'m-d');title('m-d');
subplot(3,2,6),plot(t,y,'rp');title('rp');