//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of the Eldar");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research becomes the living "
        "avatar of the ancient Eldar.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/eternal-lineage.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 70
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 150);
    addSpecification("bonus spell points", 150);
    addSpecification("bonus stamina points", 100);
    addSpecification("bonus attack", 5);
    addSpecification("bonus defense", 5);
}
