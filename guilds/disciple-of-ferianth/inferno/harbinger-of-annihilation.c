//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harbinger of Annihilation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the ultimate understanding of apocalyptic destruction, "
        "maximizing the devastating power of the most cataclysmic abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 65
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/divine-judgment.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Wrath of Ferianth": 25,
        "Celestial Inferno": 25,
        "Apocalyptic Fire": 25
    ]));
    addSpecification("affected research type", "percentage");
}
