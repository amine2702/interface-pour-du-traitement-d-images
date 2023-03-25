#include "cimg.h"
#include <iostream>

// Permet d'écrire « Image » plutôt que le type long
// Ici, « unsigned char » sera le type pour les canaux de couleur
// dont les valeurs iront de 0 à 255
using Image = cimg_library::CImg<unsigned char>;

void niv_de_gris(Image image){

	for(int y = 0; y < image.height(); ++y) {
		for(int x = 0; x < image.width(); ++x) {
			unsigned char r = image(x, y, 0); // canal rouge
			unsigned char g = image(x, y, 1); // canal vert
			unsigned char b = image(x, y, 2); // canal bleu

			unsigned char value = (r + g + b) / 3;

			// modification des 3 canaux
			image(x, y, 0) = value;
			image(x, y, 1) = value;
			image(x, y, 2) = value;
		}
	}
	  image.save("output_niv_gris.jpg"); // enregistre l'image modifiée
}

void sepia(Image image){

	for(int y = 0; y < image.height(); ++y) {
		for(int x = 0; x < image.width(); ++x) {
		
			// modification des 3 canaux
		
			unsigned char base_red = image(x, y, 0);
			unsigned char base_green = image(x, y, 1);
			unsigned char base_blue = image(x, y, 2);
			
			int r = 0.393 * base_red + 0.769 * base_green + 0.189 * base_blue;
			if (r > 255) image(x, y, 0) = 255; else image(x, y, 0) = r; // lié au pb de saturation 
				 
			int g = 0.349 * base_red + 0.686 * base_green + 0.168 * base_blue;
			if (g > 255) image(x, y, 1) = 255; else image(x, y, 1) = g;
			
			int b = 0.272 * base_red + 0.534 * base_green + 0.131 * base_blue;
			if (b > 255) image(x, y, 2) = 255; else image(x, y, 2) = b;
			
			
		}
	}
	  image.save("output_sepia.jpg"); // enregistre l'image modifiée
}



void choix_filtre(image im_source){
	std :: cout << "voici les filtres qu'on peut appliquer à l'image :" << std :: endl;
	std :: cout <<  "noir et blanc --> 1 " << std :: endl;
	std :: cout << "sépia -->  2" << std :: endl;
	int filtre;
	std :: cout << "donnez votre choix avec le chiffre associé :" << std :: endl;
	std :: cin >> filtre;
	if (filtre == 1) niv_de_gris(image im_source);
	if (filtre == 2) sepia(image im_source);
	else std :: cout << "aucun filtre ne correspond" << std :: endl;
}

int main() {
	
	Image im_source("input.jpg"); // charge le fichier input.jpg
	choix_filtre();
	/*	  

	std :: cout << "taille de l'image : " << image. height() << " et " <<   image.width () << std :: endl;
	
	//niv_de_gris(image);
	//sepia(image);		
	*/
}


