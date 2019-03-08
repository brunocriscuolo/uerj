#Aluno: Bruno Costa Criscuolo
#Matrícula: 201320712211

function rotate_object(ang, mat)
  
  ang = ang*pi/180;
  numCol = size(mat,2);
  p = mat';
  
  figure;
  axis([-10 10 -10 10]);  
  hold on;
  for i=1:numCol-1
    line([p(i,:)(1) p(i+1,:)(1)], [p(i,:)(2) p(i+1,:)(2)]);
  endfor
  line([p(i+1,:)(1) p(1,:)(1)], [p(i+1,:)(2) p(1,:)(2)]);
  
  tx = (max(mat(1,:)) + min(mat(1,:)))/2;
  ty = (max(mat(2,:)) + min(mat(2,:)))/2;
  
  T1 = [1 0 -tx; 0 1 -ty; 0 0 1];
  T2 = [cos(ang) -sin(ang) 0; sin(ang) cos(ang) 0; 0 0 1];
  T3 = [1 0 tx; 0 1 ty; 0 0 1];
  
  T = T3*T2*T1*mat;
  
  figure;
  axis([-10 10 -10 10]);  
  hold on;
  for i=1:numCol-1
    line([T(1,i) T(1,i+1)], [T(2,i) T(2,i+1)]);
  endfor
  line([T(1,i+1) T(1,1)], [T(2,i+1) T(2,1)]);
  
endfunction
