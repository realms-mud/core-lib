//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wildfire Efficiency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to reduce the spell point cost of wildfire abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/wildfire-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Smolder": 3,
        "Burning Brand": 8,
        "Spreading Flames": 15,
        "Conflagration": 20,
        "Raging Wildfire": 30,
        "Ferianth's Wildfire": 50
    ]));
    addSpecification("affected research type", "decrease cost");
}
