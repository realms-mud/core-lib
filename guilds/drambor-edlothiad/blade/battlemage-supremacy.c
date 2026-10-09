//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battlemage Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the peak of "
        "spellblade martial prowess, granting substantial combat bonuses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/war-caster.c",
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
    addSpecification("bonus attack", 8);
    addSpecification("bonus defense", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus long sword", 5);
}
