#Leitura das imagens Einstein_low_contrast.png, Einstein_med_contrast.png e Einstein_high_contrast.png.
elc = imread('Einstein_low_contrast.png');
emc = imread('Einstein_med_contrast.png'); 
ehc = imread('Einstein_high_contrast.png');

#Apresentacao das imagens.
figure;
imshow(elc);
figure;
imshow(emc);
figure;
imshow(ehc);

#Apresentacao dos respectivos histogramas.
figure;
imhist(elc);
figure;
imhist(emc);
figure;
imhist(ehc);

#Utilizando a funcao imadjust para melhorar o contraste da imagem Einstein_low_contrast.png.
newImage = imadjust(elc);

#Apresentacao da nova imagem e seu histograma em unica figura. 
subplot(1, 2, 1);
imshow(newImage);
subplot(1, 2, 2);
imhist(newImage);