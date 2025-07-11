//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
private void displayAccountStatus() 
{
    string colorConfig = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string accountDisplay = commandsDictionary->buildBanner(colorConfig, charset, "top", 
                           sprintf("%s Bank Account", User->getFirmName()));
    
    // Financial summary
    int netWorth = User->getCash() + User->getBank() - User->getDebt();
    
    accountDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Cash on Hand: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", User->getCash()),
                               "field data", "research", colorConfig) +
        configuration->decorate("        Bank Balance: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", User->getBank()),
                               "field data", "research", colorConfig));
    
    accountDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Outstanding Debt: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", User->getDebt()),
                               User->getDebt() > 0 ? "penalty modifier" : "field data",
                               "research", colorConfig) +
        configuration->decorate("     Net Worth: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", netWorth),
                               netWorth >= 0 ? "bonus modifier" : "penalty modifier",
                               "research", colorConfig));
    
    // Loan capacity
    int loanCapacity = User->getCash() * 2;
    accountDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Loan Capacity: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", loanCapacity),
                               "field data", "research", colorConfig) +
        configuration->decorate(" (based on current cash holdings)", "note", "selector", colorConfig));
    
    // Interest information
    accountDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Interest Rates: ", "field header", "research", colorConfig) +
        configuration->decorate("Bank deposits +0.5% monthly, Loans +10% monthly",
                               "details", "selector", colorConfig));
    
    accountDisplay += commandsDictionary->buildBanner(colorConfig, charset, "bottom", "-");
    
    tell_object(User, accountDisplay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Banking Services";
    Type = "Bank";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object environment = environment(User);
    
    if (!environment || !environment->isPort()) 
    {
        tell_object(User, configuration->decorate("You must be at a trading port to access banking services.",
                   "failure", "selector", colorConfiguration));
        emitCompletionEvent();
    }
    else
    {
        Data = ([]);
        int counter = 1;

        // Account status
        Data[to_string(counter++)] = ([
            "name":"View Account Status",
            "type" : "status",
            "description" : "Display your current cash, bank balance, and debt information.",
            "canShow" : 1
        ]);

        // Deposit money
        if (User->getCash() > 0)
        {
            Data[to_string(counter++)] = ([
                "name":sprintf("Deposit Money (You have %d gold)", User->getCash()),
                "type" : "deposit",
                "description" : "Transfer cash from your purse to your bank account for safekeeping.",
                "canShow" : 1
            ]);
        }

        // Withdraw money
        if (User->getBank() > 0)
        {
            Data[to_string(counter++)] = ([
                "name":sprintf("Withdraw Money (Bank: %d gold)", User->getBank()),
                "type" : "withdraw",
                "description" : "Withdraw cash from your bank account to your purse.",
                "canShow" : 1
            ]);
        }

        // Loan services
        int maxLoan = User->getCash() * 2;
        if (maxLoan > 0)
        {
            Data[to_string(counter++)] = ([
                "name":sprintf("Apply for Loan (Eligible for %d gold)", maxLoan),
                "type" : "borrow",
                "max loan" : maxLoan,
                "description" : sprintf("Borrow money from the bank. You can borrow up to %d gold "
                    "based on your current cash holdings.", maxLoan),
                "canShow" : 1
            ]);
        }

        // Debt repayment
        if (User->getDebt() > 0)
        {
            int canRepay = (User->getCash() < User->getDebt()) ?
                User->getCash() : User->getDebt();

            if (canRepay > 0)  // Add this check
            {
                Data[to_string(counter++)] = ([
                    "name":sprintf("Repay Debt (Owe %d gold)", User->getDebt()),
                    "type" : "repay",
                    "max repay" : canRepay,
                    "description" : sprintf("Repay outstanding debt. You owe %d gold and can pay up to %d gold.",
                        User->getDebt(), canRepay),
                        "canShow" : 1  // Can simplify this since we already checked above
                ]);
            }
        }

        Data[to_string(counter++)] = ([
            "name":"Return to Trading Menu",
            "type" : "exit",
            "description" : "Return to the main trading menu.",
            "canShow" : 1
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    
    if (User) 
    {
        ret = (Data[selection]["type"] == "exit");
        
        if (!ret && Data[selection]["canShow"]) 
        {
            switch(Data[selection]["type"]) 
            {
                case "status":
                    displayAccountStatus();
                    break;
                case "deposit":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("deposit");
                    SubselectorObj->setMaxAmount(User->getCash());
                    break;
                case "withdraw":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("withdraw");
                    SubselectorObj->setMaxAmount(User->getBank());
                    break;
                case "borrow":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("borrow");
                    SubselectorObj->setMaxAmount(Data[selection]["max loan"]);
                    break;
                case "repay":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("repay");
                    SubselectorObj->setMaxAmount(Data[selection]["max repay"]);
                    break;
            }
            
            if (SubselectorObj) 
            {
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-45s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
