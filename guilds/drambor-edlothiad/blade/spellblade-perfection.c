//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spellblade Perfection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the perfection "
        "of  the spellblade art, granting exceptional mastery in all aspects "
        "of magical combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/battlemage-supremacy.c",
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
    addSpecification("bonus attack", 10);
    addSpecification("bonus defense", 8);
    addSpecification("bonus damage", 8);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus long sword", 8);
    addSpecification("bonus spell points", 75);
}
