//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef researchModule_h
#define researchModule_h

// This mapping contains all of the research items that the living knows.
private mapping research = ([
    //  <research file name>: ([
    //      "when research began": time,
    //      "time spent learning": seconds,
    //      "research complete": true|false,
    //  ])
]);
private string *openResearchTrees = ({});
private mapping researchChoices = ([]);
private mapping compositeResearch = ([]);
private mapping activeCompositeResearch = 0;

private int researchPoints = 0;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadResearch(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        researchPoints = persistence->extractSaveData("availableResearchPoints", data);
        
        string *openTrees = persistence->extractSaveData("openResearchTrees", data);
        if (sizeof(openTrees))
        {
            openResearchTrees = openTrees;
        }
        research = persistence->extractSavedMapping("research", data);

        string *researchItems = m_indices(research);
        if (sizeof(researchItems))
        {
            object dictionary = load_object("/lib/dictionaries/researchDictionary");
            foreach(string researchItem in researchItems)
            {
                string *bonuses = dictionary->getResearchBonuses(researchItem);
                if (bonuses && sizeof(bonuses) &&
                    !dictionary->isActiveOrSustainedAbility(researchItem))
                {
                    research[researchItem]["bonuses"] = bonuses;
                }
            }
        }
        researchChoices = persistence->extractSavedMapping("researchChoices", data);
        compositeResearch = persistence->extractSavedMapping("compositeResearch", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping sendResearchMapping(mapping input)
{
    mapping ret = ([ ]);

    string *researchList = m_indices(input);
    foreach(string researchItem in researchList)
    {
        string *keys = m_indices(input[researchItem]);
        if (sizeof(keys))
        {
            ret[researchItem] = ([]);

            foreach(string key in keys)
            {
                ret[researchItem][key] = input[researchItem][key];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendResearch()
{
    return ([
        "research": sendResearchMapping(research),
        "researchChoices": sendResearchMapping(researchChoices),
        "openResearchTrees": openResearchTrees,
        "availableResearchPoints": researchPoints,
        "compositeResearch": compositeResearch
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removeCompositeResearch(string player, string name,
    string constraint)
{
    load_object("/lib/modules/secure/dataAccess.c")->removeCompositeResearch(
        player, name, constraint);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removeSavedResearch(string *research, string *trees)
{
    load_object("/lib/modules/secure/dataAccess.c")->removeSavedResearch(
        this_object()->RealName(), research, trees);
}

#endif
