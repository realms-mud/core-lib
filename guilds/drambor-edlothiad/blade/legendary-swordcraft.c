//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Swordcraft");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents legendary skill "
        " with the blade, known only to the greatest battlemages.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/elven-perfection.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 61
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 12);
    addSpecification("bonus attack", 10);
    addSpecification("bonus defense", 8);
    addSpecification("bonus damage", 8);
    addSpecification("bonus parry", 6);
}
