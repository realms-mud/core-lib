//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Transcendence");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research pushes the battlemage "
        "beyond  mortal limits of elemental channeling, granting exceptional "
            "bonuses "
        "when wielding enchanted blades.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/elemental-supremacy.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 47
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus magical essence", 10);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 5);
    addSpecification("bonus spell points", 50);
}
