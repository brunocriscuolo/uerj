#Aluno: Bruno Costa Criscuolo
#Matrícula: 201320712211

function translation_object(mat)
  
  numCol = size(mat,2);
  alpha = pi/4;
  teta = pi/6;
  figure;
  axis([-10 10 -10 10]);
  
  while alpha < 10000
    
    tx = (max(mat(1,:)) + min(mat(1,:)))/2;
    ty = (max(mat(2,:)) + min(mat(2,:)))/2;
      
    T1 = [1 0 -tx; 0 1 -ty; 0 0 1];
    T2 = [cos(alpha) -sin(alpha) 0; sin(alpha) cos(alpha) 0; 0 0 1];
    T3 = [1 0 tx; 0 1 ty; 0 0 1];
    T4 = [cos(teta) -sin(teta) 0; sin(teta) cos(teta) 0; 0 0 1];
    
    T = T4*T3*T2*T1*mat;
  
    hold on;
    
    for i=1:numCol-1
     h(i) = line([T(1,i) T(1,i+1)], [T(2,i) T(2,i+1)]);
    endfor
    h(i+1) = line([T(1,i+1) T(1,1)], [T(2,i+1) T(2,1)]);

    pause(0.1);
   
    delete(h);
    drawnow();
    pause(0.01);
    
    alpha = alpha + 5;
    teta = teta + 0.1;
    
  endwhile
    
endfunction
