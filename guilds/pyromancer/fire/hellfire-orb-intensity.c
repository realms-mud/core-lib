//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hellfire Orb Intensity");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to increase the number of times Hellfire Orb's "
        "flames strike enemies.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 55
        ]));

    addPrerequisite("/guilds/pyromancer/fire/hellfire-orb.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Hellfire Orb": 2
    ]));
    addSpecification("affected research type", "increase repeat effect");
}
