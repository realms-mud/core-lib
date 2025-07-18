//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object BankSelector;

///////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages", "getMenuOptionNumber",
        "bankSelectorRemoved", "onSelectorCompleted", "onSelectorAborted" });
}

///////////////////////////////////////////////////////////////////////////////
public void onSelectorCompleted(object caller)
{
    if (objectp(caller))
    {
        caller->cleanUp();
    }
}

///////////////////////////////////////////////////////////////////////////////
public void onSelectorAborted(object caller)
{
    if (objectp(caller))
    {
        caller->cleanUp();
    }
}

///////////////////////////////////////////////////////////////////////////////
void Setup()
{
    BankSelector = clone_object("/lib/modules/domains/trading/selectors/bankSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testbanker");
    Player.addCommands();
    Player.initializeTrader();
    Player.addVehicle("wagon", "eledhel");

    move_object(BankSelector, Player);
    BankSelector->registerEvent(this_object());
}

///////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(BankSelector))
    {
        destruct(BankSelector);
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
}

///////////////////////////////////////////////////////////////////////////////
private void resetPlayerMessages()
{
    if (Player && function_exists("resetCatchList", Player))
    {
        Player.resetCatchList();
    }
}

///////////////////////////////////////////////////////////////////////////////
private string getMenuOptionNumber(string optionText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);

        if (sizeof(regexp(({ line }), optionText)))
        {
            ret = regreplace(line, "^.*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////
private int bankSelectorRemoved()
{
    object *inventory = deep_inventory(Player);

    int found = 0;
    foreach(object obj in inventory)
    {
        if (obj == BankSelector)
        {
            found = 1;
            break;
        }
    }
    return !found;
}

///////////////////////////////////////////////////////////////////////////////
void BankSelectorDisplaysMainMenuCorrectly()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Banking Services", message);
    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingStatusDisplaysAccountInformation()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(200);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Bank Account", message);
    ExpectSubStringMatch("Cash on Hand", message);
    ExpectSubStringMatch("Bank Balance", message);
    ExpectSubStringMatch("Outstanding Debt", message);
    ExpectSubStringMatch("Net Worth", message);
    ExpectSubStringMatch("Loan Capacity", message);
    ExpectSubStringMatch("Interest Rates", message);
}

///////////////////////////////////////////////////////////////////////////////
void NoColorsWithASCIIDisplaysCorrectly()
{
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");

    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(200);      // 200 cash, 200 bank

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = Player.caughtMessages()[2];
    string expected = 
        "+-=-=-=-=-=-=-=-=-=-+ Unnamed Trading Company Bank Account +=-=-=-=-=-=-=-=-=-+\n"
        "| Cash on Hand:     200 gold          Bank Balance:     200 gold              |\n"
        "| Outstanding Debt: 5000 gold         Net Worth:        -4600 gold            |\n"
        "| Loan Capacity:    400 gold  (based on current cash holdings)                |\n"
        "| Interest Rates:   Bank deposits +0.5% monthly, Loans +10% monthly           |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";

    ExpectEq(expected, message);
}

///////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorWithUnicodeDisplaysCorrectly()
{
    Player.colorConfiguration("24-bit");
    Player.charsetConfiguration("unicode");

    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(200);      // 200 cash, 200 bank

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = Player.caughtMessages()[2];
    string expected =
        "\x1b[0;38;2;160;10;0m\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Unnamed Trading Company Bank Account \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m\u2551\x1b[0m \x1b[0;38;2;180;180;190mCash on Hand:     \x1b[0m\x1b[0;38;2;200;200;0m200 gold          \x1b[0m\x1b[0;38;2;180;180;190mBank Balance:     \x1b[0m\x1b[0;38;2;200;200;0m200 gold          \x1b[0m    \x1b[0;38;2;160;10;0m\u2551\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m\u2551\x1b[0m \x1b[0;38;2;180;180;190mOutstanding Debt: \x1b[0m\x1b[0;38;2;200;0;0m5000 gold         \x1b[0m\x1b[0;38;2;180;180;190mNet Worth:        \x1b[0m\x1b[0;38;2;200;0;0m-4600 gold        \x1b[0m    \x1b[0;38;2;160;10;0m\u2551\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m\u2551\x1b[0m \x1b[0;38;2;180;180;190mLoan Capacity:    \x1b[0m\x1b[0;38;2;200;200;0m400 gold  \x1b[0m\x1b[0;38;2;80;155;175m(based on current cash holdings)\x1b[0m                \x1b[0;38;2;160;10;0m\u2551\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m\u2551\x1b[0m \x1b[0;38;2;180;180;190mInterest Rates:   \x1b[0m\x1b[0;38;2;100;180;150mBank deposits +0.5% monthly, Loans +10% monthly\x1b[0m           \x1b[0;38;2;160;10;0m\u2551\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 \u2550 \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n";

    string *expByLine = explode(expected, "\n");
    string *msgByLine = explode(message, "\n");

    // Check each line of the message
    ExpectEq(expByLine[0], msgByLine[0]);
    ExpectEq(expByLine[1], msgByLine[1]);
    ExpectEq(expByLine[2], msgByLine[2]);
    ExpectEq(expByLine[3], msgByLine[3]);
    ExpectEq(expByLine[4], msgByLine[4]);
    ExpectEq(expByLine[5], msgByLine[5]);
}

///////////////////////////////////////////////////////////////////////////////
void DepositOptionShowsWhenPlayerHasCash()
{
    Player.setupStartingChoice(1); // 400 cash

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Deposit Money", message);
    ExpectSubStringMatch("(You have 400 gold)", message);
}

///////////////////////////////////////////////////////////////////////////////
void DepositOptionDoesNotShowWhenPlayerHasNoCash()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Deposit Money")) > 0,
        "Deposit option should not show when player has no cash");
}

