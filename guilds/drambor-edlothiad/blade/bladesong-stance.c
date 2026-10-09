//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bladesong Stance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the legendary "
        "bladesong  stance, where the battlemage's blade movements create a "
            "humming melody "
        "of arcane power that enhances both attack and defense.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spell-riposte.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 30);
    addSpecification("cooldown", 60);
    addSpecification("bonus attack", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus parry", 3);

    addSpecification("command template", "bladesong stance");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::begin## the bladesong, ##InitiatorPossessive## blade "
        "humming with arcane melody as it weaves through attack and "
            "defense.");
    addSpecification("use ability deactivate message", "The bladesong fades "
        "as ##InitiatorName## ##Infinitive::lower## ##InitiatorPossessive## "
            "stance.");
}
