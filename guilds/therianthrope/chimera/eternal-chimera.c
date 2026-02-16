//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Chimera");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The offensive and defensive paths of the "
        "chimera merge into one unified, eternal form. You are an avatar of "
        "composite destruction, wielding claws, horns, and fire with "
        "unmatched mastery.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 55
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/chimera-tyrant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 35,
        "Gore": 35,
        "Fire Breath": 35,
        "Chimeric Rampage": 35,
        "Inferno": 35
    ]));
}
