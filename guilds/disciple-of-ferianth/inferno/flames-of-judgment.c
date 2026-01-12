//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flames of Judgment");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of channeling Ferianth's righteous judgment through "
        "fire, enhancing the power of wrathful flame attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/pyromaniacs-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Immolation": 25,
        "Hellfire": 25,
        "Blazing Wrath": 25,
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
