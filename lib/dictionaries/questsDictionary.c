//*****************************************************************************
// Class: researchDictionary
// File Name: researchDictionary.c
//
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string BaseQuest = "/lib/modules/quests/questItem.c";

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

/////////////////////////////////////////////////////////////////////////////
public string *questTypes()
{
    return ({ "primary", "secondary", "guild", "research",
        "task", "background" });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping questsOfType(object user, string type)
{
    mapping ret = ([]);
    string *sources = ({});
    if (type == "completed")
    {
        sources = user->completedQuests();
    }
    else
    {
        sources = filter(user->questsInProgress(),
            (: questObject($1) && questObject($1)->type() == $2 :), type);
    }

    sources = sort_array(sources, (: $1 > $2 :));

    int menuItem = 1;
    foreach(string source in sources)
    {
        object quest = questObject(source);
        ret[to_string(menuItem)] = ([
            "name": ((sizeof(quest->name()) > 20) ? 
                (capitalize(quest->name()[0..16]) + "...") :
                capitalize(quest->name())),
            "type": source,
            "description": format(sprintf("\x1b[0;33m%s\n%s\x1b[0m\n\x1b[0;36m%s\x1b[0m\n",
                quest->name(), quest->description(), 
                to_string(user->questStory(source))), 78)
        ]);
        menuItem++;
    }
    return ret;
}
