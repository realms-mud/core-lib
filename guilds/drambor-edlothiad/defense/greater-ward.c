//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Greater Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the greater ward, an advanced "
        "protective enchantment that surrounds the "
        "battlemage in a constantly shifting shell "
        "of defensive energy. This ward intelligently "
        "strengthens itself at the point of impact, "
        "concentrating power where it is most needed "
        "at any given moment.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "elven-bulwark.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist physical", 4);
    addSpecification("bonus resist magical", 3);
}
