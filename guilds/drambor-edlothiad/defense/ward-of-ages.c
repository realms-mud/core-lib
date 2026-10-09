//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward of Ages");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ward of ages, a defensive "
        "technique perfected over millennia of elven "
        "warfare. This layered enchantment hardens "
        "with each passing moment, growing ever more "
        "impenetrable as it draws upon the weight "
        "of accumulated time.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "temporal-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist magical", 5);
}
