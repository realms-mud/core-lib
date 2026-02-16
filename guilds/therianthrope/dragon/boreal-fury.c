//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boreal Fury");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the fury of the boreal "
        "winds, gaining devastating offensive power in your dragon form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/permafrost.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus cold enchantment", 2);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 25,
        "Tail Lash": 25,
        "Frost Breath": 25,
        "Soul Freeze": 25,
        "Frozen Blight": 25,
        "Glacial Tempest": 25
    ]));
}
