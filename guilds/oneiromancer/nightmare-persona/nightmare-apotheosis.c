//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Apotheosis");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "pinnacle of defensive nightmare power. They have achieved apotheosis, "
        "becoming one with the nightmare realm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 45 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/terror-incarnate.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 15);
    addSpecification("bonus soak", 8);
    addSpecification("bonus resist psionic", 30);
    addSpecification("bonus resist evil", 20);
}
