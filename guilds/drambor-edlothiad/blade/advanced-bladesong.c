//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Advanced Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches an advanced form "
        "of  the bladesong, incorporating more complex arcane harmonics for "
        "greater offensive and defensive power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/bladesong-stance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 75);
    addSpecification("bonus attack", 8);
    addSpecification("bonus defense", 8);
    addSpecification("bonus parry", 5);
    addSpecification("bonus damage", 3);

    addSpecification("command template", "advanced bladesong");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::begin## an advanced bladesong, the melody more "
            "complex "
        "and powerful than before.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::allow## the advanced bladesong "
        "to fade into silence.");
}
