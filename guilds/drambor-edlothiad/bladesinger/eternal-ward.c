//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the eternal ward, a harmonic "
        "protection technique passed down through "
        "countless generations. The bladesinger "
        "sustains a perpetual undertone that "
        "resonates with the fabric of reality "
        "itself, creating an enduring shield that "
        "never falters or fades.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/"
        "defensive-harmonics.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist magical", 5);
}
