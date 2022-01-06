// David Oke
// Game of Life
// May 12, 2020

#include <iostream>
#include<vector>

using namespace std;

int aliveRuleApply(int a);              // Function to apply the rules for alive cells
int deadRuleApply(int a);               // Function to apply the rules for dead cells

int edgeRuleApply1(int a, int b,const vector<vector<int> >& grid);   // Functions for the rules for each edge element on the grid
int edgeRuleApply2(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply3(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply4(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply5(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply6(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply7(int a, int b,const vector<vector<int> >& grid);
int edgeRuleApply8(int a, int b,const vector<vector<int> >& grid);

int main()
{
    int userNum1, userNum2, userNum3, userNum4, userNum5, sizeNum, genCount;
    int counter{0}, neighbourCount{0};

    vector<vector<int> > grid{0};            // Vector for the grid
    vector<vector<int> > newGrid{0};         // Vector for the grid in the next generation

    cout << "Welcome to the Game of Life!" <<endl;
    cout << "Enter the size of the square grid: ";
    cin >> sizeNum;
    cout << "Enter the number of generations you would like to run it for: ";
    cin >> genCount;
    cout << "Enter five intital live cells: ";
    cout <<endl;
    cin >> userNum1 >> userNum2 >> userNum3 >> userNum4 >> userNum5;

    for(int i{0}; i < sizeNum; i++)
    {
        grid.push_back(vector<int>(sizeNum));     // To make the vectors the user-inputted size
        newGrid.push_back(vector<int>(sizeNum));
    }

    for(int i{0}; i <= sizeNum-1; i++)      // To make the user choices alive cells
    {
        for(int j{0}; j <= sizeNum-1; j++)
        {
            grid.at(i).at(j) = 0;
            counter++;
            if(counter == userNum1)
                 grid.at(i).at(j) = 1;
            else if(counter == userNum2)
                 grid.at(i).at(j) = 1;
            else if(counter == userNum3)
                 grid.at(i).at(j) = 1;
            else if(counter == userNum4)
                 grid.at(i).at(j) = 1;
            else if(counter == userNum5)
                 grid.at(i).at(j) = 1;
            else
                continue;
        }
    }

    for(int i{0}; i <= genCount; i++)       // To run for the user inputted amount of generations
    {
        for(int i{0}; i <= sizeNum - 1; i++)    // To run for the size of the vector
        {
            for(int j{0}; j <= sizeNum - 1; j++)                 // To check if the element is on the edge of the vector
            {
                if(j == 0 && i != 0 && i != sizeNum - 1)
                {
                    neighbourCount = edgeRuleApply1(j, i, grid);
                }
                else if(i == 0 && j != 0 && j != sizeNum - 1)
                {
                    neighbourCount = edgeRuleApply2(j, i, grid);
                }
                else if(j == sizeNum - 1 && i != sizeNum - 1 && i != 0)
                {
                    neighbourCount = edgeRuleApply3(j, i, grid);
                }
                else if(i == sizeNum - 1 && j != sizeNum - 1 && j != 0)
                {
                    neighbourCount = edgeRuleApply4(j, i, grid);
                }
                else if(j == 0 && i == 0)
                {
                    neighbourCount = edgeRuleApply5(j, i, grid);
                }
                else if(j == sizeNum - 1 && i == 0)
                {
                    neighbourCount = edgeRuleApply6(j, i, grid);
                }
                else if(j == 0 && i == sizeNum - 1)
                {
                    neighbourCount = edgeRuleApply7(j, i, grid);
                }
                else if(j == sizeNum - 1 && i == sizeNum - 1)
                {
                    neighbourCount = edgeRuleApply8(j, i, grid);
                }
                else
                {
                    if(grid.at(j-1).at(i) == 1)                 // Rules for non-edge elements of the vector
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j+1).at(i) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j).at(i+1) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j).at(i-1) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j+1).at(i+1) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j-1).at(i-1) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j+1).at(i-1) == 1)
                    {
                        neighbourCount++;
                    }
                    if(grid.at(j-1).at(i+1) == 1)
                    {
                        neighbourCount++;
                    }
                }
                if(grid.at(j).at(i) == 1)
                {
                    newGrid.at(j).at(i) = aliveRuleApply(neighbourCount);       // Function call to apply the rules for alive cells
                }
                else if(grid.at(j).at(i) == 0)
                {
                    newGrid.at(j).at(i) = deadRuleApply(neighbourCount);        // Function call to apply the rules for dead cells
                }

                neighbourCount = 0;
            }
        }

        for(int i{0}; i <= sizeNum-1; i++)              // To output the grid at each generation
        {
            cout <<endl;
            for(int j{0}; j <= sizeNum-1; j++)
            {
                cout << grid.at(j).at(i);
                cout << " ";
            }
        }

        cout << endl << "Generation: " << i << endl;
        grid = newGrid;
    }
}
int aliveRuleApply(int a)       // Function definition for the application of the rules for alive cells, will return 0 or 1
{
    if(a < 2)
        return 0;
    else if(a > 3)
        return 0;
    else if( a == 2 || a == 3)
        return 1;
}
int deadRuleApply(int a)    // Function definition for the application of the rules for dead cells, will return 0 or 1
{
    if(a == 3)
        return 1;
    else
        return 0;
}
int edgeRuleApply1(int j, int i, const vector<vector<int>>& grid)   // Ruleset for top edge cells
{
    int neighbourCount{0};
     if(grid.at(j).at(i-1) == 1)
     {
        neighbourCount++;
     }
     if(grid.at(j).at(i+1) == 1)
     {
        neighbourCount++;
     }
     if(grid.at(j+1).at(i) == 1)
     {
        neighbourCount++;
     }
     if(grid.at(j+1).at(i-1) == 1)
     {
        neighbourCount++;
     }
     if(grid.at(j+1).at(i+1) == 1)
     {
        neighbourCount++;
     }
     return neighbourCount;
}
int edgeRuleApply2(int j, int i, const vector<vector<int>>&grid)    // Ruleset for left edge cells
{
    int neighbourCount{0};
    if(grid.at(j+1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j).at(i+1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i+1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i+1) == 1)
    {
        neighbourCount++;
    }
    return neighbourCount;
}
int edgeRuleApply3(int j, int i, const vector<vector<int>>&grid)        // Ruleset for bottom edge cells
{
    int neighbourCount{0};
    if(grid.at(j).at(i+1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i+1) == 1)
    {
        neighbourCount++;
    }

    return neighbourCount;
}
int edgeRuleApply4(int j, int i, const vector<vector<int>>&grid)    // Ruleset for right edge cells
{
    int neighbourCount{0};

    if(grid.at(j).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i-1) == 1)
    {
        neighbourCount++;
    }

    return neighbourCount;

}
int edgeRuleApply5(int j, int i, const vector<vector<int>>&grid)    // Ruleset for top left corner cell
{
    int neighbourCount{0};

    if(grid.at(j+1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j).at(i+1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i+1) == 1)
    {
        neighbourCount++;
    }


    return neighbourCount;
}
int edgeRuleApply6(int j, int i, const vector<vector<int>>&grid)    // Ruleset for bottom left corner cell
{
    int neighbourCount{0};

    if(grid.at(j-1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j).at(i+1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i+1) == 1)
    {
        neighbourCount++;
    }

    return neighbourCount;
}
int edgeRuleApply7(int j, int i, const vector<vector<int>>&grid)        // Ruleset for top right corner cell
{
    int neighbourCount{0};

    if(grid.at(j).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j+1).at(i-1) == 1)
    {
        neighbourCount++;
    }

    return neighbourCount;
}
int edgeRuleApply8(int j, int i, const vector<vector<int>>&grid)         // Ruleset for bottom right corner cell
{
    int neighbourCount{0};

    if(grid.at(j-1).at(i) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j).at(i-1) == 1)
    {
        neighbourCount++;
    }
    if(grid.at(j-1).at(i-1) == 1)
    {
        neighbourCount++;
    }

    return neighbourCount;
}
