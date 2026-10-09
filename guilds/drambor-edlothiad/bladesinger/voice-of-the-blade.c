//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Voice of the Blade");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the blade singer "
        "to hear the voice of the blade itself.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/transcendent-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 4);
    addSpecification("bonus parry", 4);
}
