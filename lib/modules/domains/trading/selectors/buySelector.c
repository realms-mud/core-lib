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
        object trader = User->getService("trader");
        Data = ([]);
        int counter = 1;
        
        // Common trade goods
        string *availableItems = ({
            "/lib/instances/items/materials/metal/iron",
            "/lib/instances/items/materials/wood/oak", 
            "/lib/instances/items/weapons/swords/long-sword",
            "/lib/instances/items/food/bread",
            "/lib/instances/items/materials/crystal/diamond",
            "/lib/instances/items/materials/textile/silk",
            "/lib/instances/items/materials/spice/pepper"
        });
        
        foreach(string item in availableItems) 
        {
            object itemObj = load_object(item);
            if (itemObj) 
            {
                int price = environment->getItemPrice(item);
                int canAfford = trader->getCash() / price;
                
                Data[to_string(counter++)] = ([
                    "name": sprintf("%s (%d gold each)", itemObj->query("name"), price),
                    "type": "item",
                    "item_path": item,
                    "price": price,
                    "can_afford": canAfford,
                    "description": sprintf("Purchase %s at %d gold per unit. You can afford %d units.",
                                         itemObj->query("name"), price, canAfford),
                    "canShow": (canAfford > 0)
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
