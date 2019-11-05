//
// Created by sean on 29/10/2019.
//

#include "board_file.h"
#include <vector>


board::board(const int &players, bool test)
{
    if (test)
    {
        //<editor-fold desc="training state">
        centerPoint = {{000}};
        ring1 = {
                {100},
                {110},
                {120},
                {130},
                {140},
                {150},
        };
        ring2 = {
                {200, 201},
                {210, 211},
                {220, 221},
                {230, 231},
                {240, 241},
                {250, 251},
        };
        ring3 = {
                {300, 301, 302},
                {310, 311, 312},
                {320, 321, 322},
                {330, 331, 332},
                {340, 341, 342},
                {350, 351, 352},
        };
        ring4 = {
                {400, 401, 402, 403},
                {410, 411, 412, 413},
                {420, 421, 422, 423},
                {430, 431, 432, 433},
                {440, 441, 442, 443},
                {450, 451, 452, 453},
        };
        ring5 = {
                {500, 501, 502, 503, 504},//p
                {510, 511, 512, 513, 514},//r
                {520, 521, 522, 523, 524},//g
                {530, 531, 532, 533, 534},//b
                {540, 541, 542, 543, 544},//o
                {550, 551, 552, 553, 554},//y
        };
        ring6 = {
                {600, 601, 602, 603, 604, 605},
                {610, 611, 612, 613, 614, 615},
                {620, 621, 622, 623, 624, 625},
                {630, 631, 632, 633, 634, 635},
                {640, 641, 642, 643, 644, 645},
                {650, 651, 652, 653, 654, 655},
        };
        ring7 = {
                {700, 701, 702, 703, 704, 705, 706},
                {710, 711, 712, 713, 714, 715, 716},
                {720, 721, 722, 723, 724, 725, 726},
                {730, 731, 732, 733, 734, 735, 736},
                {740, 741, 742, 743, 744, 745, 746},
                {750, 751, 752, 753, 754, 755, 756},
        };
        state = {centerPoint, ring1, ring2, ring3, ring4, ring5, ring6, ring7};

//</editor-fold>
    } else
    {
        //<editor-fold desc="fresh board">
        centerPoint = {{0}};
        ring1 = {
                {0},
                {0},
                {0},
                {0},
                {0},
                {0},
        };
        ring2 = {
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
        };
        ring3 = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
        };
        ring4 = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
        };
        ring5 = {
                {p, 0, 0, 0, 0},//p
                {r, 0, 0, 0, 0},//r
                {g, 0, 0, 0, 0},//g
                {b, 0, 0, 0, 0},//b
                {o, 0, 0, 0, 0},//o
                {y, 0, 0, 0, 0},//y
        };
        if (players < 3)
        {
            ring6 = {
                    {-1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1},
            };
        } else
        {
            ring6 = {
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
            };
        }
        if (players < 4)
        {
            ring7 = {
                    {-1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1, -1, -1},
            };
        } else
        {
            ring7 = {
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
            };
        }
        state = {centerPoint, ring1, ring2, ring3, ring4, ring5, ring6, ring7};

//</editor-fold>
    }
}

int board::getPointValue(Coordinate coordinates)
{
    return state[coordinates.ring][coordinates.section][coordinates.position];
}


int board::setPointValue(Point point)
{
    state[point.coordinates.ring][point.coordinates.section][point.coordinates.position] = point.value;
    return state[point.coordinates.ring][point.coordinates.section][point.coordinates.position];
}

board::Point board::getLeft(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][0][0], 1, 0, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};

    }

    if (coordinates.section == 1)
    {
        if (coordinates.position == 0)
        {
            if (coordinates.ring == 7)
            {
                return {-1, -1, -1, -1};
            }
            return {state[coordinates.ring + 1][coordinates.section][coordinates.ring], coordinates.ring + 1,
                    coordinates.section, coordinates.ring};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};

        }
    }

    if (coordinates.section == 2)
    {
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring][coordinates.section - 1][coordinates.ring - 1], coordinates.ring,
                    coordinates.section - 1, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};

        }
    }

    if (coordinates.section == 3)
    {
        if (coordinates.ring == 1)
        {
            return {state[0][0][0], 0, 0, 0};
        }
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};
        } else if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring - 1][coordinates.section + 1][0], coordinates.ring - 1, coordinates.section,
                    coordinates.position};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};

        }
    }

    if (coordinates.section == 4)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][coordinates.section + 1][0], coordinates.ring, coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};
        }
    }

    if (coordinates.section == 5)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position + 1], coordinates.ring + 1,
                coordinates.section, coordinates.position + 1};


    }
    return {-1, -1, -1, -1};
}

