//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

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
private int researchPoints = 0;

/////////////////////////////////////////////////////////////////////////////
static nomask void loadResearch(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        researchPoints = persistence->extractSaveData("availableResearchPoints", data);
        openResearchTrees = persistence->extractSaveData("openResearchTrees", data);
        research = persistence->extractSavedMapping("research", data);
        researchChoices = persistence->extractSavedMapping("researchChoices", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping sendResearchMapping(string type, mapping input)
{
    mapping ret = ([]);

    string *researchList = m_indices(input);
    foreach(string researchItem in researchList)
    {
        string *keys = m_indices(input[researchItem]);
        if (sizeof(keys))
        {
            ret[type][researchItem] = ([]);

            foreach(string key in keys)
            {
                ret[type][researchItem][key] = input[researchItem][key];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendResearch()
{
    return ([
        "research": sendResearchMapping("research", research),
        "researchChoices": sendResearchMapping("researchChoices", researchChoices),
        "openResearchTrees": implode(openResearchTrees, "##"),
        "researchPoints": researchPoints
    ]);
}