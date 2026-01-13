//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empowered Restoration");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "empowered knowledge of restoration magic, enhancing high-tier "
        "healing abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Holy Pyre": 20,
        "Sanctum of Flame": 20,
        "Ferianth's Embrace": 20,
        "Divine Absolution": 20,
        "Phoenix Ascension": 20,
        "Ferianth's Salvation": 20
    ]));
    addSpecification("affected research type", "percentage");
}
