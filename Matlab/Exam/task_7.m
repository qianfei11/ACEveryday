A = [-1, 5, -4; 0, 7, 8; 3, 61, 7];
B = [8, 3, -1; 2, 5, 3; -3, 2, 0];
I = eye(3, 3);
disp('1)');
disp(A+6*B);
disp(A^2-B+I);
disp('2)');
disp(A*B);
disp(A.*B);
disp(B*A);
disp('3)');
disp(A/B);
disp(B\A);
disp('4)');
disp([A, B]);
disp([A([1,3],:); B^2]);