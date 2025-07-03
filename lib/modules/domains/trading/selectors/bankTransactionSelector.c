// /lib/modules/domains/trading/bankTransactionSelector.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string transactionType;
private int maxAmount;

/////////////////////////////////////////////////////////////////////////////
public void setTransactionType(string type) 
{
    transactionType = type;
}

/////////////////////////////////////////////////////////////////////////////
public void setMaxAmount(int amount) 
{
    maxAmount = amount;
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
    
    // Quick amount options
    int *amounts = ({ 100, 500, 1000, 5000, 10000 });
    foreach(int amount in amounts) 
    {
        if (amount <= maxAmount) 
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
    
    // Custom amount option
    Data[to_string(counter++)] = ([
        "name": "Custom Amount",
        "type": "custom",
        "description": sprintf("Enter a specific amount to %s.", transactionType),
        "canShow": 1
    ]);
    
    // Maximum amount
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
        ret = (Data[selection]["type"] == "exit");
        
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
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private int handleCustomAmount() 
{
    tell_object(User, configuration->decorate(
        sprintf("Enter amount (1-%d): ", maxAmount),
        "instructions", "selector", User->colorConfiguration()));
    
    input_to("processCustomAmount", 0);
    return -1; // Don't exit yet
}

/////////////////////////////////////////////////////////////////////////////
private void processCustomAmount(string input) 
{
    int amount = to_int(input);
    
    if (amount < 1 || amount > maxAmount) 
    {
        tell_object(User, configuration->decorate(
            sprintf("Invalid amount. Must be between 1 and %d.", maxAmount),
            "failure", "selector", User->colorConfiguration()));
        tell_object(User, displayMessage());
        return;
    }
    
    executeTransaction(amount);
    notifySynchronous("onSelectorCompleted");
}

/////////////////////////////////////////////////////////////////////////////
private void executeTransaction(int amount)
{
    object trader = User->getService("trader");
    string colorConfiguration = User->colorConfiguration();
    int success = 0;
    
    switch(transactionType)
    {
        case "deposit":
            success = trader->depositMoney(amount);
            if (success) 
            {
                tell_object(User, configuration->decorate(
                    sprintf("You deposited %d gold into your bank account.", amount),
                    "success", "quests", colorConfiguration));
            }
            break;
            
        case "withdraw":
            success = trader->withdrawMoney(amount);
            if (success) 
            {
                tell_object(User, configuration->decorate(
                    sprintf("You withdrew %d gold from your bank account.", amount),
                    "success", "quests", colorConfiguration));
            }
            break;
            
        case "borrow":
            success = trader->borrowMoney(amount);
            if (success) 
            {
                tell_object(User, configuration->decorate(
                    sprintf("You borrowed %d gold from the bank. Remember, loans accrue 10%% interest monthly.",
                           amount),
                    "success", "quests", colorConfiguration));
            }
            break;
            
        case "repay":
            success = trader->repayDebt(amount);
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
