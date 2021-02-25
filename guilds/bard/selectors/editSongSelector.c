//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string SongSegmentType = "ERROR";
private mapping SongData = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    SongSegmentType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setData(mapping data)
{
    SongData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        NumColumns = 1;
        Type = "Song";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = sprintf("%s Song Menu", capitalize(SongSegmentType));
    string *descriptions = 
        getDictionary("research")->getCompositeSections(SongData);

    int optionCount = 1;

    foreach(mapping element in SongData["elements"])
    {
        Data[to_string(optionCount)] = ([
            "name":  getDictionary("research")->getCompositeItemDetails(
                element, colorConfiguration, configuration),
            "description": "Select this option to edit or remove",
            "type": "modify",
            "value": SongData
        ]);
        optionCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret)
        {

        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
