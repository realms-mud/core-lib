//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Restorative Focus");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "focused knowledge of restorative flames, enhancing all healing "
        "abilities with additional potency.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 29
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Rejuvenating Blaze": 25,
        "Sanctified Restoration": 25,
        "Purgatory Embrace": 25,
        "Phoenix Blessing": 25,
        "Fires of Renewal": 25,
        "Holy Pyre": 25,
        "Ferianth's Embrace": 25,
        "Divine Absolution": 25,
        "Phoenix Ascension": 25,
        "Ferianth's Salvation": 25
    ]));
    addSpecification("affected research type", "percentage");
}
