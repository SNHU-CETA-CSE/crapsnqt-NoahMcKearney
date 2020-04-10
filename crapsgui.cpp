#include "crapsgui.h"
#include "die.h"
#include "ui_crapsgui.h"
#include "Player.h"
#include <iostream>

int userRoll();

CrapsGui::CrapsGui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.currentBankValueUI->setText("1000");
}

// Constructors for Player and Die class
Player user1(1000);
Die die1, die2;
int iNumRolls = 1;

// Updates ui...
void CrapsGui::updateUI(bool bWonGame) {

    if (bWonGame == true)
    {
        user1.addGameWon();
    }
    else {
        user1.addGameLoss();
    }
    
    ui.rollButton->setText("Roll Dice");
    ui.currentBankValueUI->setText(QString::number(user1.getCurrentScore()));
    ui.winLabel->setText(QString::number(user1.getCurrentWins()));
    ui.lossLabel->setText(QString::number(user1.getCurrentLosses()));
    iNumRolls = 1;
}

void CrapsGui::on_rollButton_clicked()
{
    QString bid = ui.userBid->text();
    user1.setBet(bid.toFloat());

    int iDiceRollTotal = 0, iPreviousRoll;
    float fUserScore1;
    std::string sPlayAgain;
    bool bGameContinue = true, bWonGame = false;
    
    // Rolled the die once:
    if (iNumRolls == 1)
    {
        // Gets the total of the two die:
        iPreviousRoll = userRoll();
        std::string die1ImageName = "dieImages/" + std::to_string(die1.getValue());
        std::string die2ImageName = "dieImages/" + std::to_string(die2.getValue());
        ui.die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
        ui.die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));
        ui.outputLabel->setText("Rolled a "  + QString::number(iPreviousRoll));

        // Roll a 7 or 11 on first roll (Win)
        if (iDiceRollTotal == 7 || iDiceRollTotal == 11)
        {
            ui.outputLabel2->setText("You won!");
            user1.addScore(user1.getBet());
            updateUI(true);
        }
        // Roll a 2, 3, 12 on first roll (lose)
        else if (iDiceRollTotal == 2 || iDiceRollTotal == 3 || iDiceRollTotal == 12)
        {
            user1.subtractScore();
            ui.currentBankValueUI->setText(QString::number(user1.getCurrentScore()));
            ui.outputLabel2->setText("You loss!");
            updateUI(false);
        }
        // Roll a 4, 5, 6, 8, 9, 10 on first Roll (Roll again)
        else
        {               
            ui.rollButton->setText("Roll again");
            iNumRolls += 1;
        }
        ui.outputLabel2->setText("Rolling for a " + QString::number(iPreviousRoll));
    }
    else if (iNumRolls == 2)
    {
        // Gets the die total:
        iDiceRollTotal = userRoll();
        std::string die1ImageName = "dieImages/" + std::to_string(die1.getValue());
        std::string die2ImageName = "dieImages/" + std::to_string(die2.getValue());
        ui.die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
        ui.die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));

        if (iDiceRollTotal == iPreviousRoll)
        {
            switch (iDiceRollTotal)
            {
            case 4:
                user1.addScore((user1.getBet() * 2));
                break;
            case 5:
                user1.addScore((user1.getBet() * 1.5));
                break;
            case 6:
                user1.addScore((user1.getBet() * 1.2));
                break;
            case 8:
                user1.addScore((user1.getBet() * 1.2));
                break;
            case 9:
                user1.addScore((user1.getBet() * 1.5));
                break;
            case 10:
                user1.addScore((user1.getBet() * 2));
                break;
            default:
                break;
            }
            ui.winLabel->setText(QString::number(user1.getCurrentWins()));
            ui.outputLabel->setText("Rolled a " + QString::number(iDiceRollTotal));
            ui.outputLabel2->setText("You won!");
            updateUI(true);
        }
        else
        {
            user1.subtractScore();
            ui.outputLabel->setText("Rolled a " + QString::number(iDiceRollTotal));
            ui.outputLabel2->setText("You loss!");
            updateUI(false);
        }
    }
    // Game ends
    if (user1.getCurrentScore() <= 0)
    {
        bGameContinue = false;
        ui.rollButton->setEnabled(false);
        ui.outputLabel3->setText("Game ended");
    }
}

// Adds die together
int userRoll()
{
    int iDieOneValue = die1.roll();
    die1.setValue(iDieOneValue);

    srand(time(NULL));
    int iDieTwoValue = die2.roll();
    die2.setValue(iDieTwoValue);

    int iDiceNum = iDieOneValue + iDieTwoValue;

    return iDiceNum;
}