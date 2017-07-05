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
        
        string *openTrees = persistence->extractSaveData("openResearchTrees", data);
        if (sizeof(openTrees))
        {
            openResearchTrees = openTrees;
        }
        research = persistence->extractSavedMapping("research", data);
        researchChoices = persistence->extractSavedMapping("researchChoices", data);
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
        "availableResearchPoints": researchPoints
    ]);
}