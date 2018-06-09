image = imread('Ferrari.jpg'); #Le o arquivo de imagem.
img = rgb2gray(image); #Transforma imagem colorida (RGB) em escala de cinza.
img = im2double(img); #Manipula a escala de intensidade de cores, permitindo apenas valores entre 0 e 1.
              
x = [-1 0 1; -2 0 2; -1 0 1]; #Filtro de Sobel aplicado ao eixo x.
y = [-1 -2 -1; 0 0 0; 1 2 1]; #Filtro de sobel aplicado ao eixo y. 
              
Gx = imfilter(img, x); #Derivada parcial em x.
Gy = imfilter(img, y); #Derivada parcial em y.
              
grad = [Gx,Gy]; #Vetor gradiente.
mag = abs(Gx) + abs(Gy); #Calculo do valor de magnitude do gradiente.  
alpha = atan2(Gy, Gx); #Angulo do gradiente.
              
GL = mag > 0.3; #Limiariza a imagem para valores de magnitude do gradiente maiores que 0,4.
beta = alpha .* GL;

map = [0 0 0; 1 0 0; 0 1 0; 0 0 1; 1 1 0]; #Mapa de cores que sera aplicado a imagem indexada.

index = zeros(size(beta, 1), size(beta,2), size(beta,3), size(beta,4), size(beta,5)); #Cria matriz inicial completamente zerada.

index(find(beta < (3/5)*pi & beta > (1/5)*pi)) = 4;
index(find(beta < (1/6)*pi & beta > (0)*pi)) = 5;
index(find(beta < (1)*pi & beta > (5/6)*pi)) = 5;
index(find(beta < (1/3)*pi & beta > (1/5)*pi)) = 3;
index(find(beta < (5/6)*pi & beta > (2/3)*pi)) = 2;

imshow(image); #Mostra a imagem original.
figure;
imshow(mag); #Mosta imagem com a magnitude do gradiente.
out = medfilt2(index);
figure;
imshow(out, map);