#include <iostream>

#include "board_file.h"
#include <utility>

void test();

void dumpState(board outputBoard);

struct Tile
{
    int value1;
    int value2;
};

struct Hand
{
    Tile tile1;
    Tile tile2;
    Tile tile3;
    Tile tile4;
    Tile tile5;
    Tile tile6;

    Tile &operator[](int index)
    {
        if (index >= 8)
        {
            std::cout << "Array index out of bound, exiting";
            exit(0);
        }

        if (index == 0) return tile1;
        if (index == 1) return tile2;
        if (index == 2) return tile3;
        if (index == 3) return tile4;
        if (index == 4) return tile5;
        if (index == 5) return tile6;
    }
};

struct Player
{
    Hand hand = {{0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0}};;
    Score score = {0, 0, 0, 0, 0, 0};
    bool ai = false;
};

std::pair<int, Score>
checkHand(board currentBoard, Hand hand, Score currentScore, board::Coordinate position1, board::Coordinate position2);

std::pair<std::array<board::Coordinate, 2>, int> checkBoard(board currentBoard, Hand hand, Score currentScore);

bool hasIngenioused(Score originalScore, Score additionScore);


int main()
{
//    test();
//    int hand[6][2] = {{0, 0},
//                      {0, 0},
//                      {0, 0},
//                      {0, 0},
//                      {0, 0},
//                      {0, 0}};
    std::cout << "Enter number of players: " << std::endl;
    int playerNum;
    std::cin >> playerNum;
    board gameBoard(playerNum);

    Hand hand = {{0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0},
                 {0, 0}};

//    Hand hand = {{2, 3},
//                 {2, 3},
//                 {2, 2},
//                 {2, 3},
//                 {2, 3},
//                 {2, 3}};

    std::cout << "Add hand" << std::endl;
    std::cout << "first tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile1.value1 >> hand.tile1.value2;
    std::cout << "second tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile2.value1 >> hand.tile2.value2;
    std::cout << "3rd tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile3.value1 >> hand.tile3.value2;
    std::cout << "4th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile4.value1 >> hand.tile4.value2;
    std::cout << "5th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile5.value1 >> hand.tile5.value2;
    std::cout << "6th tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple" << std::endl;
    std::cin >> hand.tile6.value1 >> hand.tile6.value2;

    Score player1Score = {0, 0, 0, 0, 0, 0};
    Player player1 = {hand, player1Score, true};
    Player player2;
    Score player2Score = {0, 0, 0, 0, 0, 0};


    std::cout << "continue 1=yes 0=no : " << std::endl;
    int cont;
    std::cin >> cont;
    // todo add ingenious
    while (cont == 1)
    {
        /*std::pair<std::array<board::Coordinate, 2>, int> moveToMake = checkBoard(gameBoard, hand, player1.score);
        Score moveScore = gameBoard.placeTile({hand[moveToMake.second].value1, moveToMake.first[0]},
                                              {hand[moveToMake.second].value2, moveToMake.first[1]});
        std::cout << "put tile (" << hand[moveToMake.second].value1 << "," << hand[moveToMake.second].value2 << ")" <<
                  " ring: " << moveToMake.first[0].ring << " section: " << moveToMake.first[0].section << " position: "
                  << moveToMake.first[0].position <<
                  " ring: " << moveToMake.first[1].ring << " section: " << moveToMake.first[1].section << " position: "
                  << moveToMake.first[1].position << "\n";
        */
        Score moveScore = {0, 0, 0, 0, 0, 0};
        std::vector<int> tilesToReplace;
        do
        {
            player1.score += moveScore; // move score initially 0 allowing me to add it but later it is added to not contaminate the ingenious check
            std::pair<std::array<board::Coordinate, 2>, int> moveToMake = checkBoard(gameBoard, player1.hand,
                                                                                     player1.score);
            std::cout << "put tile (" << player1.hand[moveToMake.second].value1 << ","
                      << player1.hand[moveToMake.second].value2 << ")"
                      << " ring: " << moveToMake.first[0].ring
                      << " section: " << moveToMake.first[0].section
                      << " position: " << moveToMake.first[0].position
                      << " ring: " << moveToMake.first[1].ring
                      << " section: " << moveToMake.first[1].section
                      << " position: " << moveToMake.first[1].position
                      << "\n";
            /*std::cout << "continue = 1 dump = 0: ";
            int continueDump = 1;
            std::cin >> continueDump;
            if (continueDump == 0)
            {
                dumpState(gameBoard);
            }*/
            moveScore = gameBoard.placeTile({player1.hand[moveToMake.second].value1, moveToMake.first[0]},
                                            {player1.hand[moveToMake.second].value2, moveToMake.first[1]});
            player1.hand[moveToMake.second] = {-2, -2}; // remove tile from hand // todo this seemed to fail
            tilesToReplace.push_back(moveToMake.second);
        } while (hasIngenioused(player1.score, moveScore));
        player1.score += moveScore; // here to add the core if not ingenioused

        for (int i : tilesToReplace)
        {
            std::cout << "Please enter a new tile (1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple): ";
            Tile tempTile = {-2, -2};
            std::cin >> tempTile.value1 >> tempTile.value2;
            player1.hand[i] = tempTile;
        }

        Score player2MoveScore = {0,0,0,0,0,0};
        do
        {
            player2.score += player2MoveScore;
            std::cout
                    << "Please enter player 2's move (tile colour 1, ring, section, position, tile colour 2, ring, section, position)\n"
                       "(1=red, 2=green, 3=blue, 4=orange, 5=yellow, 6=purple):\n";
            board::Point point1 = {-1, -1, -1, -1};
            board::Point point2 = {-1, -1, -1, -1};
            std::cin >> point1.value >> point1.coordinates.ring >> point1.coordinates.section
                     >> point1.coordinates.position
                     >> point2.value >> point2.coordinates.ring >> point2.coordinates.section
                     >> point2.coordinates.position;
            player2MoveScore = gameBoard.placeTile(point1, point2);
        } while (hasIngenioused(player2.score, player2MoveScore));
        player2.score += player2MoveScore;

        std::cout << "\nplayer1 score is: \n"
                  << "red12pointedStar: " << player1.score.red12pointedStar << "\n"
                  << "greenCircle: " << player1.score.greenCircle << "\n"
                  << "blue6PointedStar: " << player1.score.blue6PointedStar << "\n"
                  << "orangeHexagon: " << player1.score.orangeHexagon << "\n"
                  << "yellow24PointedStar: " << player1.score.yellow24PointedStar << "\n"
                  << "purpleRing: " << player1.score.purpleRing << "\n\n";

        std::cout << "\nplayer2 score is: \n"
                  << "red12pointedStar: " << player2.score.red12pointedStar << "\n"
                  << "greenCircle: " << player2.score.greenCircle << "\n"
                  << "blue6PointedStar: " << player2.score.blue6PointedStar << "\n"
                  << "orangeHexagon: " << player2.score.orangeHexagon << "\n"
                  << "yellow24PointedStar: " << player2.score.yellow24PointedStar << "\n"
                  << "purpleRing: " << player2.score.purpleRing << "\n\n";

        std::cout << "continue 1=yes 0=no : " << std::endl;
        std::cin >> cont;
    }


    return 0;
}


