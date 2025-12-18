//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rapid Combustion");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Your flame conduit form has become so "
        "attuned to divine fire that you can manifest your abilities more "
        "rapidly, reducing cooldown times while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 25
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/conduit-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    // Reduces cooldowns of form abilities
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Flame Burst": 2,
        "Immolating Grasp": 3,
        "Blazing Teleport": 5,
        "Inferno Nova": 4,
        "Phoenix Rebirth": 30
    ]));
}
