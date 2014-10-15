#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio-bis.h>

int ptTotal=0;


void regle()
{
     printf("\n\nRegles\nLe jeu du pacman est un des ancetres du jeu vidéo.\nVous dirigez un personnage grace au touche (z = haut, s = bas, q = gauche et d = droite)"); 
     printf("\nLe but étant de manger toutes les étoiles sans se faire attraper par un des 3 méchants\nAppuyer sur 'o' pour quitter la partie et voir votre score final");
     printf("\nBon jeu !\n\n");
}
int setPoint(int pt)
{
     ptTotal = ptTotal+pt;
}
void getPoint(int point)
{
     printf("Score : %d",point);
}
void jeu()
{
    int x=8,y=9,ok=0,mvMonstre=0,x1=10,y1=8,x2=10,y2=9,x3=10,y3=10,totalEtoile=189,numMvp=0,okDepartMonstre=0,randoM1=0,randoM2=0,randoM3=0;
    char perso = 1,mech1=2,mech2=2,mech3=2,mvt;
    srand(time(NULL));
    //clock_t debut; //initialize Begin
    char tab[22][19]={{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                      {'#','*','*','*','*','*','*','*','*','#','*','*','*','*','*','*','*','*','#'},
                      {'#','*','#','#','*','#','#','#','*','#','*','#','#','#','*','#','#','*','#'},
                      {'#','*','#','#','*','#','#','#','*','#','*','#','#','#','*','#','#','*','#'},
                      {'#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#'},
                      {'#','*','#','#','*','#','*','#','#','#','#','#','*','#','*','#','#','*','#'},
                      {'#','*','*','*','*','#','*','*','*','#','*','*','*','#','*','*','*','*','#'},
                      {'#','#','#','#','*','#','#','#','*','#','*','#','#','#','*','#','#','#','#'},
                      {' ',' ',' ','#','*','#','*','*','*',' ','*','*','*','#','*','#',' ',' ',' '},
                      {'#','#','#','#','*','#','*','#','#','-','#','#','*','#','*','#','#','#','#'},
                      {'*','*','*','*','*','*','*','#',' ',' ',' ','#','*','*','*','*','*','*','*'},
                      {'#','#','#','#','*','#','*','#','#','#','#','#','*','#','*','#','#','#','#'},
                      {' ',' ',' ','#','*','#','*','*','*','*','*','*','*','#','*','#',' ',' ',' '},
                      {'#','#','#','#','*','#','*','#','#','#','#','#','*','#','*','#','#','#','#'},
                      {'#','*','*','*','*','*','*','*','*','#','*','*','*','*','*','*','*','*','#'},
                      {'#','*','#','#','*','#','#','#','*','#','*','#','#','#','*','#','#','*','#'},
                      {'#','*','*','#','*','*','*','*','*','*','*','*','*','*','*','#','*','*','#'},
                      {'#','#','*','#','*','#','*','#','#','#','#','#','*','#','*','#','*','#','#'},
                      {'#','*','*','*','*','#','*','*','*','#','*','*','*','#','*','*','*','*','#'},
                      {'#','*','#','#','#','#','#','#','*','#','*','#','#','#','#','#','#','*','#'},
                      {'#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#'},
                      {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
                     
                      
                      tab[x][y]=perso; 
                      tab[x1][y1]=mech1; 
                      tab[x2][y2]=mech2;
                      tab[x3][y3]=mech3;
                      
                      /*debut = clock() * CLK_TCK; //start the timer
                      if(debut>=0.0000005)
                      {
                                     printf("\nTimer  5000");
                      }*/
                     
                     do
                      {
                      randoM1=(rand() % 4);     
                         randoM2=(rand() % 4);
                         randoM3=(rand() % 4);                  
                     textbackground(3); clrscr();             
                      for(int i=0;i<22;i++)
                      {
                                            
                                            for(int j=0;j<19;j++)
                                            {
                                            if(i==x&&j==y){textcolor(YELLOW);}
                                            else if(i==x1 &&j==y1){textcolor(RED);}
                                            else if(i==x2 &&j==y2){textcolor(BLUE);}
                                            else if(i==x3 &&j==y3){textcolor(5);}
                                            else{textcolor(7);}        
                                            printf("%c",tab[i][j]);

                                            }
                                            printf("\n");
                      }                  
                      printf("\n         ");
                      getPoint(ptTotal);
                      printf("\n rand : %d",randoM2);
                      printf("\n rand : %d",randoM3);
                      
                      mvt=getch();
                      if(mvt=='z'&&(tab[x-1][y]==' ' || tab[x-1][y]=='*'))
                      {
                                            if(tab[x-1][y]=='*')
                                            {
                                                    setPoint(100);   
                                                    totalEtoile--;
                                                             
                                            }       
                                            tab[x-1][y]=perso;
                                            tab[x][y]=' ';
                                            x=x-1;
                                            numMvp++;
                                            
                      }
                      if(mvt=='s'&&(tab[x+1][y]==' ' || tab[x+1][y]=='*'))
                      {
                                            if(tab[x+1][y]=='*')
                                            {
                                                    setPoint(100); 
                                                    totalEtoile--;            
                                            }       
                                            tab[x+1][y]=perso;
                                            tab[x][y]=' ';
                                            x=x+1;
                                            numMvp++;
                      }
                      if(mvt=='d'&&(tab[x][y+1]==' ' ||tab[x][y+1]=='*' ))
                      {
                                            if(tab[x][y+1]=='*')
                                            {
                                                    setPoint(100);  
                                                    totalEtoile--;           
                                            }          
                                            tab[x][y+1]=perso;
                                            tab[x][y]=' ';
                                            y=y+1;
                                            if(x==10 && y==18)
                                            {
                                            tab[x][0]=perso;
                                            tab[x][y]=' ';
                                            y=0;                                        
                                            }
                                            numMvp++;
                      }
                      if(mvt=='q'&&(tab[x][y-1]==' '||tab[x][y-1]=='*'))
                      {
                                            if(tab[x][y-1]=='*')
                                            {
                                                    setPoint(100);  
                                                    totalEtoile--;           
                                            }        
                                            tab[x][y-1]=perso;
                                            tab[x][y]=' ';
                                            y=y-1;
                                            if(x==10 && y==0)
                                            {
                                            tab[x][18]=perso;
                                            tab[x][y]=' ';
                                            y=18;                                        
                                            }
                                            numMvp++;
                      }
                      if(mvt=='o' || totalEtoile==0)
                      {
                                            
                                            ok=1;
                      }
                      if(numMvp==5)
                      {
                                    tab[9][9]=' ';
                                    okDepartMonstre=1;
                      }
                      if(okDepartMonstre==1)
                      {
                         //ici            
                         if(randoM1==1)
                       {
                        if(tab[x1+1][y1]=='*' || tab[x1+1][y1]==' ')
                        {
                                             if(tab[x1+1][y1]==' ')  
                                            {
                                             tab[x1+1][y1]=mech1;
                                             tab[x1][y1]=' ';
                                             x1=x1+1;
                                             }
                                            if(tab[x1+1][y1]=='*')
                                            {
                                            tab[x1+1][y1]=mech1;
                                             tab[x1][y1]='*';
                                             x1=x1+1;                 
                                            }
                                            
                                        
                         }
                        }
                       if(randoM1==2)
                       {
                        if(tab[x1-1][y1]=='*' || tab[x1-1][y1]==' ')
                        {
                                            if(tab[x1-1][y1]==' ')  
                                            {
                                             tab[x1-1][y1]=mech1;
                                             tab[x1][y1]=' ';
                                             x1=x1-1;
                                             }
                                            if(tab[x1-1][y1]=='*')
                                            {
                                            tab[x1-1][y1]=mech1;
                                             tab[x1][y1]='*';
                                             x1=x1-1;                 
                                            }
                         }
                        }
                       if(randoM1==3)
                       {
                        if(tab[x1][y1+1]=='*' || tab[x1][y1+1]==' ')
                        {
                                              if(tab[x1][y1+1]==' ')
                                              {
                                                tab[x1][y1+1]=mech1;
                                                 tab[x1][y1]=' ';
                                                  y1=y1+1;   
                                                  if(x1==10 && y1==18)
                                                  {
                                                  tab[x1][0]=mech1;
                                                  tab[x1][y1]=' ';
                                                  y1=0;                                        
                                                  }               
                                              }
                                              if(tab[x1][y1+1]=='*')
                                              {
                                                 tab[x1][y1+1]=mech1;
                                                 tab[x1][y1]='*';
                                                 y1=y1+1; 
                                                 if(x1==10 && y1==18)
                                                  {
                                                  tab[x1][0]=mech1;
                                                  tab[x1][y1]='*';
                                                  y1=0;  
                                                  } 
                                                                
                                              }
                                        
                         }
                        }
                       if(randoM1==0)
                       {
                        if(tab[x1][y1-1]=='*' || tab[x1][y1-1]==' ')
                        {
                                              if(tab[x1][y1-1]==' ')
                                              {
                                                tab[x1][y1-1]=mech1;
                                                 tab[x1][y1]=' ';
                                                  y1=y1-1;   
                                                  if(x1==10 && y1==0)
                                                  {
                                                  tab[x1][18]=mech1;
                                                  tab[x1][y1]=' ';
                                                  y1=18;                                        
                                                  }               
                                              }
                                              if(tab[x1][y1-1]=='*')
                                              {
                                                 tab[x1][y1-1]=mech1;
                                                 tab[x1][y1]='*';
                                                 y1=y1-1;   
                                                 if(x1==10 && y1==0)
                                                  {
                                                  tab[x1][18]=mech1;
                                                  tab[x1][y1]='*';
                                                  y1=18;                                        
                                                  }                     
                                              }
                                        
                         }
                        }
                        //ici
                       if(randoM2==1)
                       {
                        if(tab[x2+1][y2]=='*' || tab[x2+1][y2]==' ')
                        {
                                             if(tab[x2+1][y2]==' ')  
                                            {
                                             tab[x2+1][y2]=mech2;
                                             tab[x2][y2]=' ';
                                             x2=x2+1;
                                             }
                                            if(tab[x2+1][y2]=='*')
                                            {
                                            tab[x2+1][y2]=mech2;
                                             tab[x2][y2]='*';
                                             x2=x2+1;                 
                                            }
                                            
                                        
                         }
                        }
                       if(randoM2==2)
                       {
                        if(tab[x2-1][y2]=='*' || tab[x2-1][y2]==' ')
                        {
                                            if(tab[x2-1][y2]==' ')  
                                            {
                                             tab[x2-1][y2]=mech2;
                                             tab[x2][y2]=' ';
                                             x2=x2-1;
                                             }
                                            if(tab[x2-1][y2]=='*')
                                            {
                                            tab[x2-1][y2]=mech2;
                                             tab[x2][y2]='*';
                                             x2=x2-1;                 
                                            }
                         }
                        }
                       if(randoM2==3)
                       {
                        if(tab[x2][y2+1]=='*' || tab[x2][y2+1]==' ')
                        {
                                              if(tab[x2][y2+1]==' ')
                                              {
                                                tab[x2][y2+1]=mech2;
                                                 tab[x2][y2]=' ';
                                                  y2=y2+1;   
                                                  if(x2==10 && y2==18)
                                                  {
                                                  tab[x2][0]=mech2;
                                                  tab[x2][y2]=' ';
                                                  y2=0;                                        
                                                  }               
                                              }
                                              if(tab[x2][y2+1]=='*')
                                              {
                                                 tab[x2][y2+1]=mech2;
                                                 tab[x2][y2]='*';
                                                 y2=y2+1; 
                                                 if(x2==10 && y2==18)
                                                  {
                                                  tab[x2][0]=mech2;
                                                  tab[x2][y2]='*';
                                                  y2=0;  
                                                  } 
                                                                
                                              }
                                        
                         }
                        }
                       if(randoM2==0)
                       {
                        if(tab[x2][y2-1]=='*' || tab[x2][y2-1]==' ')
                        {
                                              if(tab[x2][y2-1]==' ')
                                              {
                                                tab[x2][y2-1]=mech2;
                                                 tab[x2][y2]=' ';
                                                  y2=y2-1;   
                                                  if(x2==10 && y2==0)
                                                  {
                                                  tab[x2][18]=mech2;
                                                  tab[x2][y2]=' ';
                                                  y2=18;                                        
                                                  }               
                                              }
                                              if(tab[x2][y2-1]=='*')
                                              {
                                                 tab[x2][y2-1]=mech2;
                                                 tab[x2][y2]='*';
                                                 y2=y2-1;   
                                                 if(x2==10 && y2==0)
                                                  {
                                                  tab[x2][18]=mech2;
                                                  tab[x2][y2]='*';
                                                  y2=18;                                        
                                                  }                     
                                              }
                                        
                         }
                        }
                        //ici
                       if(randoM3==1)
                       {
                        if(tab[x3+1][y3]=='*' || tab[x3+1][y3]==' ')
                        {
                                             if(tab[x3+1][y3]==' ')  
                                            {
                                             tab[x3+1][y3]=mech3;
                                             tab[x3][y3]=' ';
                                             x3=x3+1;
                                             }
                                            if(tab[x3+1][y3]=='*')
                                            {
                                            tab[x3+1][y3]=mech3;
                                             tab[x3][y3]='*';
                                             x3=x3+1;                 
                                            }
                                            
                                        
                         }
                        }
                       if(randoM3==2)
                       {
                        if(tab[x3-1][y3]=='*' || tab[x3-1][y3]==' ')
                        {
                                            if(tab[x3-1][y3]==' ')  
                                            {
                                             tab[x3-1][y3]=mech3;
                                             tab[x3][y3]=' ';
                                             x3=x3-1;
                                             }
                                            if(tab[x3-1][y3]=='*')
                                            {
                                            tab[x3-1][y3]=mech3;
                                             tab[x3][y3]='*';
                                             x3=x3-1;                 
                                            }
                         }
                        }
                       if(randoM3==3)
                       {
                        if(tab[x3][y3+1]=='*' || tab[x3][y3+1]==' ')
                        {
                                              if(tab[x3][y3+1]==' ')
                                              {
                                                tab[x3][y3+1]=mech3;
                                                 tab[x3][y3]=' ';
                                                  y3=y3+1;   
                                                  if(x3==10 && y3==18)
                                                  {
                                                  tab[x3][0]=mech3;
                                                  tab[x3][y3]=' ';
                                                  y3=0;                                        
                                                  }               
                                              }
                                              if(tab[x3][y3+1]=='*')
                                              {
                                                 tab[x3][y3+1]=mech3;
                                                 tab[x3][y3]='*';
                                                 y3=y3+1; 
                                                 if(x3==10 && y3==18)
                                                  {
                                                  tab[x3][0]=mech3;
                                                  tab[x3][y3]='*';
                                                  y3=0;  
                                                  } 
                                                                
                                              }
                                        
                         }
                        }
                       if(randoM3==0)
                       {
                        if(tab[x3][y3-1]=='*' || tab[x3][y3-1]==' ')
                        {
                                              if(tab[x3][y3-1]==' ')
                                              {
                                                tab[x3][y3-1]=mech3;
                                                 tab[x3][y3]=' ';
                                                  y3=y3-1;   
                                                  if(x3==10 && y3==0)
                                                  {
                                                  tab[x3][18]=mech3;
                                                  tab[x3][y3]=' ';
                                                  y3=18;                                        
                                                  }               
                                              }
                                              if(tab[x3][y3-1]=='*')
                                              {
                                                 tab[x3][y3-1]=mech3;
                                                 tab[x3][y3]='*';
                                                 y3=y3-1;   
                                                 if(x3==10 && y3==0)
                                                  {
                                                  tab[x3][18]=mech3;
                                                  tab[x3][y3]='*';
                                                  y3=18;                                        
                                                  }                     
                                              }
                                        
                         }
                        }
                               
                         //ici                             
                                            
                      }
                      system("cls");
                      
                      
                      }while(ok==0);
                      getPoint(ptTotal);
                      printf("\nFin\n\n");
                        
}
void Lanceur()
{
     int ok=0;
     char choix;
     textcolor(BLUE);
     textbackground(3); clrscr(); 
     gotoxy(10,10);
    clrscr();
     do
     {
                   
         printf("         Bonjour\n   Bienvenue au jeu du pacman");
         printf("\nVeuillez faire un choix :");
         printf("\n(1).Jeu\n(2).Regles\n(3).Quitter\nChoix : ");
         choix = getch();
         if(choix!='1' && choix!='2' && choix !='3')
         {
                     printf("\nErreur entree, veuillez choisir parmis les propositions 1, 2 ou 3\n");
         }
         switch(choix)
         {
                    case '1' : jeu();
                               ptTotal=0;
                             break;
                    case '2' : regle();
                             break;
                    case '3' : printf("\nAu revoir");
                             ok=1;
                                   
         }
     }while(ok==0);     
     
     
     
     
}
int main()
{
    
    
    Lanceur();
    Sleep(500);
    exit(EXIT_SUCCESS);
    fflush(stdin);
    getchar();
    return 0;

}
