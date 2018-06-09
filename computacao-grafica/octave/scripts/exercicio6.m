red = imread("laranjeiras_r.tif");
green = imread("laranjeiras_g.tif");
blue = imread("laranjeiras_b.tif");
inf = imread("laranjeiras_nir.tif");

r = im2double(red);
g = im2double(green);
b = im2double(blue);
nir = im2double(inf);

NDVI = (nir - r) ./ (nir + r);
veg = NDVI > 0.4;

RGB = cat(3, red, green, blue);

noveg = 1 - NDVI;

figure;
imshow(RGB);

figure;
imshow(veg);

figure;
imshow(noveg);