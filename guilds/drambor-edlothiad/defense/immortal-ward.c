//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the immortal ward, a legendary "
        "protective enchantment said to be "
        "indestructible. The battlemage sustains "
        "this barrier through sheer force of will "
        "and an inexhaustible connection to the "
        "deep currents of magical power that flow "
        "beneath the world.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "aegis-of-the-ancients.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 7);
    addSpecification("bonus resist physical", 7);
    addSpecification("bonus resist magical", 7);
}
