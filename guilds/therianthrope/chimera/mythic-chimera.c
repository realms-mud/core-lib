//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mythic Chimera");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your chimera form reaches its ultimate "
        "potential, embodying the primordial mythic chimera of legend. "
        "Your claws can rend mountains, your horns can shatter walls, "
        "and your breath can melt stone.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 67
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/chimera-ascendant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 200);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus claw attack", 30);
    addSpecification("bonus teeth attack", 30);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 35,
        "Gore": 35,
        "Fire Breath": 35,
        "Chimeric Rampage": 35,
        "Inferno": 35
    ]));
}
