//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sextuple Thread");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to weave an additional element into their combinations.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 41
       ]));

    addPrerequisite("/guilds/oneiromancer/psionic-combinations/quintuple-thread.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Waking Nightmare": 1
    ]));
    addSpecification("affected research type", "max combination chain");
}