board::Point board::getTopRight(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][2][0], 1, 2, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][coordinates.section + 1][0], coordinates.ring, coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};

        }
    }

    if (coordinates.section == 1)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }

        return {state[coordinates.ring + 1][coordinates.section][coordinates.position+1], coordinates.ring + 1, coordinates.section, coordinates.position+1};
    }

    if (coordinates.section == 2)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};
    }

    if (coordinates.section == 3)
    {
        if (coordinates.position == 0)
        {
            if (coordinates.ring == 7)
            {
                return {-1, -1, -1, -1};
            }
            return {state[coordinates.ring + 1][coordinates.section - 1][coordinates.ring], coordinates.ring + 1,
                    coordinates.section - 1, coordinates.ring};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 4)
    {
        if (coordinates.position != 0)
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};
        } else
        {
            return {state[coordinates.ring][coordinates.section - 1][coordinates.ring - 1], coordinates.ring,
                    coordinates.section - 1, coordinates.ring - 1};
        }
    }

    if (coordinates.section == 5)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring - 1][0][0], coordinates.ring - 1, 0, 0};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};

        }
    }
    return {-1, -1, -1, -1};
}

board::Point board::getTopLeft(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][1][0], 1, 1, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position + 1], coordinates.ring + 1,
                coordinates.section, coordinates.position + 1};
    }

    if (coordinates.section == 1)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};
    }

    if (coordinates.section == 2)
    {
        if (coordinates.position == 0)
        {
            if (coordinates.ring == 7)
            {
                return {-1, -1, -1, -1};
            }
            return {state[coordinates.ring + 1][coordinates.section - 1][coordinates.ring - 1], coordinates.ring + 1,
                    coordinates.section - 1, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 3)
    {
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring][coordinates.section - 1][coordinates.ring - 1], coordinates.ring,
                    coordinates.section - 1, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 4)
    {
        if (coordinates.ring == 1)
        {
            return {state[0][0][0], 0, 0, 0};
        }
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring - 1][coordinates.section + 1][0], coordinates.ring - 1,
                    coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};
        }
    }

    if (coordinates.section == 5)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][0][0], coordinates.ring, 0, 0};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};

        }
    }
    return {-1, -1, -1, -1};
}

board::Point board::getRight(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][3][0], 1, 3, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.position == 0 || coordinates.position + 1 !=
                                         coordinates.ring) // dislike the exception i had to put in for coordinates.ring 1
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section + 1][0], coordinates.ring - 1,
                    coordinates.section + 1, 0};
        }
    }

    if (coordinates.section == 1)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][coordinates.section + 1][0], coordinates.ring, coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};

        }
    }

    if (coordinates.section == 2)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position + 1], coordinates.ring + 1,
                coordinates.section, coordinates.position + 1};
    }

    if (coordinates.section == 3)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};
    }

    if (coordinates.section == 4)
    {
        if (coordinates.position == 0)
        {
            if (coordinates.ring == 7)
            {
                return {-1, -1, -1, -1};
            }
            return {state[coordinates.ring + 1][coordinates.section - 1][coordinates.ring], coordinates.ring + 1,
                    coordinates.section - 1, coordinates.ring};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 5)
    {
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring][coordinates.section - 1][coordinates.ring - 1], coordinates.ring,
                    coordinates.section - 1, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};

        }
    }
    return {-1, -1, -1, -1};
}

board::Point board::getRightBottom(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][4][0], 1, 4, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.position == 0) // dislike the exception i had to put in for coordinates.ring 1
        {
            return {state[coordinates.ring][5][coordinates.ring - 1], coordinates.ring, 5, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 1)
    {
        if (coordinates.ring == 1)
        {
            return {state[0][0][0], 0, 0, 0};
        } else if (coordinates.position +1 == coordinates.ring)
        {
            return {state[coordinates.ring - 1][coordinates.section + 1 ][0], coordinates.ring - 1,
                    coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};
        }
    }

    if (coordinates.section == 2)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][coordinates.section + 1][0], coordinates.ring, coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};

        }
    }

    if (coordinates.section == 3)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position + 1], coordinates.ring + 1,
                coordinates.section, coordinates.position + 1};
    }

    if (coordinates.section == 4)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};
    }

    if (coordinates.section == 5)
    {
        if (coordinates.position == 0)
        {
            if (coordinates.ring == 7)
            {
                return {-1, -1, -1, -1};
            }
            return {state[coordinates.ring + 1][coordinates.section - 1][coordinates.ring], coordinates.ring + 1,
                    coordinates.section - 1, coordinates.ring};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};

        }
    }
    return {-1, -1, -1 - 1};
}

