//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bladesinger Elven Grace");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research channels the natural "
        "grace of elven heritage into the bladesinger's movements, granting "
        "enhanced dexterity and fluid motion through combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/resonant-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus defense", 4);
}
