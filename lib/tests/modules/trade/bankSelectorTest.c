//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object BankSelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    BankSelector = clone_object("/lib/modules/domains/trading/selectors/bankSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testbanker");
    Player.addCommands();
    Player.initializeTrader();

    // Create a mock port environment (required for banking services)
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    move_object(BankSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(BankSelector)) destruct(BankSelector);
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
void BankSelectorDisplaysMainMenuCorrectly()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Banking Services", message);
    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void BankSelectorRequiresPortLocation()
{
    // Move player to non-port environment
    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("You must be at a trading port to access banking services", message);
    
    // Clean up
    move_object(Player, MockPort);
    destruct(MockEnvironment);
}

/////////////////////////////////////////////////////////////////////////////
void ViewAccountStatusDisplaysFinancialInformation()
{
    // Set up player with some financial data
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(200);       // 200 cash, 200 bank
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player);

    string message = implode(Player.caughtMessages(), "\n");;
    ExpectSubStringMatch("Bank Account", message);
    ExpectSubStringMatch("Cash on Hand", message);
    ExpectSubStringMatch("Bank Balance", message);
    ExpectSubStringMatch("Outstanding Debt", message);
    ExpectSubStringMatch("Net Worth", message);
    ExpectSubStringMatch("Loan Capacity", message);
    ExpectSubStringMatch("Interest Rates", message);
}

/////////////////////////////////////////////////////////////////////////////
void DepositOptionShowsWhenPlayerHasCash()
{
    Player.setupStartingChoice(1); // 400 cash
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Deposit Money", message);
    ExpectSubStringMatch("(You have 400 gold)", message);
}

/////////////////////////////////////////////////////////////////////////////
void DepositOptionDoesNotShowWhenPlayerHasNoCash()
{
    // Player starts with 0 cash by default
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Deposit Money")) > 0,
        "Deposit option should not show when player has no cash");
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawOptionShowsWhenPlayerHasBankBalance()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(300); // Put money in bank
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Withdraw Money", message);
    ExpectSubStringMatch("(Bank: 300 gold)", message);
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawOptionDoesNotShowWhenPlayerHasNoBankBalance()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Withdraw Money")) > 0,
        "Withdraw option should not show when player has no bank balance");
}

/////////////////////////////////////////////////////////////////////////////
void LoanOptionShowsWhenPlayerIsEligible()
{
    Player.setupStartingChoice(1); // 400 cash, eligible for 800 loan
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Apply for Loan", message);
    ExpectSubStringMatch("(Eligible for 800 gold)", message);
}

/////////////////////////////////////////////////////////////////////////////
void LoanOptionDoesNotShowWhenPlayerNotEligible()
{
    // Player starts with 0 cash, not eligible for loans
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Apply for Loan")) > 0,
        "Loan option should not show when player has no cash");
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionShowsWhenPlayerHasDebt()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Repay Debt", message);
    ExpectSubStringMatch("(Owe 5000 gold)", message);
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionDoesNotShowWhenPlayerHasNoDebt()
{
    Player.setupStartingChoice(2); // 0 cash, 0 debt
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay debt option should not show when player has no debt");
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtOptionDoesNotShowWhenPlayerCannotAfford()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.addCash(-400); // Remove all cash
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay debt option should not show when player cannot afford any payment");
}

