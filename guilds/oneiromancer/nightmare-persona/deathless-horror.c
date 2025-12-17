//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deathless Horror");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "aspect of a deathless horror, an entity of nightmare that endures "
        "beyond all attempts to destroy it.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 65 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/immortal-nightmare.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 20);
    addSpecification("bonus soak", 12);
    addSpecification("bonus resist psionic", 35);
    addSpecification("bonus resist evil", 30);
}
