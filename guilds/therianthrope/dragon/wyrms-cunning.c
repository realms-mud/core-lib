//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wyrm's Cunning");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The ancient cunning of the silver wyrm "
        "sharpens your combat instincts, granting heightened awareness "
        "while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/frost-breath.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 15,
        "Tail Lash": 15,
        "Frost Breath": 15,
        "Soul Freeze": 15,
        "Frozen Blight": 15,
        "Glacial Tempest": 15
    ]));
}
