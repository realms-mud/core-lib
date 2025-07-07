//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object TransactionSelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    TransactionSelector = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testbanker");
    Player.addCommands();
    Player.initializeTrader();

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
void DepositTransactionDisplaysCorrectMenu()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Deposit Money", message);
    ExpectSubStringMatch("How much would you like to deposit", message);
    ExpectSubStringMatch("100 gold", message);
    ExpectSubStringMatch("500 gold", message);
    ExpectSubStringMatch("1000 gold", message);
    ExpectSubStringMatch("Custom Amount", message);
    ExpectSubStringMatch("Maximum [(]1000 gold[)]", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionDisplaysCorrectMenu()
{
    TransactionSelector.setTransactionType("withdraw");
    TransactionSelector.setMaxAmount(500);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Withdraw Money", message);
    ExpectSubStringMatch("How much would you like to withdraw", message);
    ExpectSubStringMatch("100 gold", message);
    ExpectSubStringMatch("500 gold", message);
    ExpectSubStringMatch("Maximum [(]500 gold[)]", message);
    ExpectFalse(sizeof(regexp(({ message }), "1000 gold")) > 0,
        "Should not show amounts greater than max");
}

/////////////////////////////////////////////////////////////////////////////
void BorrowTransactionDisplaysCorrectMenu()
{
    TransactionSelector.setTransactionType("borrow");
    TransactionSelector.setMaxAmount(2000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Borrow Money", message);
    ExpectSubStringMatch("How much would you like to borrow", message);
    ExpectSubStringMatch("1000 gold", message);
    ExpectSubStringMatch("Maximum [(]2000 gold[)]", message);
}

/////////////////////////////////////////////////////////////////////////////
void RepayTransactionDisplaysCorrectMenu()
{
    TransactionSelector.setTransactionType("repay");
    TransactionSelector.setMaxAmount(300);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Repay Money", message);
    ExpectSubStringMatch("How much would you like to repay", message);
    ExpectSubStringMatch("100 gold", message);
    ExpectSubStringMatch("Maximum [(]300 gold[)]", message);
    ExpectFalse(sizeof(regexp(({ message }), "500 gold")) > 0,
        "Should not show amounts greater than max");
}

/////////////////////////////////////////////////////////////////////////////
void MenuShowsOnlyRelevantAmountOptions()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(250);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("100 gold", message);
    ExpectFalse(sizeof(regexp(({ message }), "500 gold")) > 0,
        "Should not show 500 gold when max is 250");
    ExpectFalse(sizeof(regexp(({ message }), "1000 gold")) > 0,
        "Should not show 1000 gold when max is 250");
    ExpectSubStringMatch("Maximum [(]250 gold[)]", message);
}

/////////////////////////////////////////////////////////////////////////////
void DepositTransactionExecutesSuccessfully()
{
    Player.setupStartingChoice(1); // 400 cash
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(400);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player); // Select 100 gold option

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You deposited 100 gold into your bank account", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(100, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionExecutesSuccessfully()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(200); // Put 200 in bank
    TransactionSelector.setTransactionType("withdraw");
    TransactionSelector.setMaxAmount(200);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player); // Select 100 gold option

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You withdrew 100 gold from your bank account", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(100, Player.getBank());
}

