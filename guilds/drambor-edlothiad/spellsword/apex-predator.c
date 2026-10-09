//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Apex Predator");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the mindset of an apex predator "
        "in magical combat. The spell sword learns "
        "to perceive every confrontation as a hunt, "
        "reading an opponent's magical and physical "
        "tells to identify the precise moment when "
        "a devastating spell-strike will end the "
        "engagement in a single blow.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "spell-strike-supremacy.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 61
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 5);
}