bool hasIngenioused(Score originalScore, Score additionScore)
{
    Score resultScore = originalScore + additionScore;
    if ((resultScore.red12pointedStar == 18 && originalScore.red12pointedStar < 1) ||
        (resultScore.greenCircle == 18 && originalScore.greenCircle < 18) ||
        (resultScore.blue6PointedStar == 18 && originalScore.blue6PointedStar < 18) ||
        (resultScore.orangeHexagon == 18 && originalScore.orangeHexagon < 18) ||
        (resultScore.yellow24PointedStar == 18 && originalScore.yellow24PointedStar < 18) ||
        (resultScore.purpleRing == 18 && originalScore.purpleRing < 18))
    {
        std::cout << "player has ingenioused playing again!!\n";
        return true;
    }
    return false;
}


std::pair<int, Score>
checkHand(board currentBoard, Hand hand, Score currentScore, board::Coordinate position1, board::Coordinate position2)
{
    Score maxScore = {-1, -1, -1, -1, -1, -1};
    int maxHand = -1;
//    Score tempScore;
//    for (int i = 0; i < 6; ++i)
//    {
//        Score tempScore = currentBoard.checkTile({hand[i].value1, position1}, {hand[i].value2, position2});
//        if (tempScore + currentScore > maxScore + currentScore)
//        {
//            maxScore = tempScore;
//            maxHand = i;
//        }
//    }
    Score tempScore = currentBoard.checkTile({hand.tile1.value1, position1}, {hand.tile1.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 0;
    }
    tempScore = currentBoard.checkTile({hand.tile2.value1, position1}, {hand.tile2.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 1;
    }
    tempScore = currentBoard.checkTile({hand.tile3.value1, position1}, {hand.tile3.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 2;
    }
    tempScore = currentBoard.checkTile({hand.tile4.value1, position1}, {hand.tile4.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 3;
    }
    tempScore = currentBoard.checkTile({hand.tile5.value1, position1}, {hand.tile5.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 4;
    }
    tempScore = currentBoard.checkTile({hand.tile6.value1, position1}, {hand.tile6.value2, position2});
    if (tempScore + currentScore > maxScore + currentScore)
    {
        maxScore = tempScore;
        maxHand = 5;
    }
    return std::make_pair(maxHand, maxScore);
}

//checks board and re
std::pair<std::array<board::Coordinate, 2>, int> checkBoard(board currentBoard, Hand hand, Score currentScore)
{
    std::array<board::Coordinate, 2> tilePlacement = {board::Coordinate{-1, -1, -1}, board::Coordinate{-1, -1, -1}};
    int tilePicked = -1;
    Score maxScore = {-1, -1, -1, -1, -1, -1};
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < i; ++k)
            {
                if (currentBoard.getPointValue({i, j, k}) == 0)
                {
                    board::Point left = currentBoard.getLeft({i, j, k});
                    board::Point leftUp = currentBoard.getTopLeft({i, j, k});
                    board::Point rightUp = currentBoard.getTopRight({i, j, k});
                    board::Point right = currentBoard.getRight({i, j, k});
                    board::Point rightDown = currentBoard.getRightBottom({i, j, k});
                    board::Point leftDown = currentBoard.getLeftBottom({i, j, k});

                    std::array<board::Point, 6> surroundingPoints = {left, leftUp, rightUp, right, rightDown, leftDown};

                    for (int l = 0; l < surroundingPoints.size(); ++l)
                    {
                        if (surroundingPoints[l].value == 0)
                        {
                            std::pair<int, Score> temp = checkHand(currentBoard, hand, currentScore, {i, j, k},
                                                                   surroundingPoints[l].coordinates);
                            if (temp.second + currentScore > maxScore + currentScore)
                            {
                                maxScore = temp.second;
                                tilePicked = temp.first;
                                tilePlacement[0] = {i, j, k};
                                tilePlacement[1] = surroundingPoints[l].coordinates;
                            }
                        }
                    }
                    /*if (left.value == 0)
                    {
                        std::pair<int, Score> temp = checkHand(currentBoard, hand, currentScore, {i,j,k}, left.coordinates);
                        if (temp.second + currentScore > maxScore + currentScore)
                        {
                            maxScore = temp.second;
                            tilePicked = temp.first;
                            position1 = {i,j,k};
                            position2 = left.coordinates;
                        }
                    }*/
                }
            }
        }
    }

    return std::make_pair(tilePlacement, tilePicked);
}


void dumpState(board outputBoard)
{

    printf("centerPoint = {{%d}}\n", outputBoard.getPointValue({0, 0, 0}));
    for (int i = 1; i < 8; ++i)
    {
        printf("ring%d = {\n", i);
        for (int j = 0; j < 6; ++j)
        {
            printf("{");
            for (int k = 0; k < i; ++k)
            {
                printf("%d,", outputBoard.getPointValue({i, j, k}));

            }
            printf("},\n");
        }
        printf("};\n");
    }

    /*int spaceAmount = 42;
    for (int l = 0; l < spaceAmount; ++l)
    {
        printf(" ");
    }
    printf("%d\n", outputBoard.getPointValue({0,0,0}));
    for (int i = 1; i < 8; ++i)
    {
        spaceAmount -= 6;
        for (int l = 0; l < spaceAmount; ++l)
        {
            printf(" ");
        }
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < i; ++k)
            {
                printf("%d,", outputBoard.getPointValue({i,j,k}));

            }
        }
        printf("\n");
    }*/

}

void test()
{
    board testBoard(2, true);


    printf("centerPoint %d\n", testBoard.getPointValue({0, 0, 0}));

    board::Point temp = {0, 0, 0, 0};

    printf("centerPointTopRight(120) %d\n", testBoard.getTopRight({0, 0, 0}).value);
    printf("100TopRight(110) %d\n", testBoard.getTopRight({1, 0, 0}).value);
    printf("200TopRight(201) %d\n", testBoard.getTopRight({2, 0, 0}).value);
    printf("352TopRight(200) %d\n", testBoard.getTopRight({3, 5, 2}).value);
    printf("341TopRight(241) %d\n", testBoard.getTopRight({3, 4, 1}).value);
    printf("241TopRight(140) %d\n", testBoard.getTopRight({2, 4, 1}).value);
    printf("230TopRight(322) %d\n", testBoard.getTopRight({2, 3, 0}).value);
    printf("150TopRight(000) %d\n", testBoard.getTopRight({1, 5, 0}).value);
    printf("351TopRight(251) %d\n", testBoard.getTopRight({3, 5, 1}).value);
    printf("340TopRight(332) %d\n", testBoard.getTopRight({3, 4, 0}).value);

    printf("centerPointTopLeft(110) %d\n", testBoard.getTopLeft({0, 0, 0}).value);
    printf("100TopLeft(201) %d\n", testBoard.getTopLeft({1, 0, 0}).value);
    printf("200TopLeft(301) %d\n", testBoard.getTopLeft({2, 0, 0}).value);
    printf("352TopLeft(300) %d\n", testBoard.getTopLeft({3, 5, 2}).value);
    printf("341TopLeft(241) %d\n", testBoard.getTopLeft({3, 4, 1}).value);
    printf("241TopLeft(150) %d\n", testBoard.getTopLeft({2, 4, 1}).value);
    printf("230TopLeft(221) %d\n", testBoard.getTopLeft({2, 3, 0}).value);
    printf("150TopLeft(100) %d\n", testBoard.getTopLeft({1, 5, 0}).value);
    printf("351TopLeft(352) %d\n", testBoard.getTopLeft({3, 5, 1}).value);
    printf("340TopLeft(240) %d\n", testBoard.getTopLeft({3, 4, 0}).value);

    printf("000Right(130) %d\n", testBoard.getRight({0, 0, 0}).value);
    printf("100Right(000) %d\n", testBoard.getRight({1, 0, 0}).value);
    printf("200Right(100) %d\n", testBoard.getRight({2, 0, 0}).value);
    printf("352Right(251) %d\n", testBoard.getRight({3, 5, 2}).value);
    printf("341Right(340) %d\n", testBoard.getRight({3, 4, 1}).value);
    printf("241Right(240) %d\n", testBoard.getRight({2, 4, 1}).value);
    printf("230Right(330) %d\n", testBoard.getRight({2, 3, 0}).value);
    printf("150Right(140) %d\n", testBoard.getRight({1, 5, 0}).value);
    printf("351Right(250) %d\n", testBoard.getRight({3, 5, 1}).value);
    printf("340Right(433) %d\n", testBoard.getRight({3, 4, 0}).value);

    printf("000Left(100) %d\n", testBoard.getLeft({0, 0, 0}).value);
    printf("100Left(200) %d\n", testBoard.getLeft({1, 0, 0}).value);
    printf("200Left(300) %d\n", testBoard.getLeft({2, 0, 0}).value);
    printf("352Left(453) %d\n", testBoard.getLeft({3, 5, 2}).value);
    printf("341Left(342) %d\n", testBoard.getLeft({3, 4, 1}).value);
    printf("241Left(250) %d\n", testBoard.getLeft({2, 4, 1}).value);
    printf("230Left(130) %d\n", testBoard.getLeft({2, 3, 0}).value);
    printf("150Left(251) %d\n", testBoard.getLeft({1, 5, 0}).value);
    printf("351Left(452) %d\n", testBoard.getLeft({3, 5, 1}).value);
    printf("340Left(341) %d\n", testBoard.getLeft({3, 4, 0}).value);

    printf("000LeftBottom(150) %d\n", testBoard.getLeftBottom({0, 0, 0}).value);
    printf("100LeftBottom(251) %d\n", testBoard.getLeftBottom({1, 0, 0}).value);
    printf("110LeftBottom(000) %d\n", testBoard.getLeftBottom({1, 1, 0}).value);
    printf("200LeftBottom(352) %d\n", testBoard.getLeftBottom({2, 0, 0}).value);
    printf("352LeftBottom(452) %d\n", testBoard.getLeftBottom({3, 5, 2}).value);
    printf("341LeftBottom(442) %d\n", testBoard.getLeftBottom({3, 4, 1}).value);
    printf("241LeftBottom(342) %d\n", testBoard.getLeftBottom({2, 4, 1}).value);
    printf("230LeftBottom(231) %d\n", testBoard.getLeftBottom({2, 3, 0}).value);
    printf("150LeftBottom(250) %d\n", testBoard.getLeftBottom({1, 5, 0}).value);
    printf("351LeftBottom(451) %d\n", testBoard.getLeftBottom({3, 5, 1}).value);
    printf("340LeftBottom(441) %d\n", testBoard.getLeftBottom({3, 4, 0}).value);

    printf("110RightBottom(000) %d\n", testBoard.getRightBottom({1, 1, 0}).value);
    printf("000RightBottom(140) %d\n", testBoard.getRightBottom({0, 0, 0}).value);
    printf("100RightBottom(150) %d\n", testBoard.getRightBottom({1, 0, 0}).value);
    printf("200RightBottom(251) %d\n", testBoard.getRightBottom({2, 0, 0}).value);
    printf("352RightBottom(351) %d\n", testBoard.getRightBottom({3, 5, 2}).value);
    printf("341RightBottom(441) %d\n", testBoard.getRightBottom({3, 4, 1}).value);
    printf("241RightBottom(341) %d\n", testBoard.getRightBottom({2, 4, 1}).value);
    printf("230RightBottom(331) %d\n", testBoard.getRightBottom({2, 3, 0}).value);
    printf("150RightBottom(241) %d\n", testBoard.getRightBottom({1, 5, 0}).value);
    printf("351RightBottom(350) %d\n", testBoard.getRightBottom({3, 5, 1}).value);
    printf("340RightBottom(440) %d\n", testBoard.getRightBottom({3, 4, 0}).value);

    board::Coordinate start = {1, 1, 0};
    board::Point current = testBoard.getRight(start);
    current = testBoard.getRightBottom(current.coordinates);
    current = testBoard.getLeftBottom(current.coordinates);
    current = testBoard.getLeft(current.coordinates);
    current = testBoard.getTopLeft(current.coordinates);
    current = testBoard.getTopRight(current.coordinates);

    auto current2 = testBoard.getRight(start);
    int value = current2.value;
    int total = value;
    while (value != -1)
    {
        current2 = testBoard.getTopRight(current2.coordinates);
        value = current2.value;
        total += current2.value;
    }
    printf("centerPoint %d\n", testBoard.setPointValue({5, 0, 0, 0}));
    printf("centerPoint %d\n", testBoard.getPointValue({0, 0, 0}));

    Score test = {0, 0, 0, 0, 0, 0};
    Score toAdd = {1, 2, 3, 4, 5, 6};

    test += toAdd;

    return;
}

