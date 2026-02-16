//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Molten Core");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The fire within your chimera form burns "
        "with the intensity of a molten core, granting powerful regeneration "
        "and elemental mastery.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/ashen-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points", 10);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal spell points rate", 3);
    addSpecification("bonus heal stamina rate", 3);
    addSpecification("bonus resist fire", 10);
    addSpecification("bonus resist cold", 5);
    addSpecification("bonus fire attack", 20);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fire Breath": 35,
        "Inferno": 35,
    ]));
}
