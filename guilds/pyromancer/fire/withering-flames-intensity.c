//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Withering Flames Intensity");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to increase the number of times Withering Flames' "
        "fire strikes enemies.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 61
        ]));

    addPrerequisite("/guilds/pyromancer/fire/withering-flames.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Withering Flames": 2
    ]));
    addSpecification("affected research type", "increase repeat effect");
}
