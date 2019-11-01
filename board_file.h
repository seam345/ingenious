//
// Created by sean on 30/10/2019.
//

#pragma once

#include <array>
#include <vector>
#include <memory>

using namespace std;

class board
{
public:
    board(const int& players);

    board(const int& players, bool test);

    int getPointValue(int ring, int section, int position);

    int setPointValue(int ring, int section, int position, int value);

    std::vector<int> getTopRight(int ring, int section, int position);

    std::vector<int> getRight(int ring, int section, int position);

    std::vector<int> getTopLeft(int ring, int section, int position);

    std::vector<int> getRightBottom(int ring, int section, int position);

    std::vector<int> getLeftBottom(int ring, int section, int position);

    std::vector<int> getLeft(int ring, int section, int position);


private:
    vector<vector<int>> centerPoint;
    vector<vector<int>> ring1;
    vector<vector<int>> ring2;
    vector<vector<int>> ring3;
    vector<vector<int>> ring4;
    vector<vector<int>> ring5;
    vector<vector<int>> ring6;
    vector<vector<int>> ring7;
    std::vector<std::vector<std::vector<int>>> state;


};


