//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of the Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the ultimate "
        "embodiment of the bladesong tradition.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-creation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 70
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 10);
    addSpecification("bonus defense", 10);
    addSpecification("bonus long sword", 12);
    addSpecification("bonus spellcraft", 12);
}
