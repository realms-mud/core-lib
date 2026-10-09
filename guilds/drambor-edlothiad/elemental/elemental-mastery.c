//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents a comprehensive "
        " mastery of elemental channeling through bladed weapons, granting "
        "substantial combat bonuses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/elemental-resonance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus magical essence", 8);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 3);
}
