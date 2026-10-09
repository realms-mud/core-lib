//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empowered Strikes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research empowers all spell "
        "strikes with greater potency.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/corrosive-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 3);
    addSpecification("bonus spellcraft", 3);
}
