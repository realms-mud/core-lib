//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfection of Form");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves physical "
        "perfection through elven heritage.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/ethereal-movement.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 3);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus strength", 2);
}