///////////////////////////////////////////////////////////////////////////////
void WithdrawOptionShowsWhenPlayerHasBankBalance()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(300);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Withdraw Money", message);
    ExpectSubStringMatch("(Bank: 300 gold)", message);
}

///////////////////////////////////////////////////////////////////////////////
void WithdrawOptionDoesNotShowWhenPlayerHasNoBankBalance()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Withdraw Money")) > 0,
        "Withdraw option should not show when player has no bank balance");
}

///////////////////////////////////////////////////////////////////////////////
void LoanOptionShowsWhenPlayerIsEligible()
{
    Player.setupStartingChoice(1); // 400 cash

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Apply for Loan", message);
    ExpectSubStringMatch("(Eligible for 800 gold)", message);
}

///////////////////////////////////////////////////////////////////////////////
void LoanOptionDoesNotShowWhenPlayerNotEligible()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Apply for Loan")) > 0,
        "Loan option should not show when player has no cash");
}

///////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionShowsWhenPlayerHasDebt()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Repay Debt", message);
    ExpectSubStringMatch("(Owe 5000 gold)", message);
}

///////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionDoesNotShowWhenPlayerHasNoDebt()
{
    Player.setupStartingChoice(2); // 0 cash, 0 debt

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay debt option should not show when player has no debt");
}

///////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionDoesNotShowWhenPlayerCannotAfford()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.addCash(-400);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay debt option should not show when player cannot afford any payment");
}

///////////////////////////////////////////////////////////////////////////////
void DepositTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    int depositOption = to_int(getMenuOptionNumber("Deposit Money"));
    if (depositOption > 0)
    {
        resetPlayerMessages();
        command(to_string(depositOption), Player);
        string transactionMessage = Player.caughtMessage();

        ExpectSubStringMatch("Deposit Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to deposit", transactionMessage);
    }
}

