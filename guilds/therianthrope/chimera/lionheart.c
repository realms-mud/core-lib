//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lionheart");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The predatory instincts of the chimera "
        "sharpen, granting heightened combat awareness and ferocity while "
        "transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 29
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/burning-blood.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 15,
        "Gore": 15,
        "Fire Breath": 15,
        "Chimeric Rampage": 15,
        "Inferno": 15
    ]));
}
