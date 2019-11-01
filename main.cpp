#include <iostream>
#include "main.h"
#include "board_file.h"
//#include "board_file.cpp"


int main() {
    test();
//    std::cout << "Add hand" << std::endl;
//    std::cout << "first tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    int hand[6][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
//    std::cin >> hand[0][0] >> hand[0][1];
//    std::cout << "second tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    std::cin >> hand[1][0] >> hand[1][1];
//    std::cout << "3rd tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    std::cin >> hand[2][0] >> hand[2][1];
//    std::cout << "4th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    std::cin >> hand[3][0] >> hand[3][1];
//    std::cout << "5th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    std::cin >> hand[4][0] >> hand[4][1];
//    std::cout << "6th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
//    std::cin >> hand[5][0] >> hand[5][1];
//
//    printf("1(%d, %d)", hand[0][0], hand[0][1]);
//    printf("2(%d, %d)", hand[1][0], hand[1][1]);
//    printf("3(%d, %d)", hand[2][0], hand[2][1]);
//    printf("4(%d, %d)", hand[3][0], hand[3][1]);
//    printf("5(%d, %d)", hand[4][0], hand[4][1]);
//    printf("6(%d, %d)", hand[5][0], hand[5][1]);

    board gameBoard(2);
    board gsameBoard(3, false);


//    return 0;
}

void dumpState()
{

}

