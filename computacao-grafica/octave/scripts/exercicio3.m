#Leitura das duas imagens RGB.
image1 = imread("arara_full.png");
image2 = imread("lion.png");

image1 = im2double(image1);
image2 = im2double(image2);

#Mascara espacial para suavizacao linear.
mask = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

#Aplicacao do filtro nas imagens de entrada com a mascara criada. 
img1 = imfilter(image1, mask);
img2 = imfilter(image2, mask);

#Apresentacao das imagens originais e os resultados apos aplicacao da mascara.
subplot(2, 2, 1);
imshow(image1);
subplot(2, 2, 2);
imshow(img1);
subplot(2, 2, 3);
imshow(image2);
subplot(2, 2, 4);
imshow(img2);

