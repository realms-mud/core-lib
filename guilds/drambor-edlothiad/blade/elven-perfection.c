//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Perfection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research draws on the innate elven "
        "pursuit of perfection in all arts.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 10);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus attack", 8);
    addSpecification("bonus defense", 6);
}
