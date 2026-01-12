//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blinding Glory");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of infusing their flames with blinding radiance, "
        "enhancing attacks that combine fire with debilitating effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 49
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/sacred-champion.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Rain of Fire": 20,
        "Soulfire": 20,
        "Ferianth's Fury": 20,
        "Solar Flare": 20,
        "Purging Flames": 20,
        "Divine Conflagration": 20,
        "Wrath of Ferianth": 20,
        "Celestial Inferno": 20,
        "Apocalyptic Fire": 20
    ]));
    addSpecification("affected research type", "percentage");
}
