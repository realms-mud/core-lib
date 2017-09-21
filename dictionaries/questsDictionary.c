//*****************************************************************************
// Class: researchDictionary
// File Name: researchDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseQuest = "lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
public nomask object questObject(string questItem)
{
    // The passed in value for researchItem must be a file containing a valid
    // researchItem object.
    object ret = 0;

    if (questItem && stringp(questItem) && questItem[0] != '/')
    {
        questItem = "/" + questItem;
    }
    if (questItem && stringp(questItem) && (file_size(questItem) > 0))
    {
        ret = load_object(questItem);

        if (!ret || (member(inherit_list(ret), BaseQuest) < 0) ||
            !ret->isValidQuest())
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string questSummary(string quest)
{
    string ret = "";
    object questObj = questObject(quest);
    if (questObj)
    {
        ret = capitalize(questObj->name());
    }
    return ret;
}
