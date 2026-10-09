//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Blade Singer");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research marks the achievement of "
        "legendary blade singer status.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/starlight-dancer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 61
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 8);
    addSpecification("bonus defense", 8);
    addSpecification("bonus long sword", 10);
}
