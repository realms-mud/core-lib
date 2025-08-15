//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingService;

///////////////////////////////////////////////////////////////////////////////
private string padAndDecorate(string text, int width, string deco, string section, string color)
{
    // Pad the raw text to the desired width, then decorate
    int pad = width - textWidth(text);
    string padded = text + ((pad > 0) ? sprintf("%*s", pad, "") : "");
    return configuration->decorate(padded, deco, section, color);
}

///////////////////////////////////////////////////////////////////////////////
private string padRowToBanner(string row, int bannerWidth)
{
    int pad = bannerWidth - textWidth(row);

    return row + ((pad > 0) ? sprintf("%*s", pad, "") : "");
}

///////////////////////////////////////////////////////////////////////////////
private void displayAccountStatus()
{
    string colorConfig = User->colorConfiguration();
    object commandsService = getService("commands");
    string charset = User->charsetConfiguration();

    string accountDisplay = commandsService->buildBanner(colorConfig, charset, "top",
        sprintf("%s Bank Account", User->getFirmName()));
    int bannerWidth = textWidth(accountDisplay) - 4;

    int cash = User->getCash();
    int bank = User->getBank();
    int debt = User->getDebt();
    int netWorth = cash + bank - debt;
    int loanCapacity = cash * 2;

    string row;

    // First row
    row =
        padAndDecorate("Cash on Hand:", 18, "field header", "research", colorConfig) +
        padAndDecorate(sprintf("%d gold", cash), 18, "field data", "research", colorConfig) +
        padAndDecorate("Bank Balance:", 18, "field header", "research", colorConfig) +
        padAndDecorate(sprintf("%d gold", bank), 18, "field data", "research", colorConfig);
    accountDisplay += commandsService->banneredContent(colorConfig, charset, padRowToBanner(row, bannerWidth));

    // Second row
    row =
        padAndDecorate("Outstanding Debt:", 18, "field header", "research", colorConfig) +
        padAndDecorate(sprintf("%d gold", debt), 18,
            debt > 0 ? "penalty modifier" : "field data", "research", colorConfig) +
        padAndDecorate("Net Worth:", 18, "field header", "research", colorConfig) +
        padAndDecorate(sprintf("%d gold", netWorth), 18,
            netWorth >= 0 ? "bonus modifier" : "penalty modifier", "research", colorConfig);
    accountDisplay += commandsService->banneredContent(colorConfig, charset, padRowToBanner(row, bannerWidth));

    // Third row
    row =
        padAndDecorate("Loan Capacity:", 18, "field header", "research", colorConfig) +
        padAndDecorate(sprintf("%d gold", loanCapacity), 10, "field data", "research", colorConfig) +
        configuration->decorate("(based on current cash holdings)", "note", "selector", colorConfig);
    accountDisplay += commandsService->banneredContent(colorConfig, charset, padRowToBanner(row, bannerWidth));

    // Fourth row
    row =
        padAndDecorate("Interest Rates:", 18, "field header", "research", colorConfig) +
        configuration->decorate("Bank deposits +0.5% monthly, Loans +10% monthly",
            "details", "selector", colorConfig);
    accountDisplay += commandsService->banneredContent(colorConfig, charset, padRowToBanner(row, bannerWidth));

    accountDisplay += commandsService->buildBanner(colorConfig, charset, "bottom", "-");

    tell_object(User, accountDisplay);
}

///////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Banking Services";
    Type = "Bank";
    Data = ([]);
    TradingService = getService("trading");
}

///////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    Data[to_string(counter++)] = ([
        "name":"View Account Status",
        "type" : "status",
        "description" : "Display your current cash, bank balance, and debt information.",
        "canShow" : 1
    ]);

    if (User->getCash() > 0)
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Deposit Money (You have %d gold)", User->getCash()),
            "type": "deposit",
            "description": "Transfer cash from your purse to your bank account for safekeeping.",
            "canShow" : 1
        ]);
    }

    if (User->getBank() > 0)
    {
        Data[to_string(counter++)] = ([
            "name":sprintf("Withdraw Money (Bank: %d gold)", User->getBank()),
            "type" : "withdraw",
            "description" : "Withdraw cash from your bank account to your purse.",
            "canShow" : 1
        ]);
    }

    int maxLoan = TradingService->getMaximumLoan(User);
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

    if (User->getDebt() > 0)
    {
        int canRepay = (User->getCash() < User->getDebt()) ?
            User->getCash() : User->getDebt();

        if (canRepay > 0)
        {
            Data[to_string(counter++)] = ([
                "name":sprintf("Repay Debt (Owe %d gold)", User->getDebt()),
                "type" : "repay",
                "max repay" : canRepay,
                "description" : sprintf("Repay outstanding debt. You owe %d gold and can pay up to %d gold.",
                    User->getDebt(), canRepay),
                "canShow" : 1
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

///////////////////////////////////////////////////////////////////////////////
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
                    break;
                case "withdraw":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("withdraw");
                    break;
                case "borrow":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("borrow");
                    break;
                case "repay":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankTransactionSelector.c");
                    SubselectorObj->setTransactionType("repay");
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

///////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

///////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

///////////////////////////////////////////////////////////////////////////////
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
