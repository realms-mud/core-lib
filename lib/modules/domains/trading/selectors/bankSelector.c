// /lib/modules/domains/trading/bankSelector.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

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
    object trader = User->getService("trader");
    object environment = environment(User);
    
    if (!environment || !environment->isPort()) 
    {
        tell_object(User, configuration->decorate("You must be at a trading port to access banking services.",
                   "failure", "selector", User->colorConfiguration()));
        return;
    }
    
    Data = ([]);
    int counter = 1;
    
    // Account status
    Data[to_string(counter++)] = ([
        "name": "View Account Status",
        "type": "status",
        "description": "Display your current cash, bank balance, and debt information.",
        "canShow": 1
    ]);
    
    // Deposit money
    if (trader->getCash() > 0) 
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Deposit Money (You have %d gold)", trader->getCash()),
            "type": "deposit",
            "description": "Transfer cash from your purse to your bank account for safekeeping.",
            "canShow": 1
        ]);
    }
    
    // Withdraw money
    if (trader->getBank() > 0) 
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Withdraw Money (Bank: %d gold)", trader->getBank()),
            "type": "withdraw",
            "description": "Withdraw cash from your bank account to your purse.",
            "canShow": 1
        ]);
    }
    
    // Loan services
    int maxLoan = trader->getCash() * 2;
    if (maxLoan > 0) 
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Apply for Loan (Eligible for %d gold)", maxLoan),
            "type": "borrow",
            "max_loan": maxLoan,
            "description": sprintf("Borrow money from the bank. You can borrow up to %d gold "
                                 "based on your current cash holdings.", maxLoan),
            "canShow": 1
        ]);
    }
    
    // Debt repayment
    if (trader->getDebt() > 0) 
    {
        int canRepay = (trader->getCash() < trader->getDebt()) ? 
                      trader->getCash() : trader->getDebt();
        
        Data[to_string(counter++)] = ([
            "name": sprintf("Repay Debt (Owe %d gold)", trader->getDebt()),
            "type": "repay",
            "max_repay": canRepay,
            "description": sprintf("Repay outstanding debt. You owe %d gold and can pay up to %d gold.",
                                 trader->getDebt(), canRepay),
            "canShow": (canRepay > 0)
        ]);
    }
    
    // Investment options (future expansion)
    Data[to_string(counter++)] = ([
        "name": "Investment Services",
        "type": "invest",
        "description": "Explore investment opportunities (Coming Soon).",
        "canShow": 0  // Disabled for now
    ]);
    
    Data[to_string(counter++)] = ([
        "name": "Return to Trading Menu",
        "type": "exit",
        "description": "Return to the main trading menu.",
        "canShow": 1
    ]);
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
                    SubselectorObj->setMaxAmount(User->getService("trader")->getCash());
                    break;
                case "withdraw":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("withdraw");
                    SubselectorObj->setMaxAmount(User->getService("trader")->getBank());
                    break;
                case "borrow":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("borrow");
                    SubselectorObj->setMaxAmount(Data[selection]["max_loan"]);
                    break;
                case "repay":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("repay");
                    SubselectorObj->setMaxAmount(Data[selection]["max_repay"]);
                    break;
                case "invest":
                    tell_object(User, configuration->decorate("Investment services are not yet available.",
                               "note", "selector", User->colorConfiguration()));
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
private void displayAccountStatus() 
{
    object trader = User->getService("trader");
    string colorConfiguration = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string accountDisplay = commandsDictionary->buildBanner(colorConfiguration, charset, "top", 
                           sprintf("%s Bank Account", trader->getFirmName()));
    
    // Financial summary
    int netWorth = trader->getCash() + trader->getBank() - trader->getDebt();
    
    accountDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Cash on Hand: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", trader->getCash()),
                               "field data", "research", colorConfiguration) +
        configuration->decorate("        Bank Balance: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", trader->getBank()),
                               "field data", "research", colorConfiguration));
    
    accountDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Outstanding Debt: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", trader->getDebt()),
                               trader->getDebt() > 0 ? "penalty modifier" : "field data",
                               "research", colorConfiguration) +
        configuration->decorate("     Net Worth: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", netWorth),
                               netWorth >= 0 ? "bonus modifier" : "penalty modifier",
                               "research", colorConfiguration));
    
    // Loan capacity
    int loanCapacity = trader->getCash() * 2;
    accountDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Loan Capacity: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", loanCapacity),
                               "field data", "research", colorConfiguration) +
        configuration->decorate(" (based on current cash holdings)", "note", "selector", colorConfiguration));
    
    // Interest information
    accountDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Interest Rates: ", "field header", "research", colorConfiguration) +
        configuration->decorate("Bank deposits +0.5% monthly, Loans +10% monthly",
                               "details", "selector", colorConfiguration));
    
    accountDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(User, accountDisplay);
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
