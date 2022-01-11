#include <stdio.h>
#include <stdlib.h>

#include "RubiksCube.hh"

void changeFace(int* magicCube, int face1, int face2){
  int tempFace = -1;

  tempFace = magicCube[face1];
  magicCube[face1] = magicCube[face2];
  magicCube[face2] = tempFace;
}


void R(int* magicCube){

  changeFace(magicCube,27,29);
  changeFace(magicCube,27,35);
  changeFace(magicCube,27,33);

  changeFace(magicCube,28,32);
  changeFace(magicCube,28,34);
  changeFace(magicCube,28,30);

  changeFace(magicCube,8,45);
  changeFace(magicCube,8,26);
  changeFace(magicCube,8,44);

  changeFace(magicCube,5,48);
  changeFace(magicCube,5,23);
  changeFace(magicCube,5,41);

  changeFace(magicCube,2,51);
  changeFace(magicCube,2,20);
  changeFace(magicCube,2,38);

}

void Rh(int* magicCube){
  
  changeFace(magicCube,27,33);
  changeFace(magicCube,27,35);
  changeFace(magicCube,27,29);

  changeFace(magicCube,28,30);
  changeFace(magicCube,28,34);
  changeFace(magicCube,28,32);

  changeFace(magicCube,8,44);
  changeFace(magicCube,8,26);
  changeFace(magicCube,8,45);

  changeFace(magicCube,5,41);
  changeFace(magicCube,5,23);
  changeFace(magicCube,5,48);

  changeFace(magicCube,2,38);
  changeFace(magicCube,2,20);
  changeFace(magicCube,2,51);
}

void R2(int* magicCube){
  R(magicCube);
  R(magicCube);
}

void L(int* magicCube){

  changeFace(magicCube,10,14);
  changeFace(magicCube,10,16);
  changeFace(magicCube,10,12);

  changeFace(magicCube,9,11);
  changeFace(magicCube,9,17);
  changeFace(magicCube,9,15);

  changeFace(magicCube,6,42);
  changeFace(magicCube,6,24);
  changeFace(magicCube,6,47);

  changeFace(magicCube,3,39);
  changeFace(magicCube,3,21);
  changeFace(magicCube,3,50);

  changeFace(magicCube,0,36);
  changeFace(magicCube,0,18);
  changeFace(magicCube,0,53);

}

void Lh(int* magicCube){

  changeFace(magicCube,10,12);
  changeFace(magicCube,10,16);
  changeFace(magicCube,10,14);

  changeFace(magicCube,9,15);
  changeFace(magicCube,9,17);
  changeFace(magicCube,9,11);

  changeFace(magicCube,6,47);
  changeFace(magicCube,6,24);
  changeFace(magicCube,6,42);

  changeFace(magicCube,3,50);
  changeFace(magicCube,3,21);
  changeFace(magicCube,3,39);

  changeFace(magicCube,0,53);
  changeFace(magicCube,0,18);
  changeFace(magicCube,0,36);

}

void L2(int* magicCube){
  L(magicCube);
  L(magicCube);
}

void U(int* magicCube){

  changeFace(magicCube,0,2);
  changeFace(magicCube,0,8);
  changeFace(magicCube,0,6);

  changeFace(magicCube,1,5);
  changeFace(magicCube,1,7);
  changeFace(magicCube,1,3);

  changeFace(magicCube,9,45);
  changeFace(magicCube,9,27);
  changeFace(magicCube,9,36);

  changeFace(magicCube,10,46);
  changeFace(magicCube,10,28);
  changeFace(magicCube,10,37);

  changeFace(magicCube,11,47);
  changeFace(magicCube,11,29);
  changeFace(magicCube,11,38);

}

void Uh(int* magicCube){

  changeFace(magicCube,0,6);
  changeFace(magicCube,0,8);
  changeFace(magicCube,0,2);

  changeFace(magicCube,1,3);
  changeFace(magicCube,1,7);
  changeFace(magicCube,1,5);

  changeFace(magicCube,9,36);
  changeFace(magicCube,9,27);
  changeFace(magicCube,9,45);

  changeFace(magicCube,10,37);
  changeFace(magicCube,10,28);
  changeFace(magicCube,10,46);

  changeFace(magicCube,11,38);
  changeFace(magicCube,11,29);
  changeFace(magicCube,11,47);

}

void U2(int* magicCube){
  U(magicCube);
  U(magicCube);
}

