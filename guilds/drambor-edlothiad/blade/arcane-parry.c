//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Parry");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "reinforce parries with arcane energy, creating a shimmering barrier "
        "along the blade that deflects attacks more effectively.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 1
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 30);
    addSpecification("bonus defense", 3);
    addSpecification("bonus parry", 2);

    addSpecification("command template", "arcane parry");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## blade in an arcane "
            "parry "
        "stance, the edge shimmering with defensive magic.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::lower## ##InitiatorPossessive## arcane parry stance.");
}
