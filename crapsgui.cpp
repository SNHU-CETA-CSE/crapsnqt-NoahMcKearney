#include "crapsgui.h"
#include "die.h"
#include "ui_crapsgui.h"
#include "Player.h"
#include <iostream>

CrapsGui::CrapsGui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.currentBankValueUI->setText(QString::number(user.getBet()));
}

void CrapsGui::updateUI() {
    //    printf("Inside updateUI()\n");
    std::string die1ImageName = ":/dieImages/Resources/" + std::to_string(die1.getValue());
    std::string die2ImageName = ":/dieImages/Resources/" + std::to_string(die2.getValue());
    ui.die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
    ui.die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));

    //ui.currentBankValueUI->setText(QString::fromStdString("100"));
}

void CrapsGui::on_rollButton_clicked()
{
    int bid = ui.userBid->value();
    user.setBet(bid);



    int iDiceRoll = 0, iPreviousRoll, iNumRolls = 0;
    float fUserScore1;
    std::string sPlayAgain;
    bool bGameContinue = true, bWonGame = false;

    while (bGameContinue)
    {
        iNumRolls += 1;
        iPreviousRoll = iDiceRoll;
        if (iNumRolls == 1)
        {
            
            // Roll a 7 or 11 on first roll (Win)
            if (iDiceRoll == 7 || iDiceRoll == 11)
            {
                user.addScore(user.getBet());
                user.addGameWon();
                std::cout << "Bet: " << user.getBet() << std::endl;
                std::cout << "Score: " << user.getCurrentScore() << std::endl;
                std::cout << "You Won!" << std::endl;
                std::cout << "Wins: " << user.getCurrentWins() << std::endl;
                std::cout << "Losses: " << user.getCurrentLosses() << std::endl;
                bWonGame = true;
            }
            // Roll a 2, 3, 12 on first roll (lose)
            else if (iDiceRoll == 2 || iDiceRoll == 3 || iDiceRoll == 12)
            {
                user.subtractScore();
                user.addGameLoss();
                std::cout << "Score: " << user.getCurrentScore() << std::endl;
                std::cout << "You loss" << std::endl;
                std::cout << "Wins: " << user.getCurrentWins() << std::endl;
                std::cout << "Losses: " << user.getCurrentLosses() << std::endl;
                iNumRolls = 3;
            }
            // Roll a 4, 5, 6, 8, 9, 10 on first Roll (Roll again)
            else
            {
                std::cout << "Roll again, you rolled a " << iDiceRoll << std::endl;
            }
        }
        else if (iNumRolls == 2)
        {
            iDiceRoll = userRoll();
            if (iDiceRoll == iPreviousRoll)
            {
                switch (iDiceRoll)
                {
                case 4:
                    user.addScore((user.getBet() * 2));
                    break;
                case 5:
                    user.addScore((user.getBet() * 1.5));
                    break;
                case 6:
                    user.addScore((user.getBet() * 1.2));
                    break;
                case 8:
                    user.addScore((user.getBet() * 1.2));
                    break;
                case 9:
                    user.addScore((user.getBet() * 1.5));
                    break;
                case 10:
                    user.addScore((user.getBet() * 2));
                    break;
                default:
                    break;
                }
                user.addGameWon();
                std::cout << "Bet: " << user.getBet() << std::endl;
                std::cout << "Score: " << user.getCurrentScore() << std::endl;
                std::cout << "You Won!" << std::endl;
                std::cout << "Wins: " << user.getCurrentWins() << std::endl;
                std::cout << "Losses: " << user.getCurrentLosses() << std::endl;
            }
            else
            {
                user.subtractScore();
                user.addGameLoss();
                std::cout << "You loss" << std::endl;
                std::cout << "Score: " << user.getCurrentScore() << std::endl;
                std::cout << "Wins: " << user.getCurrentWins() << std::endl;
                std::cout << "Losses: " << user.getCurrentLosses() << std::endl;
            }
        }
        if (user.getCurrentScore() == 0)
        {
            bGameContinue = false;
            std::cout << "Game ended";
        }
        else if (iNumRolls > 2 || bWonGame == true)
        {
            std::cout << "Play Again? (\"yes\"): ";
            std::cin >> sPlayAgain;
            bGameContinue = user.playAgain(sPlayAgain);
            iNumRolls = 0;
            bWonGame = false;
            std::cout << "\n";
        }
    }
}

int userRoll()
{
    int iDieOneValue = 
    die1.setValue(iDieOneValue);

    srand(time(NULL));
    Die Die2(6, 1, 1);
    int iDieTwoValue = Die2.roll();
    Die2.setValue(iDieTwoValue);

    int iDiceNum = iDieOneValue + iDieTwoValue;
    std::cout << "Two die Added: " << iDiceNum << std::endl;

    return iDiceNum;
}


    // updateUI();
