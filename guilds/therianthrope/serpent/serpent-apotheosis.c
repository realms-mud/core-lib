//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpent Apotheosis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your serpent form transcends the merely "
        "physical, becoming an avatar of ophidian perfection with "
        "devastating speed and lethal precision.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 39
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/ophidian-swiftness.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus poison enchantment", 2);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Fanged Bite": 25,
        "Constrict": 25,
        "Spit Venom": 25,
        "Death Roll": 25,
        "Miasma": 25
    ]));
}
