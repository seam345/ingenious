//
// Created by sean on 30/10/2019.
//

#pragma once

#include <array>
#include <vector>
#include <memory>

struct Score {
    int red12pointedStar;
    int greenCircle;
    int blue6PointedStar;
    int orangeHexagon;
    int yellow24PointedStar;
    int purpleRing;
};

void operator+=(Score& lhs, const Score& rhs );
Score operator+(const Score& lhs, const Score& rhs );
bool operator< (const Score& lhs, const Score& rhs);
bool operator> (const Score& lhs, const Score& rhs);



//Score& operator+=(const Score& rhs);

enum class shape
{
    red12pointedStar = 1,
    greenCircle = 2,
    blue6PointedStar = 3,
    orangeHexagon = 4,
    yellow24PointedStar = 5,
    purpleRing = 6
};

const int red12pointedStar = 1;
const int greenCircle = 2;
const int blue6PointedStar = 3;
const int orangeHexagon = 4;
const int yellow24PointedStar = 5;
const int purpleRing = 6;

const int r = red12pointedStar;
const int g = greenCircle;
const int b = blue6PointedStar;
const int o = orangeHexagon;
const int y = yellow24PointedStar;
const int p = purpleRing;

class board
{
public:
//    board(const int& players);
    struct Coordinate
    {
        int ring;
        int section;
        int position;
    };
    struct Point
    {
        int value;
        Coordinate coordinates;
    };


    board(const int &players, bool test = false);

    int getPointValue(Coordinate coordinates);

    int setPointValue(Point point);

    Point getTopRight(Coordinate coordinates);

    Point getRight(Coordinate coordinates);

    Point getTopLeft(Coordinate coordinates);

    Point getRightBottom(Coordinate coordinates);

    Point getLeftBottom(Coordinate coordinates);

    Point getLeft(Coordinate coordinates);

    Score placeTile(Point tilePoint1, Point tilePoint2);

    Score checkTile(Point tilePoint1, Point tilePoint2);

    Score getScoreForPosition(board::Point tilePoint1);

private:
    std::vector<std::vector<int>> centerPoint;
    std::vector<std::vector<int>> ring1;
    std::vector<std::vector<int>> ring2;
    std::vector<std::vector<int>> ring3;
    std::vector<std::vector<int>> ring4;
    std::vector<std::vector<int>> ring5;
    std::vector<std::vector<int>> ring6;
    std::vector<std::vector<int>> ring7;
    std::vector<std::vector<std::vector<int>>> state;

};