/////////////////////////////////////////////////////////////////////////////
void BorrowTransactionExecutesSuccessfully()
{
    Player.setupStartingChoice(1); // 400 cash, eligible for 800 loan
    TransactionSelector.setTransactionType("borrow");
    TransactionSelector.setMaxAmount(500);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player); // Select 100 gold option

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You borrowed 100 gold from the bank", message);
    ExpectSubStringMatch("loans accrue 10% interest monthly", message);
    ExpectEq(500, Player.getCash());
    ExpectEq(5100, Player.getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void RepayTransactionExecutesSuccessfully()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    TransactionSelector.setTransactionType("repay");
    TransactionSelector.setMaxAmount(400);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player); // Select 100 gold option

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You repaid 100 gold toward your debt", message);
    ExpectEq(300, Player.getCash());
    ExpectEq(4900, Player.getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void MaximumAmountOptionWorks()
{
    Player.setupStartingChoice(1); // 400 cash
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(400);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    
    // Find maximum option
    string message = Player.caughtMessage();
    int maxOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Maximum \\(400 gold\\)")))
        {
            sscanf(line, "%d. %*s", maxOption);
            break;
        }
    }
    
    if (maxOption > 0)
    {
        resetPlayerMessages();
        command(to_string(maxOption), Player);
        string transactionMessage = implode(Player.caughtMessages(), "\n");
        
        ExpectSubStringMatch("You deposited 400 gold into your bank account", transactionMessage);
        ExpectEq(0, Player.getCash());
        ExpectEq(400, Player.getBank());
    }
}

/////////////////////////////////////////////////////////////////////////////
void CustomAmountOptionDisplaysPrompt()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    
    // Find custom amount option
    string message = Player.caughtMessage();
    int customOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Custom Amount")))
        {
            sscanf(line, "%d. %*s", customOption);
            break;
        }
    }
    
    if (customOption > 0)
    {
        resetPlayerMessages();
        command(to_string(customOption), Player);
        string promptMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Enter amount [(]1-1000[)]:", promptMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void CancelOptionExitsTransaction()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    
    // Find cancel option
    string message = Player.caughtMessage();
    int cancelOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Cancel")))
        {
            sscanf(line, "%d. %*s", cancelOption);
            break;
        }
    }
    
    if (cancelOption > 0)
    {
        resetPlayerMessages();
        command(to_string(cancelOption), Player);
        // Should complete the selector and return to parent
    }
}

/////////////////////////////////////////////////////////////////////////////
void FailedTransactionShowsErrorMessage()
{
    // Try to deposit more money than player has
    Player.setupStartingChoice(1); // 400 cash
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    
    // Find 500 gold option
    string message = Player.caughtMessage();
    int option500 = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "500 gold")))
        {
            sscanf(line, "%d. %*s", option500);
            break;
        }
    }
    
    if (option500 > 0)
    {
        resetPlayerMessages();
        command(to_string(option500), Player);
        string errorMessage = implode(Player.caughtMessages(), "\n");
        
        ExpectSubStringMatch("Unable to complete the deposit transaction", errorMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Deposit Money", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsTransactionDetails()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Deposit.*100 gold", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInTransactionSelector()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(1000);
    
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
    // Test each transaction type
    string *types = ({ "deposit", "withdraw", "borrow", "repay" });
    string *expectedTitles = ({ "Deposit Money", "Withdraw Money", "Borrow Money", "Repay Money" });
    
    for (int i = 0; i < sizeof(types); i++)
    {
        TransactionSelector.setTransactionType(types[i]);
        TransactionSelector.setMaxAmount(1000);
        
        resetPlayerMessages();
        TransactionSelector.initiateSelector(Player);
        string message = Player.caughtMessage();
        
        ExpectSubStringMatch(expectedTitles[i], message);
    }
}

/////////////////////////////////////////////////////////////////////////////
void MaxAmountLimitsAvailableOptions()
{
    // Test with very low max amount
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(50);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "100 gold")) > 0,
        "Should not show 100 gold when max is 50");
    ExpectSubStringMatch("Custom Amount", message);
    ExpectSubStringMatch("Maximum [(]50 gold[)]", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void ZeroMaxAmountShowsOnlyCustomAndCancel()
{
    TransactionSelector.setTransactionType("deposit");
    TransactionSelector.setMaxAmount(0);
    
    resetPlayerMessages();
    TransactionSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "100 gold")) > 0,
        "Should not show any preset amounts when max is 0");
    ExpectFalse(sizeof(regexp(({ message }), "Maximum \\(0 gold\\)")) > 0,
        "Should not show maximum option when max is 0");
    ExpectSubStringMatch("Custom Amount", message);
    ExpectSubStringMatch("Cancel", message);
}
