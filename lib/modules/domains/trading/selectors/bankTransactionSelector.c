//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string transactionType;
private int awaitingCustomAmount = 0;

/////////////////////////////////////////////////////////////////////////////
public void setTransactionType(string type)
{
    transactionType = type;
}

/////////////////////////////////////////////////////////////////////////////
private int getMaxAmount()
{
    int cash = User->getCash();
    int bank = User->getBank();
    int debt = User->getDebt();

    // Sanitize all values to be non-negative
    if (cash < 0) cash = 0;
    if (bank < 0) bank = 0;
    if (debt < 0) debt = 0;

    int result = 0;
    switch (transactionType)
    {
        case "deposit":
            result = cash;
            break;

        case "withdraw":
            result = bank;
            break;

        case "borrow":
            result = cash * 2;
            if (result < 1000)
            {
                result = 1000;
            }
            break;

        case "repay":
            if (cash > 0 && debt > 0)
            {
                result = (cash < debt) ? cash : debt;
            }
            else
            {
                result = 0;
            }
            break;

        default:
            result = 0;
            break;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private void executeTransaction(int amount)
{
    string colorConfiguration = User->colorConfiguration();
    object configuration = getService("configuration");
    int success = 0;

    switch (transactionType)
    {
        case "deposit":
            success = User->depositMoney(amount);
            if (success)
            {
                tell_object(User, configuration->decorate(
                    sprintf("You deposited %d gold into your bank account.", amount),
                    "success", "quests", colorConfiguration));
            }
            break;

        case "withdraw":
            success = User->withdrawMoney(amount);
            if (success)
            {
                tell_object(User, configuration->decorate(
                    sprintf("You withdrew %d gold from your bank account.", amount),
                    "success", "quests", colorConfiguration));
            }
            break;

        case "borrow":
            success = User->borrowMoney(amount);
            if (success)
            {
                tell_object(User, configuration->decorate(
                    sprintf("You borrowed %d gold from the bank. Remember, loans accrue 10%% interest monthly.",
                        amount),
                    "success", "quests", colorConfiguration));
            }
            break;

        case "repay":
            success = User->repayDebt(amount);
            if (success)
            {
                tell_object(User, configuration->decorate(
                    sprintf("You repaid %d gold toward your debt.", amount),
                    "success", "quests", colorConfiguration));
            }
            break;
    }

    if (!success)
    {
        tell_object(User, configuration->decorate(
            sprintf("Unable to complete the %s transaction.", transactionType),
            "failure", "selector", colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
private int handleCustomAmount()
{
    object configuration = getService("configuration");
    int maxAmount = getMaxAmount();
    tell_object(User, configuration->decorate(
        sprintf("Enter amount (1-%d): ", maxAmount),
        "instructions", "selector", User->colorConfiguration()));
    awaitingCustomAmount = 1;
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
private void processCustomAmount(string input)
{
    int amount = to_int(input);
    int maxAmount = getMaxAmount();
    object configuration = getService("configuration");

    int valid = 1;
    if (amount < 1 || amount > maxAmount)
    {
        tell_object(User, configuration->decorate(
            sprintf("Invalid amount. Must be between 1 and %d.", maxAmount),
            "failure", "selector", User->colorConfiguration()));
        tell_object(User, displayMessage());
        valid = 0;
    }

    if (valid)
    {
        executeTransaction(amount);
        notifySynchronous("onSelectorCompleted");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    HasDescription = 0;
    SuppressColon = 1;
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = sprintf("How much would you like to %s?", transactionType);
    Type = sprintf("%s Money", capitalize(transactionType));

    Data = ([]);
    int counter = 1;
    int maxAmount = getMaxAmount();

    // Preset amounts
    int *amounts = ({ 100, 500, 1000, 5000, 10000 });
    foreach (int amount in amounts)
    {
        if (amount <= maxAmount && maxAmount > 0)
        {
            Data[to_string(counter++)] = ([
                "name": sprintf("%d gold", amount),
                "type": "amount",
                "amount": amount,
                "description": sprintf("%s %d gold.", capitalize(transactionType), amount),
                "canShow": 1
            ]);
        }
    }

    // Custom amount option (always present)
    Data[to_string(counter++)] = ([
        "name": "Custom Amount",
        "type": "custom",
        "description": sprintf("Enter a specific amount to %s.", transactionType),
        "canShow": 1
    ]);

    // Maximum amount option (only if maxAmount > 0)
    if (maxAmount > 0)
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Maximum (%d gold)", maxAmount),
            "type": "amount",
            "amount": maxAmount,
            "description": sprintf("%s the maximum amount (%d gold).",
                capitalize(transactionType), maxAmount),
            "canShow": 1
        ]);
    }

    // Cancel option (always present)
    Data[to_string(counter++)] = ([
        "name": "Cancel",
        "type": "exit",
        "description": "Cancel this transaction.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        if (awaitingCustomAmount)
        {
            awaitingCustomAmount = 0;
            processCustomAmount(selection);
            ret = 1;
        }
        else
        {
            ret = (Data[selection]["type"] == "exit") ? 1 : 0;

            if (!ret && Data[selection]["canShow"])
            {
                if (Data[selection]["type"] == "amount")
                {
                    executeTransaction(Data[selection]["amount"]);
                    ret = 1;
                }
                else if (Data[selection]["type"] == "custom")
                {
                    ret = handleCustomAmount();
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return awaitingCustomAmount;
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return awaitingCustomAmount;
}
