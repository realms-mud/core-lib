//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Restoration");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "mastery of divine restoration, maximizing the power of the most "
        "powerful healing abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ferianth's Embrace": 20,
        "Divine Absolution": 20,
        "Phoenix Ascension": 20,
        "Ferianth's Salvation": 20
    ]));
    addSpecification("affected research type", "percentage");
}
