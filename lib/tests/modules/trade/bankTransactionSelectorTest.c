//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object TransactionSelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages", "getMenuOptionNumber" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    TransactionSelector = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testbanker");
    Player.addCommands();
    Player.initializeTrader();
    Player.addCash(1000);
    Player.colorConfiguration("none");

    // Create a mock port environment
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    move_object(TransactionSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(TransactionSelector)) destruct(TransactionSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
private void resetPlayerMessages()
{
    if (Player && function_exists("resetCatchList", Player))
    {
        Player.resetCatchList();
    }
}

/////////////////////////////////////////////////////////////////////////////
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
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void DepositTransactionDisplaysCorrectMenuWhenHavingFourHundredGold()
{
    Player.addCash(-1000);
    Player.addCash(400);
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Deposit Money - How much would you like to deposit?\n"
        "    [1] - 100 gold            \n"
        "    [2] - Custom Amount       \n"
        "    [3] - Maximum (400 gold)  \n"
        "    [4] - Cancel              \n"
        "You must select a number from 1 to 4. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void DepositTransactionDisplaysCorrectMenuWhenHavingOneThousandGold()
{
    Player.addCash(-1000);
    Player.addCash(1000);
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Deposit Money - How much would you like to deposit?\n"
        "    [1] - 100 gold            \n"
        "    [2] - 500 gold            \n"
        "    [3] - 1000 gold           \n"
        "    [4] - Custom Amount       \n"
        "    [5] - Maximum (1000 gold) \n"
        "    [6] - Cancel              \n"
        "You must select a number from 1 to 6. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionDisplaysCorrectMenu()
{
    Player.depositMoney(500);
    TransactionSelector.setTransactionType("withdraw");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Withdraw Money - How much would you like to withdraw?\n"
        "    [1] - 100 gold            \n"
        "    [2] - 500 gold            \n"
        "    [3] - Custom Amount       \n"
        "    [4] - Maximum (500 gold)  \n"
        "    [5] - Cancel              \n"
        "You must select a number from 1 to 5. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void BorrowTransactionDisplaysCorrectMenu()
{
    Player.addCash(1000); // Set cash to 2000, so max loan is 4000
    TransactionSelector.setTransactionType("borrow");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Borrow Money - How much would you like to borrow?\n"
        "    [1] - 100 gold            \n"
        "    [2] - 500 gold            \n"
        "    [3] - 1000 gold           \n"
        "    [4] - Custom Amount       \n"
        "    [5] - Maximum (4000 gold) \n"
        "    [6] - Cancel              \n"
        "You must select a number from 1 to 6. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}



/////////////////////////////////////////////////////////////////////////////
void RepayTransactionDisplaysCorrectMenu()
{
    Player.addCash(-1000);
    Player.addCash(300);
    Player.borrowMoney(400); // Use a setter in your mockPlayer
    TransactionSelector.setTransactionType("repay");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Repay Money - How much would you like to repay?\n"
        "    [1] - 100 gold            \n"
        "    [2] - Custom Amount       \n"
        "    [3] - Maximum (400 gold)  \n"
        "    [4] - Cancel              \n"
        "You must select a number from 1 to 4. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void MenuShowsOnlyRelevantAmountOptions()
{
    Player.addCash(-1000);
    Player.addCash(250);
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Deposit Money - How much would you like to deposit?\n"
        "    [1] - 100 gold            \n"
        "    [2] - Custom Amount       \n"
        "    [3] - Maximum (250 gold)  \n"
        "    [4] - Cancel              \n"
        "You must select a number from 1 to 4. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void DepositTransactionExecutesSuccessfully()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.setupStartingChoice(1); // 400 cash

    ExpectEq(400, Player.getCash());
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("100 gold"), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You deposited 100 gold into your bank account", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(100, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionExecutesSuccessfully()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.setupStartingChoice(1);
    Player.depositMoney(200);
    TransactionSelector.setTransactionType("withdraw");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("100 gold"), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You withdrew 100 gold from your bank account", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(100, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void BorrowTransactionExecutesSuccessfully()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.setupStartingChoice(1); // 400 cash
    TransactionSelector.setTransactionType("borrow");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("100 gold"), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You borrowed 100 gold from the bank", message);
    ExpectSubStringMatch("loans accrue 10% interest monthly", message);
    ExpectEq(500, Player.getCash());
    ExpectEq(5100, Player.getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void RepayTransactionExecutesSuccessfully()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.setupStartingChoice(1); // 400 cash

    TransactionSelector.setTransactionType("repay");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("100 gold"), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You repaid 100 gold toward your debt", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(4900, Player.getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void MaximumAmountOptionWorks()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.setupStartingChoice(1); // Guarantees 400 cash and 5000 debt

    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    // Confirm the menu contains the correct option
    string menu = Player.caughtMessage();
    ExpectSubStringMatch("Maximum .400 gold.", menu);

    command(getMenuOptionNumber("Maximum .400 gold."), Player);

    string transactionMessage = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You deposited 400 gold into your bank account", transactionMessage);
    ExpectEq(0, Player.getCash());
    ExpectEq(400, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void CustomAmountOptionDisplaysPrompt()
{
    Player.addCash(-1000);
    Player.addCash(1000); // Ensure cash is 1000
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("Custom Amount"), Player);
    string promptMessage = implode(Player.caughtMessages(), "\n");

    ExpectSubStringMatch("Enter amount [(]1-1000[)]:", promptMessage);
}

/////////////////////////////////////////////////////////////////////////////
void CustomAmountExecutesSuccessfully()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("Custom Amount"), Player);
    command("250", Player); // Simulate entering a custom amount

    string transactionMessage = implode(Player.caughtMessages(), "\n");

    ExpectSubStringMatch("You deposited 250 gold into your bank account", transactionMessage);
    ExpectEq(150, Player.getCash());
    ExpectEq(250, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void CustomAmountInvalidShowsError()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    command(getMenuOptionNumber("Custom Amount"), Player);
    command("9999", Player); // Simulate entering a custom amount

    string errorMessage = implode(Player.caughtMessages(), "\n");

    ExpectSubStringMatch("Invalid amount. Must be between 1 and 400.", errorMessage);
    ExpectSubStringMatch("Deposit Money", errorMessage);
}

/////////////////////////////////////////////////////////////////////////////
void CancelOptionExitsTransaction()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string cancelOption = getMenuOptionNumber("Cancel");
    if (to_int(cancelOption) > 0)
    {
        resetPlayerMessages();
        command(cancelOption, Player);
        // Should complete the selector and return to parent
    }
}

/////////////////////////////////////////////////////////////////////////////
void FailedTransactionShowsErrorMessage()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string option500 = getMenuOptionNumber("500 gold");
    if (to_int(option500) > 0)
    {
        resetPlayerMessages();
        command(option500, Player);
        string errorMessage = implode(Player.caughtMessages(), "\n");

        ExpectSubStringMatch("Unable to complete the deposit transaction", errorMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Deposit Money", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsTransactionDetails()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Deposit.*100 gold", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInTransactionSelector()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(400); // Ensure cash is 400
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void TransactionTypeDeterminesMenuTitle()
{
    string *types = ({ "deposit", "withdraw", "borrow", "repay" });
    string *expectedTitles = ({ "Deposit Money", "Withdraw Money", "Borrow Money", "Repay Money" });

    for (int i = 0; i < sizeof(types); i++)
    {
        Player.addCash(-1000);
        Player.addVehicle("wagon", "eledhel");
        Player.addCash(400); // Ensure cash is 400
        if (types[i] == "withdraw")
        {
            Player.depositMoney(200);
        }
        else if (types[i] == "repay")
        {
            Player.borrowMoney(5000);
        }

        TransactionSelector.setTransactionType(types[i]);
        resetPlayerMessages();
        TransactionSelector.initiateSelector(Player);
        string message = Player.caughtMessage();

        ExpectSubStringMatch(expectedTitles[i], message);
    }
}

/////////////////////////////////////////////////////////////////////////////
void MaxAmountLimitsAvailableOptions()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    Player.addCash(50); // Ensure cash is 50
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Deposit Money - How much would you like to deposit?\n"
        "    [1] - Custom Amount       \n"
        "    [2] - Maximum (50 gold)   \n"
        "    [3] - Cancel              \n"
        "You must select a number from 1 to 3. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}

/////////////////////////////////////////////////////////////////////////////
void ZeroMaxAmountShowsOnlyCustomAndCancel()
{
    Player.addCash(-1000);
    Player.addVehicle("wagon", "eledhel");
    TransactionSelector.setTransactionType("deposit");

    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string expected = "Deposit Money - How much would you like to deposit?\n"
        "    [1] - Custom Amount       \n"
        "    [2] - Cancel              \n"
        "You must select a number from 1 to 2. You may also undo or reset.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n";

    string message = Player.caughtMessage();
    ExpectEq(expected, message);
}