board::Point board::getLeftBottom(Coordinate coordinates)
{
    if (coordinates.ring == 0)
    {
        return {state[1][5][0], 1, 5, 0};
    }


    if (coordinates.section == 0)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring + 1][5][coordinates.ring], coordinates.ring + 1, 5, coordinates.ring};
        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position - 1], coordinates.ring,
                    coordinates.section, coordinates.position - 1};
        }
    }

    if (coordinates.section == 1)
    {
        if (coordinates.position == 0)
        {
            return {state[coordinates.ring][coordinates.section - 1][coordinates.ring - 1], coordinates.ring,
                    coordinates.section - 1, coordinates.ring - 1};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position - 1], coordinates.ring - 1,
                    coordinates.section, coordinates.position - 1};

        }
    }

    if (coordinates.section == 2)
    {
        if (coordinates.ring == 1)
        {
            return {state[0][0][0], 0, 0, 0};
        }
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring - 1][coordinates.section + 1][0], coordinates.ring - 1,
                    coordinates.section + 1, 0};
        } else
        {
            return {state[coordinates.ring - 1][coordinates.section][coordinates.position], coordinates.ring - 1,
                    coordinates.section, coordinates.position};
        }
    }

    if (coordinates.section == 3)
    {
        if (coordinates.position + 1 == coordinates.ring)
        {
            return {state[coordinates.ring][coordinates.section + 1][0], coordinates.ring, coordinates.section + 1, 0};

        } else
        {
            return {state[coordinates.ring][coordinates.section][coordinates.position + 1], coordinates.ring,
                    coordinates.section, coordinates.position + 1};

        }

    }

    if (coordinates.section == 4)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position + 1], coordinates.ring + 1,
                coordinates.section, coordinates.position + 1};
    }

    if (coordinates.section == 5)
    {
        if (coordinates.ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[coordinates.ring + 1][coordinates.section][coordinates.position], coordinates.ring + 1,
                coordinates.section, coordinates.position};
    }
    return {-1, -1, -1, -1};
}

Score tileValueToScore(int value)
{
    Score score = {0, 0, 0, 0, 0, 0};
    switch (value)
    {
        case 1:
            score.red12pointedStar = 1;
            break;
        case 2:
            score.greenCircle = 1;
            break;
        case 3:
            score.blue6PointedStar = 1;
            break;
        case 4:
            score.orangeHexagon = 1;
            break;
        case 5:
            score.yellow24PointedStar = 1;
            break;
        case 6:
            score.purpleRing = 1;
            break;
    }

    return score;

}

Score board::getScoreForPosition(board::Point tilePoint1)
{
    Score score = {0, 0, 0, 0, 0, 0};

    Point leftPoint = getLeft(tilePoint1.coordinates);
    while (leftPoint.value != -1 && leftPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(leftPoint.value);
        leftPoint = getLeft(leftPoint.coordinates);
    }

    Point leftUpPoint = getTopLeft(tilePoint1.coordinates);
    while (leftUpPoint.value != -1 && leftUpPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(leftUpPoint.value);
        leftUpPoint = getTopLeft(leftUpPoint.coordinates);
    }

    Point RightUpPoint = getTopRight(tilePoint1.coordinates);
    while (RightUpPoint.value != -1 && RightUpPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(RightUpPoint.value);
        RightUpPoint = getTopRight(RightUpPoint.coordinates);
    }

    Point rightPoint = getRight(tilePoint1.coordinates);
    while (rightPoint.value != -1 && rightPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(rightPoint.value);
        rightPoint = getRight(rightPoint.coordinates);
    }

    Point rightDownPoint = getRightBottom(tilePoint1.coordinates);
    while (rightDownPoint.value != -1 && rightDownPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(rightDownPoint.value);
        rightDownPoint = getRightBottom(rightDownPoint.coordinates);
    }

    Point leftDownPoint = getLeftBottom(tilePoint1.coordinates);
    while (leftDownPoint.value != -1 && leftDownPoint.value == tilePoint1.value)
    {
        score += tileValueToScore(leftDownPoint.value);
        leftDownPoint = getLeftBottom(leftDownPoint.coordinates);
    }


    return score;


}

