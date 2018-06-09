#Leitura da imagem leme.bmp.
image = imread("leme.bmp");
image = im2double(image);

#Utilizando a funcao imadjust para criar uma nova imagem colorida em que as areas escuras da imagem original fiquem mais claras, mas as areas claras da imagem original nao mudem muito de intensidade na nova imagem.
img = imadjust(image, [0 1], [0 1], 0.4);

#Apresentacao da imagem original e nova imagem em unica figura.
subplot(1, 2, 1);
imshow(image);
subplot(1, 2, 2);
imshow(img);