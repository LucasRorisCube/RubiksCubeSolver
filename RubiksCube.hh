#ifndef __RubiksCube__
#define __RubiksCube__

#include <map>
#include <iostream>
#include <vector>

using namespace std;


class RubiksCube
{
    public:
        int pieces[54];
        RubiksCube(){
            for(int i = 0; i < 6 ; i++){
                for(int j = 0; j < 9; j++){
                    this->pieces[i*9+j] = i;
                }
            }
        }

        const map<int,string> auxiliarPrint {
            {-1,"\e[0m"},
            {0,"\033[48;2;255;255;0m"},
            {1,"\033[48;2;255;0;0m"},
            {2,"\033[48;2;255;255;255m"},
            {3,"\033[48;2;255;165;0m"},
            {4,"\033[48;2;0;255;0m"},
            {5,"\033[48;2;63;160;239m"}
        };

        void scramble(int moves);
        int isSolved();
        void applyMoveVector(vector<int> moveVector);
        RubiksCube* clone();
        int evalueteWithPairs();
        void Move(int direction);
        vector<int> scrambleReturningAnswer(int amountOfMoves);
        void reset();
        void printRubiksCube();

};

#endif