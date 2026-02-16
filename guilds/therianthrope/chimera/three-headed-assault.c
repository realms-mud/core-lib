//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Three-Headed Assault");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The three aspects of the chimera "
        "coordinate their attacks in deadly concert, each head and limb "
        "striking in perfect synchrony.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 43
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/chimeric-apotheosis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 20,
        "Gore": 20,
        "Fire Breath": 20,
        "Chimeric Rampage": 20,
        "Inferno": 20
    ]));
}
