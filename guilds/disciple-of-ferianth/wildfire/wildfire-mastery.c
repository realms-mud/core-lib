//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wildfire Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "enhanced knowledge of wildfire magic, increasing the damage "
        "of all wildfire abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 5
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/smolder.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Smolder": 25,
        "Burning Brand": 25,
        "Spreading Flames": 25,
        "Conflagration": 25,
        "Raging Wildfire": 25,
        "Ferianth's Wildfire": 25
    ]));
    addSpecification("affected research type", "percentage");
}