///////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(200);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    int withdrawOption = to_int(getMenuOptionNumber("Withdraw Money"));
    if (withdrawOption > 0)
    {
        resetPlayerMessages();
        command(to_string(withdrawOption), Player);
        string transactionMessage = Player.caughtMessage();

        ExpectSubStringMatch("Withdraw Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to withdraw", transactionMessage);
    }
}

///////////////////////////////////////////////////////////////////////////////
void BorrowTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    int loanOption = to_int(getMenuOptionNumber("Apply for Loan"));
    if (loanOption > 0)
    {
        resetPlayerMessages();
        command(to_string(loanOption), Player);
        string transactionMessage = Player.caughtMessage();

        ExpectSubStringMatch("Borrow Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to borrow", transactionMessage);
    }
}

///////////////////////////////////////////////////////////////////////////////
void RepayTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    int repayOption = to_int(getMenuOptionNumber("Repay Debt"));
    if (repayOption > 0)
    {
        resetPlayerMessages();
        command(to_string(repayOption), Player);
        string transactionMessage = Player.caughtMessage();

        ExpectSubStringMatch("Repay Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to repay", transactionMessage);
    }
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingExitExitsSelector()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    ExpectFalse(bankSelectorRemoved(),
        "Selector should be present before exit command");

    command(getMenuOptionNumber("Return to Trading Menu"), Player);

    ExpectSubStringMatch("You have selected 'Return to Trading Menu'",
        Player.caughtMessage());

    ExpectTrue(bankSelectorRemoved(),
        "Selector should be removed from player after exit command");
}

///////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Banking Services", Player.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsDetails()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Display your current cash", Player.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInBankSelector()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

///////////////////////////////////////////////////////////////////////////////
void NetWorthCalculatedCorrectlyWithPositiveValue()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(100);      // 300 cash, 100 bank, 5000 debt = -4600 net worth
    Player.addCash(5000);          // 5300 cash, 100 bank, 5000 debt = 400 net worth

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = Player.caughtMessages()[2];

    ExpectSubStringMatch("Net Worth", message);
    ExpectTrue(sizeof(regexp(({ message }), "400 gold")) > 0,
        "Should display the correct net worth");
}

///////////////////////////////////////////////////////////////////////////////
void NetWorthCalculatedCorrectlyWithNegativeValue()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt = -4600 net worth

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = Player.caughtMessages()[2];

    ExpectSubStringMatch("Net Worth", message);
    ExpectTrue(sizeof(regexp(({ message }), "-4600 gold")) > 0,
        "Should display the correct negative net worth");
}

///////////////////////////////////////////////////////////////////////////////
void LoanCapacityBasedOnCurrentCash()
{
    Player.setupStartingChoice(1); // 400 cash
    Player.addCash(100);          // 500 cash = 1000 loan capacity

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Account Status"), Player);

    string message = Player.caughtMessages()[2];

    ExpectSubStringMatch("Loan Capacity", message);
    ExpectTrue(sizeof(regexp(({ message }), "1000 gold")) > 0,
        "Should display correct loan capacity (2x cash)");
}

///////////////////////////////////////////////////////////////////////////////
void AllBankingOptionsShowWhenPlayerHasFullFinancialProfile()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(100);      // 300 cash, 100 bank, 5000 debt

    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();

    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Deposit Money", message);
    ExpectSubStringMatch("Withdraw Money", message);
    ExpectSubStringMatch("Apply for Loan", message);
    ExpectSubStringMatch("Repay Debt", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

///////////////////////////////////////////////////////////////////////////////
void BankSelectorHandlesEmptyFinancialState()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();

    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Return to Trading Menu", message);

    ExpectFalse(sizeof(regexp(({ message }), "Deposit Money")) > 0,
        "Deposit should not be available with no cash");
    ExpectFalse(sizeof(regexp(({ message }), "Withdraw Money")) > 0,
        "Withdraw should not be available with no bank balance");
    ExpectFalse(sizeof(regexp(({ message }), "Apply for Loan")) > 0,
        "Loan should not be available with no cash");
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay should not be available with no debt");
}