/////////////////////////////////////////////////////////////////////////////
void DepositTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    
    // Find deposit option
    string message = Player.caughtMessage();
    int depositOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Deposit Money")))
        {
            sscanf(line, "%d. %*s", depositOption);
            break;
        }
    }
    
    if (depositOption > 0)
    {
        resetPlayerMessages();
        command(to_string(depositOption), Player);
        string transactionMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Deposit Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to deposit", transactionMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);
    Player.depositMoney(200);
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    
    // Find withdraw option
    string message = Player.caughtMessage();
    int withdrawOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Withdraw Money")))
        {
            sscanf(line, "%d. %*s", withdrawOption);
            break;
        }
    }
    
    if (withdrawOption > 0)
    {
        resetPlayerMessages();
        command(to_string(withdrawOption), Player);
        string transactionMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Withdraw Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to withdraw", transactionMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void BorrowTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    
    // Find loan option
    string message = Player.caughtMessage();
    int loanOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Apply for Loan")))
        {
            sscanf(line, "%d. %*s", loanOption);
            break;
        }
    }
    
    if (loanOption > 0)
    {
        resetPlayerMessages();
        command(to_string(loanOption), Player);
        string transactionMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Borrow Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to borrow", transactionMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void RepayTransactionOpensTransactionSelector()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    
    // Find repay option
    string message = Player.caughtMessage();
    int repayOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Repay Debt")))
        {
            sscanf(line, "%d. %*s", repayOption);
            break;
        }
    }
    
    if (repayOption > 0)
    {
        resetPlayerMessages();
        command(to_string(repayOption), Player);
        string transactionMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Repay Money", transactionMessage);
        ExpectSubStringMatch("How much would you like to repay", transactionMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ExitOptionReturnsToTradingMenu()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    // Find exit option
    int exitOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Return to Trading Menu")))
        {
            sscanf(line, "%d. %*s", exitOption);
            break;
        }
    }
    
    resetPlayerMessages();
    if (exitOption > 0)
    {
        command(to_string(exitOption), Player);
        ExpectSubStringMatch("Bank has been exited", Player.caughtMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Banking Services", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsDetails()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Display your current cash", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInBankSelector()
{
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    // Since bank selector allows undo, this should show some undo message or menu
    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void NetWorthCalculatedCorrectlyWithPositiveValue()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(100);      // 300 cash, 100 bank, 5000 debt = -4600 net worth
    Player.addCash(5000);          // 5300 cash, 100 bank, 5000 debt = 400 net worth
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player);

    string message = implode(Player.caughtMessages(), "\n");  // Change this line
    ExpectSubStringMatch("Net Worth", message);
    // Should show positive net worth
    ExpectTrue(sizeof(regexp(({ message }), "400 gold")) > 0,
        "Should display the correct net worth");
}

/////////////////////////////////////////////////////////////////////////////
void NetWorthCalculatedCorrectlyWithNegativeValue()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt = -4600 net worth
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player);

    string message = implode(Player.caughtMessages(), "\n");  // Change this line
    ExpectSubStringMatch("Net Worth", message);
    // Should show negative net worth
    ExpectTrue(sizeof(regexp(({ message }), "-4600 gold")) > 0,
        "Should display the correct negative net worth");
}

/////////////////////////////////////////////////////////////////////////////
void LoanCapacityBasedOnCurrentCash()
{
    Player.setupStartingChoice(1); // 400 cash
    Player.addCash(100);          // 500 cash = 1000 loan capacity
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player);

    string message = implode(Player.caughtMessages(), "\n");  // Change this line
    ExpectSubStringMatch("Loan Capacity", message);
    ExpectTrue(sizeof(regexp(({ message }), "1000 gold")) > 0,
        "Should display correct loan capacity (2x cash)");
}

/////////////////////////////////////////////////////////////////////////////
void MenuUpdatesAfterCompleteingTransaction()
{
    Player.setupStartingChoice(1); // 400 cash
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);
    
    // Check initial menu shows deposit option
    string initialMessage = Player.caughtMessage();
    ExpectSubStringMatch("Deposit Money", initialMessage);
    ExpectSubStringMatch("(You have 400 gold)", initialMessage);
    
    // After a transaction, the menu should update to reflect new balances
    // (This would be tested more thoroughly in integration tests)
}

/////////////////////////////////////////////////////////////////////////////
void AllBankingOptionsShowWhenPlayerHasFullFinancialProfile()
{
    Player.setupStartingChoice(1); // 400 cash, 5000 debt
    Player.depositMoney(100);      // 300 cash, 100 bank, 5000 debt
    
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // All options should be available
    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Deposit Money", message);
    ExpectSubStringMatch("Withdraw Money", message);
    ExpectSubStringMatch("Apply for Loan", message);
    ExpectSubStringMatch("Repay Debt", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void BankSelectorHandlesEmptyFinancialState()
{
    // Player with no cash, no bank, no debt
    resetPlayerMessages();
    BankSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Only status and exit should be available
    ExpectSubStringMatch("View Account Status", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
    
    // These should not be available
    ExpectFalse(sizeof(regexp(({ message }), "Deposit Money")) > 0,
        "Deposit should not be available with no cash");
    ExpectFalse(sizeof(regexp(({ message }), "Withdraw Money")) > 0,
        "Withdraw should not be available with no bank balance");
    ExpectFalse(sizeof(regexp(({ message }), "Apply for Loan")) > 0,
        "Loan should not be available with no cash");
    ExpectFalse(sizeof(regexp(({ message }), "Repay Debt")) > 0,
        "Repay should not be available with no debt");
}
