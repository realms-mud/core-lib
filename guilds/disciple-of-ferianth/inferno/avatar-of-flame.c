//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Flame");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "the ultimate understanding of Ferianth's sacred fire, allowing "
        "them to become a living conduit for divine conflagration.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 61
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/essence-of-the-sun.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Divine Conflagration": 25,
        "Wrath of Ferianth": 25,
        "Celestial Inferno": 25,
        "Apocalyptic Fire": 25
    ]));
    addSpecification("affected research type", "percentage");
}
