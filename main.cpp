#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void action(char x);
char uperRowClockwise();
char lowerrowclockwise();
char middlerowclockwise();
char rightcolumnfronttoback();
char middlecolumnfronttoback();
char leftcolumnfronttoback();


 char frontface[3][3]={{'w','w','w'},{'w','w','w'},{'w','w','w'}};
    char backface[3][3]={{'r','r','r'},{'r','r','r'},{'r','r','r'}};
    char topface[3][3]={{'o','o','o'},{'o','o','o'},{'o','o','o'}};
    char bottomface[3][3]={{'b','b','b'},{'b','b','b'},{'b','b','b'}};
    char rightface[3][3]={{'g','g','g'},{'g','g','g'},{'g','g','g'}};
    char leftface[3][3]={{'y','y','y'},{'y','y','y'},{'y','y','y'}};
    char temp[3][3];

int main()
{
    int i,j,actionpo;


    cout << "welcome to the rubiks cube solver\nThe faces of the cube have respective colors" << endl;


          cout<<"     ___"<<endl;
          cout<<"    |   |"<<endl;
          cout<<"    | R |"<<endl;
          cout<<" ___|___|___"<<endl;
    cout<<       "|   |   |   |"<<endl;
    cout<<       "| Y | B | G |"<<endl;
    cout<<       "|___|___|___|"<<endl;
           cout<<"    |   |"<<endl;
           cout<<"    | W |"<<endl;
           cout<<"    |___|"<<endl;
           cout<<"    |   |"<<endl;
           cout<<"    | O |"<<endl;
           cout<<"    |___|"<<endl;

    cout<<"enter your desired function"<<endl;
    cout<<"rotate upper row clockwise:  1\nrotate lower row clockwise:  2\nrotate middle row clockwise: 3\n"<<endl;
    cout<<"rotate right column front to back:  4\nrotate left column front to back:   5\nrotate middle column front to back: 6\n"<<endl;
    cout<<"press 0 to exit the game"<<endl;

do{

    cin>>actionpo; //action to be performed

    switch(actionpo){
     case (1): {
            uperRowClockwise();
        break;
     }
    case (2):{
       lowerrowclockwise();
    break;

    }
    case 3:{
        middlerowclockwise();
    break;
       }
        case 4:{
            rightcolumnfronttoback();
    break;
        }
        case 5:{
        leftcolumnfronttoback();
    break;
        }
            case 6:{
         middlecolumnfronttoback();
    break;
        }

    }






//FOR PRINTING
 for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
       cout<<frontface[i][j]<<"\t";
    }
      cout<<endl<<endl;
   }
}while(actionpo!=0);

return 0;
}

char uperRowClockwise(){
   for(int i=0;i<1;i++){
            for(int j=0;j<3;j++){
          temp[i][j]=frontface[i][j];
          frontface[i][j]=leftface[i][j];
          leftface[i][j]=backface[i][j];
          backface[i][j]=rightface[i][j];
          rightface[i][j]=temp[i][j];
      }

    }
}

char lowerrowclockwise(){
    for(int i=2;i<3;i++){
    for(int j=0;j<3;j++){
        temp[i][j]=frontface[i][j];
        frontface[i][j]=leftface[i][j];
        leftface[i][j]=backface[i][j];
        backface[i][j]=rightface[i][j];
        rightface[i][j]=temp[i][j];
    }
   }
}


char middlerowclockwise(){
    for(int i=1;i<3;i++){
        for(int j=0;j<3;j++){
        temp[i][j]=frontface[i][j];
        frontface[i][j]=leftface[i][j];
        leftface[i][j]=backface[i][j];
        backface[i][j]=rightface[i][j];
        rightface[i][j]=temp[i][j];
    }
   }
}

char rightcolumnfronttoback(){
        for(int i=0;i<3;i++){
        for(int j=2;j<3;j++){
        temp[i][j]=frontface[i][j];
        frontface[i][j]=bottomface[i][j];
        bottomface[i][j]=backface[i][j];
        backface[i][j]=topface[i][j];
        topface[i][j]=temp[i][j];
    }
   }
}


char leftcolumnfronttoback(){
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
        temp[i][j]=frontface[i][j];
        frontface[i][j]=bottomface[i][j];
        bottomface[i][j]=backface[i][j];
        backface[i][j]=topface[i][j];
        topface[i][j]=temp[i][j];
    }
   }
}

char middlecolumnfronttoback(){
    for(int i=0;i<3;i++){
        for(int j=1;j<2;j++){
        temp[i][j]=frontface[i][j];
        frontface[i][j]=bottomface[i][j];
        bottomface[i][j]=backface[i][j];
        backface[i][j]=topface[i][j];
        topface[i][j]=temp[i][j];
    }
   }
}
/*
             the cube has six faces, names from 0 to 5
                0 F = front face
                1 R = right face
                2 U = up face
                3 L = left face
                4 D = down face
                5 B = back face
                             ___
                            /2 /|
                           /__/ | 5
                          |   |1|
                        3 | 0 | /
                          |___|/
                            4
              if we open them into 2 dimensions:

                       ___
                      |   |
                      | 2 |
                   ___|___|___
                  |   |   |   |
                  | 3 | 0 | 1 |
                  |___|___|___|
                      |   |
                      | 4 |
                      |___|
                      |   |
                      | 5 |
                      |___|

            // changing the front side and right side, we will get these results:

                     ___              ___             ___
                    |   |            |   |           |   |
                    | 0 |            | 0 |           | 0 |
                 ___|___|___      ___|___|___     ___|___|___
                |   |   |   |    |   |   |   |   |   |   |   |
                | 4 | 1 | 2 |    | 1 | 2 | 3 |   | 2 | 3 | 4 |
                |___|___|___|    |___|___|___|   |___|___|___|
                    |   |            |   |           |   |
                    | 5 |            | 5 |           | 5 |
                    |___|            |___|           |___|
                    |   |            |   |           |   |
                    | 3 |            | 4 |           | 1 |
                    |___|            |___|           |___|

                     ___                  ___
                    |   |                |   |
                    | 0 |                | 4 |
                 ___|___|___          ___|___|___
                |   |   |   |        |   |   |   |
                | 3 | 4 | 1 |        | 3 | 5 | 1 |
                |___|___|___|        |___|___|___|
                    |   |                |   |
                    | 5 |                | 2 |
                    |___|                |___|
                    |   |                |   |
                    | 2 |                | 0 |
                    |___|                |___|



           */
