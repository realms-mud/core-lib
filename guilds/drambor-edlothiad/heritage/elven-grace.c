//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Grace");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the natural grace inherent to "
        "all elves. Through conscious cultivation "
        "of this birthright, the battlemage moves "
        "with a liquid fluidity that makes even "
        "the most complex maneuvers appear "
        "effortless and serene.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus dodge", 1);
}
