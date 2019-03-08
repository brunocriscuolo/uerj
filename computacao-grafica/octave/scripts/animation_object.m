#Aluno: Bruno Costa Criscuolo
#Matrícula: 201320712211

function animation_object(mat)
  
  numCol = size(mat,2);
  p = mat';
  ang = pi/4;
  figure;
  axis([-10 10 -10 10]);
  
  while ang < 10000
    
    tx = (max(mat(1,:)) + min(mat(1,:)))/2;
    ty = (max(mat(2,:)) + min(mat(2,:)))/2;
  
    T1 = [1 0 -tx; 0 1 -ty; 0 0 1];
    T2 = [cos(ang) -sin(ang) 0; sin(ang) cos(ang) 0; 0 0 1];
    T3 = [1 0 tx; 0 1 ty; 0 0 1];
  
    T = T3*T2*T1*mat;
  
    hold on;
    
    for i=1:numCol-1
     h(i) = line([T(1,i) T(1,i+1)], [T(2,i) T(2,i+1)]);
    endfor
    h(i+1) = line([T(1,i+1) T(1,1)], [T(2,i+1) T(2,1)]);

    pause(0.1);
    
    delete(h);
    drawnow();
    pause(0.01);
    
    ang = ang + 5; 
    
  endwhile
    
endfunction
