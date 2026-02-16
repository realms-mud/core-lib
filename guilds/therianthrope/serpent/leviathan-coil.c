//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Leviathan Coil");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your coils grow to leviathan proportions, "
        "capable of crushing enemies with the force of a tidal wave. Your "
        "physical attacks become devastatingly powerful.");

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

    addPrerequisite("/guilds/therianthrope/serpent/serpent-apotheosis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 10);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Constrict": 30,
        "Death Roll": 30,
    ]));
}
