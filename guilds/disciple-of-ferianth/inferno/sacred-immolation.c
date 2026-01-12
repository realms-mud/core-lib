//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Immolation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "profound understanding of sacred fire's purifying nature, "
        "greatly enhancing high-tier immolation abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/flames-of-judgment.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Infernal Blast": 25,
        "Rain of Fire": 25,
        "Soulfire": 25,
        "Ferianth's Fury": 25,
        "Solar Flare": 25,
        "Purging Flames": 25,
        "Divine Conflagration": 25,
        "Wrath of Ferianth": 25,
        "Celestial Inferno": 25,
        "Apocalyptic Fire": 25
    ]));
    addSpecification("affected research type", "percentage");
}
