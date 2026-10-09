//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Guard");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches an advanced "
        "defensive  technique that layers multiple arcane wards through "
            "blade movements, "
        "creating a near-impenetrable mystic guard.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/bladesong-stance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("stamina point cost", 35);
    addSpecification("cooldown", 75);
    addSpecification("bonus defense", 8);
    addSpecification("bonus parry", 5);
    addSpecification("bonus resist magical", 5);

    addSpecification("command template", "mystic guard");
    addSpecification(
        "use ability activate message",
        "Layers of arcane energy "
        "takes shape.");
    addSpecification("use ability deactivate message", "The mystic guard "
        "dissipates.");
}
