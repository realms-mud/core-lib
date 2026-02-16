//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basilisk Gaze");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your gaze takes on the petrifying "
        "quality of the legendary basilisk, weakening those who dare meet "
        "your eyes and enhancing your venomous attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 43
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/necrotic-venom.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus poison enchantment", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus defense", 3);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 30,
        "Spit Venom": 30,
        "Miasma": 30,
    ]));
}
