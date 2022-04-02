#include "command.h"
#include "board.h"
#include "cell.h"
#include "block.h"
#include "difficulty.h"
#include "textoutput.h"


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    //? Board Varibles
    Command cmd;
    
    int hi_score = 0;
    int width = 11;
    int height = 18;
    int player = 1;
    int ini_level = 0;
    

    bool graphicsMode = true; //? Default: with both graphic output and text output


    //? Command-line interface if exists
    for (int i = 0; i < argc; ++i) {
        string cmd_arg = argv[i];
        if (cmd_arg == "-text") {
            graphicsMode = false;
        } 
        if (cmd_arg == "-seed") {
            // Left to add
        }
        if (cmd_arg == "scriptfile1") {
            // set player1 to file
        } 
        if (cmd_arg == "scriptfile2") {
            // set player2 to file;
        } 
        if (cmd_arg == "-startlevel") {
            string xxx = argv[i + 1];
            ini_level = stoi(xxx);
            i++;
        }

    }
    
    

    //? Initialize two boards
    Board *b1 = new Board{width, height, ini_level};
    Board *b2 = new Board{width, height, ini_level};
    TextOutput t{11 , 18, b1, b2};


    Difficulty *curBlock1 = b1->generateNewBlock('L', 4);
    Difficulty *curBlock2 = b2->generateNewBlock('L', 2);
    // Block* currentBlock = new JBlock(b1->getCell(0, 3), b1->getCell(0, 4), b1->getCell(1, 4), b1->getCell(2, 4));
    
    //b1->spin(currentBlock, true);

    //b1->move(-1, 0, 2, curBlock1);

    //? For textoutput and graphicsoutput
    
    cout << t;
    // Initialize boards with other setting

    cout << curBlock1->getWeight() << endl;
    cout << curBlock2->getWeight() << endl;

    string cmdin;
    //! Game
    while (cin >> cmdin) {

        bool restart = false;
        bool touch = false;
        // Two players turn
        Board *cur_play = (player == 1) ? b1 : b2;
        Block *curBlock = (player == 1) ? curBlock1 : curBlock2;
        // With input

        // Special Action
        string intput;

        

        if (cmdin == "rename") {
            string old, cur;
            cin >> old;
            cin >> cur;
            cmd.short_com(old, cur);
        }

        if (cmdin == "left") {
            if (!touch) {
                cur_play->move(-1, 0, curBlock, curBlock1);
            }
        }

        if (cmdin == "right") {
            if (!touch) {
                cur_play->move(1, 0, curBlock, curBlock1);
            }
        }

        if (cmdin == "down") {
            if (!touch) {
                cur_play->move(0, 1, curBlock->getWeight, curBlock)
            }
        }
        
        if (cmdin == "clockwise") {

        }

        if (cmdin == "counterclockwise") {

        }

        if (cmdin == "drop") {

        }

        if (cmdin == "levelup") {
            // int cur_level = cur_play->getLevel();
            // if (cur_level < 4) {
            //     cur_level += 1;
            // }
            // cur_play->setLevel(cur_level);
        }

        if (cmdin == "leveldown") { 
            // int cur_level = cur_play->getLevel();
            // if (cur_level > 0) {
            //     cur_level -= 1;
            // }
            // cur_play->setLevel(cur_level);
            // cout << t;
        }

        if (cmdin == "norandom") {
            
        }

        if (cmdin == "random") {
            
        }

        if (cmdin == "sequence") {
            
        }

        //! For Block create with Block name


        if (cmdin == "restart") {
            restart = true;

        }


    }


}
