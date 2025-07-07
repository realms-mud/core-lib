//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string selectedItem;
private int selectedQuantity;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Buy Goods";
    Type = "Purchase";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object environment = environment(User);
    object configuration = getDictionary("configuration");
    
    if (environment && environment->isPort()) 
    {
        Data = ([]);
        int counter = 1;
        
        object tradingDict = getDictionary("trading");
        mapping availableGoods = tradingDict->getAvailableGoods(environment, User);

        string *choices = m_indices(availableGoods);
        foreach(string choice in choices)
        {
            if (availableGoods[choice]["canShow"])
            {
                Data[to_string(counter++)] = availableGoods[choice] + ([
                    "type": "item",
                    "description": sprintf("Purchase %s. You can afford %d units.",
                                         availableGoods[choice]["name"], 
                                         availableGoods[choice]["can afford"])
                ]);
            }
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
        tell_object(User, configuration->decorate("You must be at a trading port to buy goods.",
                   "failure", "selector", User->colorConfiguration()));
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
            selectedItem = Data[selection]["item_path"];
            
            // Create quantity selector
            SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
            SubselectorObj->setItem(selectedItem);
            SubselectorObj->setMaxQuantity(Data[selection]["can_afford"]);
            SubselectorObj->setPrice(Data[selection]["price"]);
            SubselectorObj->setAction("buy");
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
    object configuration = getDictionary("configuration");
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    string colorConfiguration = User->colorConfiguration();

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-40s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
