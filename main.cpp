#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>
#include "RubiksCube.hh"


void printVectorMoves(vector<int> vetor){
  // Print answer moves
  for(int i = 0 ; i < vetor.size() ; i++){
    switch(vetor[i]){
      case 0:
        cout << "R";
        break;
      case 1:
        cout << "Rh";
        break;
      case 2:
        cout << "R2";
        break;
      case 3:
        cout << "L";
        break;
      case 4:
        cout << "Lh";
        break;
      case 5:
        cout << "L2";
        break;
      case 6:
        cout << "U";
        break;
      case 7:
        cout << "Uh";
        break;
      case 8:
        cout << "U2";
        break;
      case 9:
        cout << "D";
        break;
      case 10:
        cout << "Dh";
        break;
      case 11:
        cout << "D2";
        break;
      case 12:
        cout << "F";
        break;
      case 13:
        cout << "Fh";
        break;
      case 14:
        cout << "F2";
        break;
      case 15:
        cout << "B";
        break;
      case 16:
        cout << "Bh";
        break;
      case 17:
        cout << "B2";
        break;
    }
    if(i+1 == vetor.size()){
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

// Function make a median of grades of solutions
vector<float> generateMedianGrade(int moves){

  // Number of cubes to test
  int numCubes = 50000;
  vector<float> grades;

  RubiksCube* cube = new RubiksCube();

  // Initialization of vector of grades
  for(int i = 0 ; i < moves ; i++) grades.push_back(0);

  for(int n = 0 ; n < numCubes ; n++){

    // Always reset the cube
    cube->reset();

    // Scramble the cube returning the answer
    vector<int> answer = cube->scrambleReturningAnswer(moves);

    // Move and evaluate the current state of cube
    for(int i = 0 ; i < answer.size() ; i++){
        
      cube->Move(answer[i]);

      grades[i] += cube->evalueteWithPairs();
    }
  }

  // Take the normal median
  for(int i = 0 ; i < moves ; i++) grades[i] /= (float)numCubes;

  delete(cube);
  return grades;
}

vector<int> AG(RubiksCube* originalCube){
    
    // Initial parameters
    int numPopulation = 100000;
    int numMaxMoves = 50;
    float weightsOfSize = 1.0;
    float percentToPreserve = 0.1;

    // Find the median of grade in a solution
    vector<float> medianGrades = generateMedianGrade(numMaxMoves);

    // Start the tax of mutation with 1
    int taxMutation = 1;

    int geration = 1;

    // Define weights to moves
    vector<float> weights;
    for( int i = 0 ; i < numMaxMoves ; i++){
        if(i+6 > numMaxMoves){
            weights.push_back(3.0);
        } else {
            weights.push_back(1.0);
        }
    }

    // Find what is the max possible grade one cube can recieve
    RubiksCube* aux = new RubiksCube();
    int maxPossibleGrade = aux->evalueteWithPairs();
    delete(aux);

    ////////////////////////////** Initialization **////////////////////////////

    // Start population, reserving space in RAM
    vector<vector<int>> population;
    population.reserve(numPopulation);

    for( int i = 0 ; i < numPopulation ; i++ ){
        
        // Make an individual with random size and random moves
        vector<int> individual;

        int numMoves = 1 + rand()%numMaxMoves;

        for( int k = 0 ; k < numMoves ; k++ ) individual.push_back(rand()%18);

        // Add individual in population
        population.push_back(individual);

    }

    float oldBestGrade = 10000;
    int count = 0;
    // The function never stop until the cube has been solved
    while(1){
        ////////////////////////////** Avaliation **////////////////////////////

        vector<float> grades;

        // Evaluate all individuals of population
        for( vector<int> individual : population ){

            // If individual not have moves, he will be the worst
            if( individual.size() == 0){
                grades.push_back(10000);
                continue;

            }

            // To evaluate all for equals, we make a clone of original and move only the clone
            // The original cube never is moved, only in final solution
            RubiksCube* clone = originalCube->clone();
            float finalGrade = 0;

            // For every move, we compare with the median and take the module of distance of points
            for( int i = 0 ; i < individual.size() ; i++){

                // Apply one move
                clone->Move(individual[i]);

                // Verify the grade
                int grade = clone->evalueteWithPairs();

                // If cuve is solved, end the algorithm 
                if(grade == maxPossibleGrade){
                    // Return only solution
                    individual.erase(individual.begin()+i+1,individual.end());
                    return individual;
                }

                // Calcule the final grade, verify the absolute distance of grade to median grade, and applying weight
                float auxGrade = grade-medianGrades[numMaxMoves-individual.size()+i];
                finalGrade += weights[numMaxMoves-individual.size()+i]*(auxGrade < 0)?-auxGrade:auxGrade;
                
            }
            
            // Make the median
            finalGrade /= individual.size();
            finalGrade += individual.size()*weightsOfSize;
            grades.push_back(finalGrade);
            delete(clone);

        }

        ////////////////////////////** Selection **////////////////////////////

        // Make a vector in index of individuals
        vector<int> indexBestIndividuals;
        int numBestToPreserve = numPopulation*percentToPreserve;

        // Discovery all the n best individuals of population
        for(int j = 0 ; j < numBestToPreserve ; j++){

            float minGrade = 10000;
            int indexChoose = -1;

            for( int i = 0 ; i < numPopulation ; i++){

                if(j != 0){
                    if(grades[i] < minGrade && grades[i] > grades[indexBestIndividuals[j-1]]){
                        minGrade = grades[i];
                        indexChoose = i;
                    }
                } else {
                    if(grades[i] < minGrade){
                        minGrade = grades[i];
                        indexChoose = i;
                    }
                }
            }

            indexBestIndividuals.push_back(indexChoose);
        }

        ////////////////////////////** Print the best **////////////////////////////

        // Print the best individual to see if the population is converting to solution
        RubiksCube* clone = originalCube->clone();
        clone->applyMoveVector(population[indexBestIndividuals[0]]);
        originalCube->printRubiksCube();
        clone->printRubiksCube();
        delete(clone);
        cout << "Numero de movimentos: " << population[indexBestIndividuals[0]].size() << endl;
        cout << "Menor nota: " << grades[indexBestIndividuals[0]] << endl;
        cout << "Taxa de mutacao: " << taxMutation << endl;
        cout << "Geracao: " << geration << endl;

        // If the best individual is the same for 5 times, plus one in taxMutation
        if(oldBestGrade == grades[indexBestIndividuals[0]]){
            count++;
        } else {
            count = 0;
            taxMutation = 1;
        }

        if(count == 5){
            taxMutation++;
            count = 0;
        }

        oldBestGrade = grades[indexBestIndividuals[0]];
        
        ////////////////////////////** Cloning + Mutation **////////////////////////////

        // Transforme the vector of index for a vector of individuals
        vector<vector<int>> theBests;
        theBests.reserve(numBestToPreserve);
        for( int index : indexBestIndividuals) theBests.push_back(population[index]);

        // Clear population
        population.clear();

        int numClonePerIndividual = numPopulation/numBestToPreserve - 1;

        // For each individual, will make n clones with a little variation
        for( vector<int> individual : theBests){

            population.push_back(individual);

            for( int j = 0 ; j < numClonePerIndividual ; j++){

                vector<int> clone = individual;

                for( int i = 0 ; i < taxMutation ; i++){

                    // The variation can be a mudance of movimente, or erase one move, or add a new move
                    int randOperation = rand()%3;

                    // Erase a random move
                    if(randOperation == 0){

                        if(clone.size() != 1)
                            clone.erase(clone.begin()+rand()%clone.size());

                    // Add on final a random move
                    } else if(randOperation == 1){

                        if(clone.size() <= numMaxMoves)
                            clone.push_back(rand()%18);

                    } else {

                        // Modificate a random move
                        if(clone.size() != 0)
                            clone[rand()%clone.size()] = rand()%18;

                    }

                }

                population.push_back(clone);
            }
            
        }

        geration++;

        // If geration ultrapass 25, will make predation and restart all individuals of population
        if( geration%25 == 0){
            population.clear();
            taxMutation = 1;
            count = 0;
            for( int i = 0 ; i < numPopulation ; i++ ){
        
                vector<int> individual;

                int numMoves = rand()%numMaxMoves;

                for( int k = 0 ; k < numMoves ; k++ ) individual.push_back(rand()%18);

                population.push_back(individual);

            }
        }
    }
    // Return error mensage
    vector<int> error;
    error.push_back(-1);
    return error;
}

int applyAG(RubiksCube* originalCube){

  // Apply the AG algorithm and return the moves to complete the cube
  vector<int> answer = AG(originalCube);

  // If ocurrent any problem with solution
  if(answer[0] == -1){
    cout << "Nao consegui resolver" << endl;
    return 0;
  }

  printVectorMoves(answer);

  // Print before and after apply solve the cube
  originalCube->printRubiksCube();
  originalCube->applyMoveVector(answer);
  originalCube->printRubiksCube();
  return 1;
}



int main(void) {
  
  // Create a seed of random numbers
  srand(time(NULL));

  // Create a Rubiks Cube solved
  RubiksCube* originalCube = new RubiksCube();
  
  // Scremble it with a number of moves
  originalCube->scramble(10);
  
  // Apply the Evolutive Algorithm
  applyAG(originalCube);

  // Free memory;
  delete(originalCube);

  // Return sucess
  return 0;
}