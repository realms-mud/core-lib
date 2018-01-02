//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingType;
private string CraftingSubType = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    CraftingType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setSubType(string type)
{
    CraftingSubType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;

        Dictionary = load_object("/lib/dictionaries/craftingDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!CraftingType)
    {
        raise_error("ERROR: craftItemSubselector.c - The type has not been "
            "set.\n");
    }

    string displayType = CraftingSubType ? CraftingSubType : CraftingType;

    Description = "From this menu, you can craft items";
    Type = "Craft " + capitalize(displayType);

    if (CraftingSubType)
    {
        Data = Dictionary->getCraftingListBySubType(CraftingType, CraftingSubType, User);
    }
    else
    {
        Data = Dictionary->getCraftingList(CraftingType, User);
    }

    NumColumns = Data["1"]["show materials"] ? 2 : 1;
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Exit Craft %s Menu", capitalize(displayType)),
        "type": "exit",
        "canShow": 1,
        "description": "This option lets you exit this crafting menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        if (!ret)
        {
            if(member(Data[selection], "show materials"))
            {
                SubselectorObj =
                    clone_object("/lib/modules/crafting/selectMaterialsSelector.c");
                SubselectorObj->setItem(Data[selection]["selector"]);
                SubselectorObj->setType(Data[selection]["type"]);
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else
            {
                SubselectorObj =
                    clone_object("/lib/modules/crafting/craftItemSelector.c");
                SubselectorObj->setType(Data[selection]["selector"]);
                if (member(Data[selection], "sub type"))
                {
                    SubselectorObj->setSubType(Data[selection]["sub type"]);
                }
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
    if (caller->selection())
    {
        if (User)
        {
            tell_object(User, displayMessage());
        }
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string *ret = ({});

    if (member(Data[choice], "prerequisites met") &&
        !Data[choice]["prerequisites met"])
    {
        ret += ({ "P" });
    }
    if (member(Data[choice], "have materials") &&
        !Data[choice]["have materials"])
    {
        ret += ({ "M" });
    }
    return sizeof(ret) ? sprintf("[0;34;1m([0;35m%s[0;34;1m)[0m", implode(ret, ",")) : "";
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    return sprintf("%s[%s]%s - %s%s", 
        (NumColumns < 3) ? "\t" : "", Red,
        padSelectionDisplay(choice),
        Data[choice]["canShow"] ? "[0;32m%-20s[0m" : "[0;31m%-20s[0m",
        displayDetails(choice));
}