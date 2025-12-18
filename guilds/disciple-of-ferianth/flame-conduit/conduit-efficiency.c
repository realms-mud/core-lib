//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conduit Efficiency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Your mastery of the flame conduit form "
        "allows you to channel Ferianth's fire more efficiently, reducing "
        "the cost of abilities used while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/inner-fire-mastery.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    // Reduces cost of form abilities
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Flame Burst": 5,
        "Immolating Grasp": 8,
        "Blazing Teleport": 10,
        "Inferno Nova": 12,
        "Phoenix Rebirth": 15
    ]));
}
