#include<bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int height=30,width=30,gameover=0;

int x,y,fruitx,fruity,score = 0;	// x and y represents the head of the snake
int flag;

int count=0;						// length of the snake
int tailx[1000],taily[1000];		// helps to draw the snake

void setup()
{
    gameover=0;
    x=height/2;						// x and y are snake's head -  co-ordinates
    y=width/2;

    label1:
        fruitx=rand()%20;			// randomly fruit generation -  co-ordinates

    label2:
        fruity=rand()%20;

    if(fruitx == 0)					// if random number generated is invalid, it goes back and generates again
        goto label1;

    if(fruity == 0)
        goto label2;
}

void input()
{
    if(kbhit())						// when user press any key
    {
        switch(getch())				// getch() gets the key which user have pressed
        {							// flag is for direction
            case 'y':
                {
                    flag=1;
                    break;
                }
            case 'b':
                {
                    flag=2;
                    break;
                }
            case 'g':
                {
                    flag=3;
                    break;
                }
            case 'h':
                {
                    flag=4;
                    break;
                }
            case 'z':				// if user wants to stop the game
                {
                    gameover=1;
                    break;
                }
        }
    }
}

void makemove()										// when user press any key, this function will help to make move accordingly
{
    int newx = tailx[0], newy = taily[0];
    int prevx,prevy;
    tailx[0] = x;
    taily[0] = y;

    for(int i = 1 ; i < count ; i++)				// moves all the bites
    {
        prevx = tailx[i];
        prevy = taily[i];

        tailx[i] = newx;
        taily[i] = newy;

        newx = prevx;
        newy = prevy;
    }

    switch(flag)			// direction
    {
        case 1:
            {
                x--;
                break;
            }
        case 2:
            {
                x++;
                break;
            }
        case 3:
            {
                y--;
                break;
            }
        case 4:
            {
                y++;
                break;
            }
        default:
            break;
    }
    
    if(x < 0 || x > width || y < 0 || y > height)
        gameover=1;

    for(int r = 0 ; r < count ; r++)
    {
        if(x == tailx[r] && y == taily[r])			// if snake touches itself -> game gets over
            gameover = 1;
    }

    if(x == fruitx && y == fruity)					// if snake gets the food, new food will be generated
    {
    label3:
        fruitx=rand()%20;

    label4:
        fruity=rand()%20;

    if(fruitx == 0)
        goto label3;

    if(fruity == 0)
        goto label4;

        score +=10;
    count++;
    }
}
void draw()
{

    system("cls");
    printf("\n\n\n\n\n* * * SNAKE GAME IN C * * *\n\n\n\n\n");
    int i,j;
     for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1)					// This will draw the boundary
                printf("*");

            else
                {
                    if( i == x && j == y)												// Snake Position
                        printf("@");
                    else if(i == fruitx && j == fruity)									// Food Position
                            printf("F");
                    else
                    {
                        int temp = 0;
                        for(int k = 0 ; k < count ; k++)								// Entire Snake has to be printed
                        {
                            if( i == tailx[k] && j == taily[k])							// if that matches, draws snake
                            {
                                printf("o");
                                temp = 1;
                            }
                        }
                        if(temp == 0)													// if it dosen't match, space has to be drawn		
                                printf(" ");
                    }
                }
        }
        printf("\n");
    }

    printf("\n\n\nscore = %d ",score);
}
int main()
{
    setup();

    while(!gameover)
    {
        draw();						// draws the entire layout
        input();					// takes the acrtion from the user
        makemove();					// according to user's action, makes the move
    }
    return 0;
}
