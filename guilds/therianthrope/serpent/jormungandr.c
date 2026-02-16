//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Jormungandr");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of the legendary "
        "world-encircling serpent, gaining colossal strength and crushing "
        "power in your serpent form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/leviathan-coil.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 3);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 30,
        "Constrict": 35,
        "Spit Venom": 30,
        "Death Roll": 35,
        "Miasma": 30
    ]));
}