void test()
{
    board testBoard(2, false);


    printf("centerPoint %d\n", testBoard.getPointValue(0,0,0));


    printf("centerPointTopRight(120) %d\n", testBoard.getTopRight(0, 0, 0)[0]);
    printf("100TopRight(110) %d\n", testBoard.getTopRight(1, 0, 0)[0]);
    printf("200TopRight(201) %d\n", testBoard.getTopRight(2, 0, 0)[0]);
    printf("352TopRight(200) %d\n", testBoard.getTopRight(3, 5, 2)[0]);
    printf("341TopRight(241) %d\n", testBoard.getTopRight(3, 4, 1)[0]);
    printf("241TopRight(140) %d\n", testBoard.getTopRight(2, 4, 1)[0]);
    printf("230TopRight(322) %d\n", testBoard.getTopRight(2, 3, 0)[0]);
    printf("150TopRight(000) %d\n", testBoard.getTopRight(1, 5, 0)[0]);
    printf("351TopRight(251) %d\n", testBoard.getTopRight(3, 5, 1)[0]);
    printf("340TopRight(332) %d\n", testBoard.getTopRight(3, 4, 0)[0]);

    printf("centerPointTopLeft(110) %d\n", testBoard.getTopLeft(0, 0, 0)[0]);
    printf("100TopLeft(201) %d\n", testBoard.getTopLeft(1, 0, 0)[0]);
    printf("200TopLeft(301) %d\n", testBoard.getTopLeft(2, 0, 0)[0]);
    printf("352TopLeft(300) %d\n", testBoard.getTopLeft(3, 5, 2)[0]);
    printf("341TopLeft(241) %d\n", testBoard.getTopLeft(3, 4, 1)[0]);
    printf("241TopLeft(150) %d\n", testBoard.getTopLeft(2, 4, 1)[0]);
    printf("230TopLeft(221) %d\n", testBoard.getTopLeft(2, 3, 0)[0]);
    printf("150TopLeft(100) %d\n", testBoard.getTopLeft(1, 5, 0)[0]);
    printf("351TopLeft(352) %d\n", testBoard.getTopLeft(3, 5, 1)[0]);
    printf("340TopLeft(240) %d\n", testBoard.getTopLeft(3, 4, 0)[0]);

    printf("000Right(130) %d\n", testBoard.getRight(0, 0, 0)[0]);
    printf("100Right(000) %d\n", testBoard.getRight(1, 0, 0)[0]);
    printf("200Right(100) %d\n", testBoard.getRight(2, 0, 0)[0]);
    printf("352Right(251) %d\n", testBoard.getRight(3, 5, 2)[0]);
    printf("341Right(340) %d\n", testBoard.getRight(3, 4, 1)[0]);
    printf("241Right(240) %d\n", testBoard.getRight(2, 4, 1)[0]);
    printf("230Right(330) %d\n", testBoard.getRight(2, 3, 0)[0]);
    printf("150Right(140) %d\n", testBoard.getRight(1, 5, 0)[0]);
    printf("351Right(250) %d\n", testBoard.getRight(3, 5, 1)[0]);
    printf("340Right(433) %d\n", testBoard.getRight(3, 4, 0)[0]);

    printf("000Left(100) %d\n", testBoard.getLeft(0, 0, 0)[0]);
    printf("100Left(200) %d\n", testBoard.getLeft(1, 0, 0)[0]);
    printf("200Left(300) %d\n", testBoard.getLeft(2, 0, 0)[0]);
    printf("352Left(453) %d\n", testBoard.getLeft(3, 5, 2)[0]);
    printf("341Left(342) %d\n", testBoard.getLeft(3, 4, 1)[0]);
    printf("241Left(250) %d\n", testBoard.getLeft(2, 4, 1)[0]);
    printf("230Left(130) %d\n", testBoard.getLeft(2, 3, 0)[0]);
    printf("150Left(251) %d\n", testBoard.getLeft(1, 5, 0)[0]);
    printf("351Left(452) %d\n", testBoard.getLeft(3, 5, 1)[0]);
    printf("340Left(341) %d\n", testBoard.getLeft(3, 4, 0)[0]);

    printf("000LeftBottom(150) %d\n", testBoard.getLeftBottom(0, 0, 0)[0]);
    printf("100LeftBottom(251) %d\n", testBoard.getLeftBottom(1, 0, 0)[0]);
    printf("110LeftBottom(000) %d\n", testBoard.getLeftBottom(1, 1, 0)[0]);
    printf("200LeftBottom(352) %d\n", testBoard.getLeftBottom(2, 0, 0)[0]);
    printf("352LeftBottom(452) %d\n", testBoard.getLeftBottom(3, 5, 2)[0]);
    printf("341LeftBottom(442) %d\n", testBoard.getLeftBottom(3, 4, 1)[0]);
    printf("241LeftBottom(342) %d\n", testBoard.getLeftBottom(2, 4, 1)[0]);
    printf("230LeftBottom(231) %d\n", testBoard.getLeftBottom(2, 3, 0)[0]);
    printf("150LeftBottom(250) %d\n", testBoard.getLeftBottom(1, 5, 0)[0]);
    printf("351LeftBottom(451) %d\n", testBoard.getLeftBottom(3, 5, 1)[0]);
    printf("340LeftBottom(441) %d\n", testBoard.getLeftBottom(3, 4, 0)[0]);

    printf("110RightBottom(000) %d\n", testBoard.getRightBottom(1, 1, 0)[0]);
    printf("000RightBottom(140) %d\n", testBoard.getRightBottom(0, 0, 0)[0]);
    printf("100RightBottom(150) %d\n", testBoard.getRightBottom(1, 0, 0)[0]);
    printf("200RightBottom(251) %d\n", testBoard.getRightBottom(2, 0, 0)[0]);
    printf("352RightBottom(351) %d\n", testBoard.getRightBottom(3, 5, 2)[0]);
    printf("341RightBottom(441) %d\n", testBoard.getRightBottom(3, 4, 1)[0]);
    printf("241RightBottom(341) %d\n", testBoard.getRightBottom(2, 4, 1)[0]);
    printf("230RightBottom(331) %d\n", testBoard.getRightBottom(2, 3, 0)[0]);
    printf("150RightBottom(241) %d\n", testBoard.getRightBottom(1, 5, 0)[0]);
    printf("351RightBottom(350) %d\n", testBoard.getRightBottom(3, 5, 1)[0]);
    printf("340RightBottom(440) %d\n", testBoard.getRightBottom(3, 4, 0)[0]);

    int start[] = {1,1,0};
    vector<int> current = testBoard.getRight(start[0],start[1],start[2]);
    current = testBoard.getRightBottom(current[1], current[2], current[3]);
    current = testBoard.getLeftBottom(current[1], current[2], current[3]);
    current = testBoard.getLeft(current[1], current[2], current[3]);
    current = testBoard.getTopLeft(current[1], current[2], current[3]);
    current = testBoard.getTopRight(current[1], current[2], current[3]);

    vector<int> current2 = testBoard.getRight(start[0],start[1],start[2]);
    int value = current2[0];
    int total = value;
    while (value != -1)
    {
        current2 = testBoard.getTopRight(current2[1], current2[2], current2[3]);
        value=current2[0];
        total += current2[0];
    }
    printf("centerPoint %d\n", testBoard.setPointValue(0,0,0, 5));
    printf("centerPoint %d\n", testBoard.getPointValue(0,0,0));

    printf("start: %d current %d", testBoard.getPointValue(start[0],start[1],start[2]), current[0]);

    return;
}