//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blade Singer's Perfection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves martial "
        "perfection through the bladesong.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/supreme-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus damage", 5);
}
