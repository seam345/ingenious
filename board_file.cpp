//
// Created by sean on 29/10/2019.
//

#include "board_file.h"
#include <vector>



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



board::board(const int& players, bool test)
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
        ring2={
                {200, 201},
                {210, 211},
                {220, 221},
                {230, 231},
                {240, 241},
                {250, 251},
        };
        ring3={
                {300, 301, 302},
                {310, 311, 312},
                {320, 321, 322},
                {330, 331, 332},
                {340, 341, 342},
                {350, 351, 352},
        };
        ring4={
                {400, 401, 402, 403},
                {410, 411, 412, 413},
                {420, 421, 422, 423},
                {430, 431, 432, 433},
                {440, 441, 442, 443},
                {450, 451, 452, 453},
        };
        ring5={
                {500, 501, 502, 503, 504},//p
                {510, 511, 512, 513, 514},//r
                {520, 521, 522, 523, 524},//g
                {530, 531, 532, 533, 534},//b
                {540, 541, 542, 543, 544},//o
                {550, 551, 552, 553, 554},//y
        };
        ring6={
                {600, 601, 602, 603, 604, 605},
                {610, 611, 612, 613, 614, 615},
                {620, 621, 622, 623, 624, 625},
                {630, 631, 632, 633, 634, 635},
                {640, 641, 642, 643, 644, 645},
                {650, 651, 652, 653, 654, 655},
        };
        ring7={
                {700, 701, 702, 703, 704, 705, 706},
                {710, 711, 712, 713, 714, 715, 716},
                {720, 721, 722, 723, 724, 725, 726},
                {730, 731, 732, 733, 734, 735, 736},
                {740, 741, 742, 743, 744, 745, 746},
                {750, 751, 752, 753, 754, 755, 756},
        };
        state = {centerPoint, ring1, ring2, ring3, ring4, ring5, ring6, ring7};

//</editor-fold>
    } else{
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
        ring2={
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
        };
        ring3={
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0},
        };
        ring4={
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
        };
        ring5={
                {p, 0, 0, 0, 0},//p
                {r, 0, 0, 0, 0},//r
                {g, 0, 0, 0, 0},//g
                {b, 0, 0, 0, 0},//b
                {o, 0, 0, 0, 0},//o
                {y, 0, 0, 0, 0},//y
        };
        ring6={
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
        };
        ring7={
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
        };
        state = {centerPoint, ring1, ring2, ring3, ring4, ring5, ring6, ring7};

//</editor-fold>
    }
}

int board::getPointValue(int ring, int section, int position)
{
    return state[ring][section][position];
}


int board::setPointValue(int ring, int section, int position, int value)
{
    state[ring][section][position] = value;
    return state[ring][section][position];
}

std::vector<int> board::getLeft(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][0][0], 1, 0, 0};
    }


    if (section == 0)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};

    }

    if (section == 1)
    {
        if (position == 0)
        {
            return {state[ring + 1][section][ring], ring + 1, section, ring};
        } else
        {
            return {state[ring][section][position - 1], ring, section, position - 1};

        }
    }

    if (section == 2)
    {
        if (position == 0)
        {
            return {state[ring][section - 1][ring - 1], ring, section - 1, ring - 1};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};

        }
    }

    if (section == 3)
    {
        if (position == 0)
        {
            return {state[ring - 1][section][position], ring - 1, section, position};
        } else if (position + 1 == ring)
        {
            return {state[ring - 1][section + 1][0], ring - 1, section, position};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};

        }
    }

    if (section == 4)
    {
        if (position + 1 == ring)
        {
            return {state[ring][section + 1][0], ring, section + 1, 0};
        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};
        }
    }

    if (section == 5)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position + 1], ring + 1, section, position + 1};


    }
    return {-1, -1, -1, -1};
}

std::vector<int> board::getTopRight(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][2][0], 1, 2, 0};
    }


    if (section == 0)
    {
        if (position + 1 == ring)
        {
            return {state[ring][section + 1][0], ring, section + 1, 0};
        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};

        }
    }

    if (section == 1)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][1][1], ring + 1, 1, 1};
    }

    if (section == 2)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};
    }

    if (section == 3)
    {
        if (position == 0)
        {
            return {state[ring + 1][section - 1][ring], ring + 1, section - 1, ring};
        } else
        {
            return {state[ring][section][position - 1], ring, section, position - 1};
        }
    }

    if (section == 4)
    {
        if (position != 0)
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};
        } else
        {
            return {state[ring][section - 1][ring - 1], ring, section - 1, ring - 1};
        }
    }

    if (section == 5)
    {
        if (position + 1 == ring)
        {
            return {state[ring - 1][0][0], ring - 1, 0, 0};
        } else
        {
            return {state[ring - 1][section][position], ring - 1, section, position};

        }
    }
    return {-1, -1, -1, -1};
}


