//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Champion");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the mantle of Ferianth's sacred champion, greatly amplifying "
        "the divine power behind area-effect conflagrations.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 41
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/righteous-fury.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
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
