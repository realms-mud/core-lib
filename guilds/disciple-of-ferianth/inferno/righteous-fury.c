//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Righteous Fury");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "knowledge of channeling righteous anger into their flames, "
        "significantly enhancing the raw destructive power of fire attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 33
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/pyromaniacs-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Immolation": 30,
        "Hellfire": 30,
        "Infernal Blast": 30,
        "Rain of Fire": 30,
        "Ferianth's Fury": 30,
        "Solar Flare": 30,
        "Divine Conflagration": 30,
        "Wrath of Ferianth": 30,
        "Apocalyptic Fire": 30
    ]));
    addSpecification("affected research type", "percentage");
}
