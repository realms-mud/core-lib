//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string BaseQuest = "lib/modules/quests/questItem.c";

private mapping quests = ([
    // "path to quest object" : ([
    //      "name": "<name>",
    //      "state": "<state>",
    //      "states completed": ({ list }),
    //      "is active", true/false
    //      "is completed", true/false
    // ]),
]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadQuests(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        quests = persistence->extractSavedMapping("quests", data);

        if (sizeof(quests))
        {
            string *questList = m_indices(quests);
            foreach(string quest in questList)
            {
                if (member(quests[quest], "states completed"))
                {
                    quests[quest]["states completed"] =
                        explode(quests[quest]["states completed"],
                            "##") - ({ "" });
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendQuests()
{
    mapping ret = ([
        "quests":([])
    ]);

    string *questList = m_indices(quests);
    foreach(string quest in questList)
    {
        string *keys = m_indices(quests[quest]);
        if (sizeof(keys))
        {
            ret["quests"][quest] = ([]);

            foreach(string key in keys)
            {
                if (key == "states completed")
                {
                    ret["quests"][quest][key] = implode(
                        quests[quest][key], "##");
                }
                else
                {
                    ret["quests"][quest][key] = quests[quest][key];
                }
            }
        }
    }
    return ret;
}