Score board::placeTile(board::Point tilePoint1, board::Point tilePoint2)
{
    if (getPointValue(tilePoint1.coordinates) != 0 ||
        getPointValue(tilePoint2.coordinates) != 0)
    { //invalid move
        return {-1, -1, -1, -1, -1, -1};
    }

    Score score = {0, 0, 0, 0, 0, 0};


    score += getScoreForPosition(tilePoint1);
    score += getScoreForPosition(tilePoint2);



    // add tile to board
    setPointValue(tilePoint1);
    setPointValue(tilePoint2);

    return score;
}

Score board::checkTile(board::Point tilePoint1, board::Point tilePoint2)
{
    if (getPointValue(tilePoint1.coordinates) != 0 ||
        getPointValue(tilePoint2.coordinates) != 0)
    { //invalid move
        return {-1, -1, -1, -1, -1, -1};
    }

    Score score = {0, 0, 0, 0, 0, 0};


    score += getScoreForPosition(tilePoint1);
    score += getScoreForPosition(tilePoint2);


    return score;
}

// todo add limit
void operator+=(Score &lhs, const Score &rhs)
{
    lhs.red12pointedStar += rhs.red12pointedStar;
    if (lhs.red12pointedStar > 18) lhs.red12pointedStar = 18;
    lhs.greenCircle += rhs.greenCircle;
    if (lhs.greenCircle > 18) lhs.greenCircle = 18;
    lhs.blue6PointedStar += rhs.blue6PointedStar;
    if (lhs.blue6PointedStar > 18) lhs.blue6PointedStar = 18;
    lhs.orangeHexagon += rhs.orangeHexagon;
    if (lhs.orangeHexagon > 18) lhs.orangeHexagon = 18;
    lhs.yellow24PointedStar += rhs.yellow24PointedStar;
    if (lhs.yellow24PointedStar > 18) lhs.yellow24PointedStar = 18;
    lhs.purpleRing += rhs.purpleRing;
    if (lhs.purpleRing > 18) lhs.purpleRing = 18;

}


bool operator>(const Score &lhs, const Score &rhs)
{
    int maxScore = 18;
    int rhScore = 0;
    rhScore += maxScore - rhs.purpleRing;
    rhScore += maxScore - rhs.yellow24PointedStar;
    rhScore += maxScore - rhs.red12pointedStar;
    rhScore += maxScore - rhs.blue6PointedStar;
    rhScore += maxScore - rhs.greenCircle;
    rhScore += maxScore - rhs.orangeHexagon;
    int lhScore = 0;
    lhScore += maxScore - lhs.purpleRing;
    lhScore += maxScore - lhs.yellow24PointedStar;
    lhScore += maxScore - lhs.red12pointedStar;
    lhScore += maxScore - lhs.blue6PointedStar;
    lhScore += maxScore - lhs.greenCircle;
    lhScore += maxScore - lhs.orangeHexagon;

    // operator reversed because lower score is better
    return lhScore < rhScore;
}

bool operator<(const Score &lhs, const Score &rhs)
{
    return rhs > lhs;
}

Score operator+(const Score &lhs, const Score &rhs)
{
    Score result = {0, 0, 0, 0, 0, 0};
    result.red12pointedStar = lhs.red12pointedStar + rhs.red12pointedStar;
    if (result.red12pointedStar > 18) result.red12pointedStar = 18;
    result.greenCircle = lhs.greenCircle + rhs.greenCircle;
    if (result.greenCircle > 18) result.greenCircle = 18;
    result.blue6PointedStar = lhs.blue6PointedStar + rhs.blue6PointedStar;
    if (result.blue6PointedStar > 18) result.blue6PointedStar = 18;
    result.orangeHexagon = lhs.orangeHexagon + rhs.orangeHexagon;
    if (result.orangeHexagon > 18) result.orangeHexagon = 18;
    result.yellow24PointedStar = lhs.yellow24PointedStar + rhs.yellow24PointedStar;
    if (result.yellow24PointedStar > 18) result.yellow24PointedStar = 18;
    result.purpleRing = lhs.purpleRing + rhs.purpleRing;
    if (result.purpleRing > 18) result.purpleRing = 18;

    return result;
}
