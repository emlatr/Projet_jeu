#include "sdl-light.h"
//#include "main.c"

int tab_lab (world *tab[][]){
	tab[365][335];
	int i, j;
	//mur gauche
	for(i=0; i<5; i++){
		for(j=0; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur bas
	for(i=0; i<365; i++){
		for(j=330; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur haut
	for(i=30; i<365; i++){
		for(j=0; j<5; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}
	//mur droit
	for(i=360; i<365; i++){
		for(j=0; j<335; j++){
			tab[i][j] = 1;//blanc (mur)
		}
	}

	//chemin horizontal sont fait pendant la verticale
	//chemin 1
	for(i=5; i<30; i++){
		for(j=0; j<330; j++){
			tab[i][j] = 0;//noir
		}
		for(j=330; j<335; j++){
			tab[i][j] = 1;
		}
	}
	//mur 2
	for(i=30; i<35; i++){
		for(j=5; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<335; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 2
	for(i=35; i<60; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 3
	for(i=60; i<65; i++){
		for(j=5; j<35; j++){
			tab[i][j] = 1;
		}
		for(j=35; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<125; j++){
			tab[i][j] = 1;
		}
		for(j=125; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 3
	for(i=65; i<90; i++){
		for(j=5; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 4
	for(i=90; i<95; i++){
		for(j=5; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<260; j++){
			tab[i][j] = 0;
		}
		for(j=260; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 4
	for(i=95; i<120; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<125; j++){
			tab[i][j] = 1;
		}
		for(j=125; j<240; j++){
			tab[i][j] = 0;
		}
		for(j=240; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<270; j++){
			tab[i][j] = 0;
		}
		for(j=270; j<275; j++){
			tab[i][j] = 1;
		}
		for(j=275; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 5
	for(i=120; i<125; i++){
		for(j=5; j<35; j++){
			tab[i][j] = 1;
		}
		for(j=35; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<125; j++){
			tab[i][j] = 1;
		}
		for(j=125; j<150; j++){
			tab[i][j] = 0;
		}
		for(j=150; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<270; j++){
			tab[i][j] = 0;
		}
		for(j=270; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 5
	for(i=125; i<150; i++){
		for(j=5; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<330; j++){
			tab[i][j] = 0;
		}
	}
	//mur 6
	for(i=150; i<155; i++){
		for(j=5; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<305; j++){
			tab[i][j] = 1;
		}
		for(j=305; j<335; j++){
			tab[i][j] = 0;
		}
	}
	//chemin 6
	for(i=155; i<180; i++){
		for(j=5; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<215; j++){
			tab[i][j] = 1;
		}
		for(j=215; j<330; j++){
			tab[i][j] = 0;
		}
		
	}
	//mur 7
	for(i=180; i<185; i++){
		for(j=5; j<185; j++){
			tab[i][j] = 1;
		}
		for(j=185; j<210; j++){
			tab[i][j] = 0;
		}
		for(j=210; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 7
	for(i=185; i<210; i++){
		for(j=5; j<60; j++){
			tab[i][j] = 0;
		}
		for(j=60; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<240; j++){
			tab[i][j] = 0;
		}
		for(j=240; j<245; j++){
			tab[i][j] = 1;
		}
		for(j=245; j<305; j++){
			tab[i][j] = 0;
		}
	}
	//mur 7
	for(i=210; i<215; i++){
		for(j=5; j<65; j++){
			tab[i][j] = 1;
		}
		for(j=65; j<90; j++){
			tab[i][j] = 0;
		}
		for(j=90; j<95; j++){
			tab[i][j] = 1;
		}
		for(j=95; j<120; j++){
			tab[i][j] = 0;
		}
		for(j=120; j<155; j++){
			tab[i][j] = 1;
		}
		for(j=155; j<180; j++){
			tab[i][j] = 0;
		}
		for(j=180; j<330; j++){
			tab[i][j] = 1;
		}
	}
	//chemin 8
	for(i=215; i<240; i++){
		for(j=5; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 9
	for(i=240; i<245; i++){
		for(j=5; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<305; j++){
			tab[i][j]=1;
		}
		for(j=305; j<330; j++){
			tab[i][j]=0;
		}
	}
	//chemin 9
	for(i=245; i<270; i++){
		for(j=5; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<245; j++){
			tab[i][j]=1;
		}
		for(j=245; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 10
	for(i=270; i<275; i++){
		for(j=5; j<35; j++){
			tab[i][j]=0;
		}
		for(j=35; j<330; j++){
			tab[i][j]=1;
		}
	}
	//chemin 10
	for(i=275; i<300; i++){
		for(j=5; j<60; j++){
			tab[i][j]=0;
		}
		for(j=60; j<65; j++){
			tab[i][j]=1;
		}
		for(j=65; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<180; j++){
			tab[i][j]=0;
		}
		for(j=180; j<185; j++){
			tab[i][j]=1;
		}
		for(j=185; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<245; j++){
			tab[i][j]=1;
		}
		for(j=245; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 11
	for(i=300; i<305; i++){
		for(j=5; j<35; j++){
			tab[i][j]=1;
		}
		for(j=35; j<60; j++){
			tab[i][j]=0;
		}
		for(j=60; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<150; j++){
			tab[i][j]=0;
		}
		for(j=150; j<155; j++){
			tab[i][j]=1;
		}
		for(j=155; j<180; j++){
			tab[i][j]=0;
		}
		for(j=180; j<185; j++){
			tab[i][j]=1;
		}
		for(j=185; j<210; j++){
			tab[i][j]=0;
		}
		for(j=210; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<240; j++){
			tab[i][j]=0;
		}
		for(j=240; j<330; j++){
			tab[i][j]=1;
		}
	}
	//chemin 11
	for(i=305; i<330; i++){
		for(j=5; j<150; j++){
			tab[i][j]=0;
		}
		for(j=150; j<155; j++){
			tab[i][j]=1;
		}
		for(j=155; j<210; j++){
			tab[i][j]=0;
		}
		for(j=210; j<215; j++){
			tab[i][j]=1;
		}
		for(j=215; j<330; j++){
			tab[i][j]=0;
		}
	}
	//mur 12
	for(i=330; i<335; i++){
		for(j=5; j<95; j++){
			tab[i][j]=1;
		}
		for(j=95; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<305; j++){
			tab[i][j]=1;
		}
		for(j=305; j<330; j++){
			tab[i][j]=0;
		}
	}
	//chemin 12
	for(i=335; i<360; i++){
		for(j=5; j<120; j++){
			tab[i][j]=0;
		}
		for(j=120; j<125; j++){
			tab[i][j]=1;
		}
		for(j=125; j<330; j++){
			tab[i][j]=0;
		}
	}
	return tab;
}