void D(int* magicCube){

  changeFace(magicCube,18,20);
  changeFace(magicCube,18,26);
  changeFace(magicCube,18,24);

  changeFace(magicCube,19,23);
  changeFace(magicCube,19,25);
  changeFace(magicCube,19,21);

  changeFace(magicCube,42,33);
  changeFace(magicCube,42,51);
  changeFace(magicCube,42,15);

  changeFace(magicCube,43,34);
  changeFace(magicCube,43,52);
  changeFace(magicCube,43,16);

  changeFace(magicCube,44,35);
  changeFace(magicCube,44,53);
  changeFace(magicCube,44,17);

}

void Dh(int* magicCube){

  changeFace(magicCube,18,24);
  changeFace(magicCube,18,26);
  changeFace(magicCube,18,20);

  changeFace(magicCube,19,21);
  changeFace(magicCube,19,25);
  changeFace(magicCube,19,23);

  changeFace(magicCube,42,15);
  changeFace(magicCube,42,51);
  changeFace(magicCube,42,33);

  changeFace(magicCube,43,16);
  changeFace(magicCube,43,52);
  changeFace(magicCube,43,34);

  changeFace(magicCube,44,17);
  changeFace(magicCube,44,53);
  changeFace(magicCube,44,35);

}

void D2(int* magicCube){
  D(magicCube);
  D(magicCube);
}

void F(int* magicCube){

  changeFace(magicCube,36,38);
  changeFace(magicCube,36,44);
  changeFace(magicCube,36,42);

  changeFace(magicCube,37,41);
  changeFace(magicCube,37,43);
  changeFace(magicCube,37,39);

  changeFace(magicCube,6,27);
  changeFace(magicCube,6,20);
  changeFace(magicCube,6,17);

  changeFace(magicCube,7,30);
  changeFace(magicCube,7,19);
  changeFace(magicCube,7,14);

  changeFace(magicCube,8,33);
  changeFace(magicCube,8,18);
  changeFace(magicCube,8,11);

}

void Fh(int* magicCube){

  changeFace(magicCube,36,42);
  changeFace(magicCube,36,44);
  changeFace(magicCube,36,38);

  changeFace(magicCube,37,39);
  changeFace(magicCube,37,43);
  changeFace(magicCube,37,41);

  changeFace(magicCube,6,17);
  changeFace(magicCube,6,20);
  changeFace(magicCube,6,27);

  changeFace(magicCube,7,14);
  changeFace(magicCube,7,19);
  changeFace(magicCube,7,30);

  changeFace(magicCube,8,11);
  changeFace(magicCube,8,18);
  changeFace(magicCube,8,33);

}

void F2(int* magicCube){
  F(magicCube);
  F(magicCube);
}

void B(int* magicCube){

  changeFace(magicCube,45,47);
  changeFace(magicCube,45,53);
  changeFace(magicCube,45,51);

  changeFace(magicCube,46,50);
  changeFace(magicCube,46,52);
  changeFace(magicCube,46,48);

  changeFace(magicCube,0,15);
  changeFace(magicCube,0,26);
  changeFace(magicCube,0,29);

  changeFace(magicCube,1,12);
  changeFace(magicCube,1,25);
  changeFace(magicCube,1,32);

  changeFace(magicCube,2,9);
  changeFace(magicCube,2,24);
  changeFace(magicCube,2,35);

}

void Bh(int* magicCube){

  changeFace(magicCube,45,51);
  changeFace(magicCube,45,53);
  changeFace(magicCube,45,47);

  changeFace(magicCube,46,48);
  changeFace(magicCube,46,52);
  changeFace(magicCube,46,50);

  changeFace(magicCube,0,29);
  changeFace(magicCube,0,26);
  changeFace(magicCube,0,15);

  changeFace(magicCube,1,32);
  changeFace(magicCube,1,25);
  changeFace(magicCube,1,12);

  changeFace(magicCube,2,35);
  changeFace(magicCube,2,24);
  changeFace(magicCube,2,9);

}

void B2(int* magicCube){
  B(magicCube);
  B(magicCube);
}

typedef void (*FunctionCallback)(int*);
FunctionCallback moves[] = {&R, &Rh, &R2, &L, &Lh, &L2, &U, &Uh, &U2, &D, &Dh, &D2, &F, &Fh, &F2, &B, &Bh, &B2};

void RubiksCube::scramble(int amountOfMoves){

  for( int i = 0 ; i < amountOfMoves ; i++){

    moves[rand()%18](this->pieces);

  }

}