std::vector<int> board::getTopLeft(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][1][0], 1, 1, 0};
    }


    if (section == 0)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position + 1], ring + 1, section, position + 1};
    }

    if (section == 1)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};
    }

    if (section == 2)
    {
        if (position == 0)
        {
            return {state[ring + 1][section - 1][ring - 1], ring + 1, section - 1, position - 1};
        } else
        {
            return {state[ring][section][position], ring, section, position};
        }
    }

    if (section == 3)
    {
        if (position == 0)
        {
            return {state[ring][section - 1][ring - 1], ring, section - 1, ring - 1};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};
        }
    }

    if (section == 4)
    {
        if (position + 1 == ring)
        {
            return {state[ring - 1][section + 1][0], ring - 1, section + 1, 0};
        } else
        {
            return {state[ring - 1][section][position], ring - 1, section, position};
        }
    }

    if (section == 5)
    {
        if (position + 1 == ring)
        {
            return {state[ring][0][0], ring, 0, 0};
        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};

        }
    }
    return {-1, -1, -1, -1};
}

std::vector<int> board::getRight(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][3][0], 1, 3, 0};
    }


    if (section == 0)
    {
        if (position == 0 || position + 1 != ring) // dislike the exception i had to put in for ring 1
        {
            return {state[ring - 1][section][position], ring - 1, section, position};
        } else
        {
            return {state[ring - 1][section + 1][0], ring - 1, section + 1, 0};
        }
    }

    if (section == 1)
    {
        if (position + 1 == ring)
        {
            return {state[ring][section + 1][0], ring, section + 1, 0};
        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};

        }
    }

    if (section == 2)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position + 1], ring + 1, section, position + 1};
    }

    if (section == 3)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};
    }

    if (section == 4)
    {
        if (position == 0)
        {
            return {state[ring + 1][section - 1][ring], ring + 1, section - 1, ring};
        } else
        {
            return {state[ring][section][position - 1], ring, section, position - 1};
        }
    }

    if (section == 5)
    {
        if (position == 0)
        {
            return {state[ring][section - 1][ring - 1], ring, section - 1, ring - 1};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};

        }
    }
    return {-1, -1, -1, -1};
}

std::vector<int> board::getRightBottom(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][4][0], 1, 4, 0};
    }


    if (section == 0)
    {
        if (position == 0) // dislike the exception i had to put in for ring 1
        {
            return {state[ring][5][ring - 1], ring, 5, ring - 1};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};
        }
    }

    if (section == 1)
    {
        if (ring == 1)
        {
            return {state[0][0][0], 0, 0, 0};
        } else
        {
            return {state[ring - 1][section][position], ring - 1, section, position};
        }
    }

    if (section == 2)
    {
        if (position + 1 == ring)
        {
            return {state[ring][section + 1][0], ring, section + 1, 0};
        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};

        }
    }

    if (section == 3)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position + 1], ring + 1, section, position + 1};
    }

    if (section == 4)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};
    }

    if (section == 5)
    {
        if (position == 0)
        {
            return {state[ring + 1][section - 1][ring], ring + 1, section - 1, ring};
        } else
        {
            return {state[ring][section][position - 1], ring, section, position - 1};

        }
    }
    return {-1, -1, -1 - 1};
}

std::vector<int> board::getLeftBottom(int ring, int section, int position)
{
    if (ring == 0)
    {
        return {state[1][5][0], 1, 5, 0};
    }


    if (section == 0)
    {
        if (position == 0)
        {
            return {state[ring + 1][5][ring], ring + 1, 5, ring};
        } else
        {
            return {state[ring][section][position - 1], ring, section, position - 1};
        }
    }

    if (section == 1)
    {
        if (position == 0)
        {
            return {state[ring][section - 1][ring - 1], ring, section - 1, ring - 1};
        } else
        {
            return {state[ring - 1][section][position - 1], ring - 1, section, position - 1};

        }
    }

    if (section == 2)
    {
        if (position + 1 == ring)
        {
            return {state[ring - 1][section + 1][0], ring - 1, section + 1, 0};
        } else
        {
            return {state[ring - 1][section][position], ring - 1, section, position};
        }
    }

    if (section == 3)
    {
        if (position + 1 == ring)
        {
            return {state[ring][section + 1][0], ring, section + 1, 0};

        } else
        {
            return {state[ring][section][position + 1], ring, section, position + 1};

        }

    }

    if (section == 4)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position + 1], ring + 1, section, position + 1};
    }

    if (section == 5)
    {
        if (ring == 7)
        {
            return {-1, -1, -1, -1};
        }
        return {state[ring + 1][section][position], ring + 1, section, position};
    }
    return {-1, -1, -1, -1};
}





