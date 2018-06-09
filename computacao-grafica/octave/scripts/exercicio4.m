#Leitura das duas imagens RGB.
image1 = imread("arara_full.png");
image2 = imread("lion.png");

image1 = im2double(image1);
image2 = im2double(image2);

#Aplicacao do filtro nas imagens de entrada com tres mascaras distintas disponi­veis a partir da funcao 'fspecial'.
img1 = imfilter(image1, fspecial('laplacian'));
img2 = imfilter(image1, fspecial('gaussian'));
img3 = imfilter(image1, fspecial('sobel'));
img4 = imfilter(image2, fspecial('laplacian'));
img5 = imfilter(image2, fspecial('gaussian'));
img6 = imfilter(image2, fspecial('sobel'));

#Apresentacao das imagens originais e os resultados aposs aplicacao da mascara.
figure;
subplot(2, 2, 1);
imshow(image1);
title('Original');
subplot(2, 2, 2);
imshow(img1);
title('Laplacian Filter');
subplot(2, 2, 3);
imshow(img2);
title('Gaussian Filter');
subplot(2, 2, 4);
imshow(img3);
title('Sobel Fliter');
figure;
subplot(2, 2, 1);
imshow(image2);
title('Original');
subplot(2, 2, 2);
imshow(img4);
title('Laplacian Filter');
subplot(2, 2, 3);
imshow(img5);
title('Gaussian Filter');
subplot(2, 2, 4);
imshow(img6);
title('Sobel Fliter');