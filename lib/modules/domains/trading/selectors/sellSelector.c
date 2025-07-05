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
    Description = "Sell Goods";
    Type = "Sell Cargo";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object environment = environment(User);
    if (environment && environment->isPort())
    {
        object trader = User->getService("trader");
        mapping vehicle = trader->getVehicle();
        mapping cargo = vehicle["cargo"];
        
        Data = ([]);
        int counter = 1;
        
        if (sizeof(cargo))
        {
            string *items = m_indices(cargo);
            foreach(string item in items)
            {
                object itemObj = load_object(item);
                if (itemObj)
                {
                    int price = environment->getItemPrice(item);
                    int quantity = cargo[item];
                    int totalValue = price * quantity;
                    
                    Data[to_string(counter++)] = ([
                        "name": sprintf("%s x%d (%d gold each)", 
                                       itemObj->query("name"), quantity, price),
                        "type": "item",
                        "item path": item,
                        "price": price,
                        "quantity": quantity,
                        "total value": totalValue,
                        "description": sprintf("Sell %s. You have %d units worth %d gold each.",
                                             itemObj->query("name"), quantity, price),
                        "canShow": 1
                    ]);
                }
            }
        }
        else
        {
            Data[to_string(counter++)] = ([
                "name": "No Cargo to Sell",
                "type": "empty",
                "description": "Your vehicle has no cargo to sell.",
                "canShow": 0
            ]);
        }
        
        Data[to_string(counter++)] = ([
            "name": "Return to Trading Menu",
            "type": "exit",
            "description": "Return to the main trading menu.",
            "canShow": 1
        ]);
    }
    else
    {
        tell_object(User, configuration->decorate("You must be at a trading port to sell goods.",
                   "failure", "selector", colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        
        if (!ret && Data[selection]["canShow"] && Data[selection]["type"] == "item")
        {
            // Create quantity selector for selling
            SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
            SubselectorObj->setItem(Data[selection]["item path"]);
            SubselectorObj->setMaxQuantity(Data[selection]["quantity"]);
            SubselectorObj->setPrice(Data[selection]["price"]);
            SubselectorObj->setAction("sell");
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
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
    string colorConfig = User->colorConfiguration();

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfig),
        padSelectionDisplay(choice),
        configuration->decorate("%-35s", displayType, "selector", colorConfig),
        displayDetails(choice));
}
