//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tri-Form Fury");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The three aspects of the chimera work "
        "in perfect concert, allowing you to strike with blinding speed "
        "from any angle.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 45
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/three-headed-assault.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Rending Claws": 1,
        "Gore": 1,
        "Fire Breath": 2,
        "Chimeric Rampage": 2,
        "Inferno": 3
    ]));
}
