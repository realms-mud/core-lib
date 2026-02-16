//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chimeric Apotheosis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your chimera form transcends the merely "
        "physical, becoming an avatar of composite destruction with "
        "searing fire and savage precision.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 41
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/blazing-mane.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus fire enchantment", 2);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 25,
        "Gore": 25,
        "Fire Breath": 25,
        "Chimeric Rampage": 25,
        "Inferno": 25
    ]));
}
