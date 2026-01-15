//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Wildfire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "supreme mastery of wildfire, greatly increasing the damage "
        "of high-level wildfire abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 41
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianth's Wildfire": 50,
        "Searing Devastation": 50,
        "Apocalyptic Firestorm": 50,
        "Ferianth's Eternal Pyre": 50
    ]));
    addSpecification("affected research type", "percentage");
}
