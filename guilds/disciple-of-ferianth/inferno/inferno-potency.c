//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "deeper knowledge of inferno magic, enhancing the power of "
        "mid-tier fire abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 13
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Flame Touch": 25,
        "Fire Bolt": 25,
        "Burning Hands": 25,
        "Fireball": 25,
        "Pillar of Fire": 25,
        "Flame Strike": 25,
        "Fire Storm": 25
    ]));
    addSpecification("affected research type", "percentage");
}
