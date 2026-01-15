//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wildfire Intensity");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to increase the duration of all wildfire effects, "
        "causing flames to burn longer.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 25
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Smolder": 1,
        "Burning Brand": 1,
        "Spreading Flames": 1,
        "Conflagration": 1,
        "Raging Wildfire": 1,
        "Ferianth's Wildfire": 1,
        "Searing Devastation": 1,
        "Apocalyptic Firestorm": 1,
        "Ferianth's Eternal Pyre": 1
    ]));
    addSpecification("affected research type", "increase repeat effect");
}
