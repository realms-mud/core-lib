//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unbreakable Song");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research makes the blade singer's "
        "defenses nearly unbreakable.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/invincible-harmony.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus armor class", 5);
    addSpecification("bonus parry", 5);
}
