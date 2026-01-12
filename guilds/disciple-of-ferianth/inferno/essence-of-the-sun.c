//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Essence of the Sun");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "mastery over solar fire, allowing them to channel the very "
        "essence of the sun through their most devastating abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 53
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/sacred-immolation.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
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
