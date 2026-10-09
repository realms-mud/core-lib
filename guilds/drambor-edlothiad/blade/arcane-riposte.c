//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Riposte");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches a devastating "
        "arcane  riposte technique that channels significant magical force "
            "into "
        "counter-attacks.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/mystic-guard.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 6);
    addSpecification("bonus defense", 6);
    addSpecification("bonus damage", 4);

    addSpecification("command template", "arcane riposte");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::enter## an arcane riposte stance, blade crackling "
        "with retaliatory energy.");
    addSpecification("use ability deactivate message", "The arcane riposte "
        "stance dissipates.");
}
