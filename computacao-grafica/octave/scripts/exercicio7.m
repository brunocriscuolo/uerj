image = imread('digital.png'); #Le o arquivo de imagem.
img = rgb2gray(image); #Transforma imagem colorida (RGB) em escala de cinza.
img = im2double(img); #Manipula a escala de intensidade de cores, permitindo apenas valores entre 0 e 1.
                    
T = 0.4;
var = 5;

while(var >= 0.2)
  aux = T;
  
  u1 = mean(img(find(img < T)));
  u2 = mean(img(find(img >= T)));
  T = (u1 + u2)/2;
  
  var = aux - T;
endwhile

lim = img > T; #Limiariza a imagem.

subplot(1, 3, 1);
imshow(image);
subplot(1, 3, 3);
imshow(lim);
subplot(1, 3, 2);
imhist(image);