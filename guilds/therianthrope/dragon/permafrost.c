//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Permafrost");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your frost attacks linger with a "
        "permafrost chill, deepening their impact and extending their "
        "devastation.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 47
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/frozen-blight.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 2);

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
