//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Precision of the Ancients");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research draws on ancient elven "
        "blade  techniques, granting exceptional precision in combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/elven-swordcraft.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 5);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);
}
