//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Terror Incarnate");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ability to become terror incarnate, their very presence a weapon "
        "that assaults the minds of all who behold them.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 37 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/dream-devourer.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 5);
    addSpecification("bonus resist evil", 15);
}