vector<int> RubiksCube::scrambleReturningAnswer(int amountOfMoves){

  vector<int> answer;
  int OldRandomMove = -1;
  for( int i = 0 ; i < amountOfMoves ; i++){

    int randomMove = rand()%18;
    if(OldRandomMove != -1){
      while(1){
        int sair = 1;

        if((int)(randomMove/3) == (int)(OldRandomMove/3)) sair = 0;
        if(sair == 1) break;
        randomMove = rand()%18;
      }
    }
    moves[randomMove](this->pieces);
    OldRandomMove = randomMove;

    switch(randomMove%3){
      case 0:
        answer.insert(answer.begin(),randomMove+1);
        break;
      case 1:
        answer.insert(answer.begin(),randomMove-1);
        break;
      case 2:
        answer.insert(answer.begin(),randomMove);
        break;
    }

  }

  return answer;

}

int RubiksCube::isSolved(){

  for(int i = 0; i < 6 ; i++){
    for(int j = 0; j < 9; j++){
        if(this->pieces[i*9+j] != i){
          return 0;
        }
    }
  }
  return 1;
  
}

RubiksCube* RubiksCube::clone(){

  RubiksCube* clone = new RubiksCube();

  for(int i = 0; i < 54 ; i++){
      clone->pieces[i] = this->pieces[i];
  }

  return clone;
}

void RubiksCube::reset(){
  for(int i = 0; i < 6 ; i++){
      for(int j = 0; j < 9; j++){
          this->pieces[i*9+j] = i;
      }
  }
}

void RubiksCube::applyMoveVector(vector<int> moveVector){
  for( int i = 0 ; i < moveVector.size() ; i++){
    moves[moveVector.at(i)](this->pieces);
  }
}

void RubiksCube::Move(int direction){
  moves[direction](this->pieces);
}

void RubiksCube::printRubiksCube(){

  int firstLine[12] = {9,10,11,36,37,38,27,28,29,45,46,47};

  for(int j = 0 ; j < 3 ; j++){
      printf("%12c",' ');
      for(int i = 0 ; i < 3 ; i++){
          cout << this->auxiliarPrint.at(this->pieces[i+j*3]) << " " << this->auxiliarPrint.at(-1) << "   ";
      }
      cout << endl << endl;
  }

  for( int j = 0 ; j < 3 ; j++){
      for( int i = 0 ; i < 12 ; i++){
          cout << this->auxiliarPrint.at(this->pieces[firstLine[i]+j*3]) << " " << this->auxiliarPrint.at(-1) << "   ";
      }
      cout << endl << endl;
  }

  for(int j = 0 ; j < 3 ; j++){
      printf("%12c",' ');
      for(int i = 0 ; i < 3 ; i++){
          cout << this->auxiliarPrint.at(this->pieces[i+j*3+18]) << " " << this->auxiliarPrint.at(-1) << "   ";
      }
      cout << endl << endl;
  }
  cout << endl;
}

int RubiksCube::evalueteWithPairs(){
  int gradePerPair = 1;
  int gradePerLine = 1;
  int gradePerSquare = 1;
  int gradePerCorrectPiece = 0;

  int grade = 0;
  for( int i = 0 ; i < 6 ; i++){
    int initial = 9*i;

    // Verify all pairs
    for(int j = 0 ; j < 3 ; j++){
      // pair 0,1
      if(this->pieces[initial+3*j] == this->pieces[initial+1+3*j]){
        grade += gradePerPair;
      }
      // pair 1,2
      if(this->pieces[initial+1+3*j] == this->pieces[initial+2+3*j]){
        grade += gradePerPair;
      }
      // Line 0,1,2
      if(this->pieces[initial+3*j] == this->pieces[initial+1+3*j] && this->pieces[initial+3*j] == this->pieces[initial+2+3*j]){
        grade += gradePerLine;
      }
      // pair 0,3
      if(this->pieces[initial+j] == this->pieces[initial+3+j]){
        grade += gradePerPair;
      }
      // pair 3,6
      if(this->pieces[initial+3+j] == this->pieces[initial+6+j]){
        grade += gradePerPair;
      }
      // Line 0,3,6
      if(this->pieces[initial+j] == this->pieces[initial+3+j] && this->pieces[initial+j] == this->pieces[initial+6+j]){
        grade += gradePerLine;
      }
    }
    
    // All squares
    int controler = 0;
    while(1){
      if(this->pieces[initial+controler] == this->pieces[initial+1+controler] && this->pieces[initial+controler] == this->pieces[initial+3+controler] && this->pieces[initial+controler] == this->pieces[initial+4+controler]){
        grade += gradePerSquare;
      }

      if(controler == 4) break;
      if(controler == 3) controler = 4;
      if(controler == 1) controler = 3;
      if(controler == 0) controler = 1;
      
    }

  }

  for(int i = 0; i < 6 ; i++){
    for(int j = 0; j < 9; j++){
      if(this->pieces[i*9+j] == i){
        grade += gradePerCorrectPiece;
      }
    }
  }
  return grade;
}