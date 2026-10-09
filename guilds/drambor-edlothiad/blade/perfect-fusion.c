//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Fusion");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the absolute "
        "apex  of the spellblade art. Blade and magic become one, and the "
        "battlemage transcends the distinction between warrior and mage.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/perfect-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);
    addSpecification("stamina point cost", 100);
    addSpecification("cooldown", 120);
    addSpecification("bonus attack", 18);
    addSpecification("bonus defense", 18);
    addSpecification("bonus parry", 12);
    addSpecification("bonus damage", 10);
    addSpecification("bonus dodge", 8);
    addSpecification("bonus hit points", 100);

    addSpecification("command template", "perfect fusion");
    addSpecification("use ability activate message", "Blade and magic merge "
        "into perfect unity as ##InitiatorName## ##Infinitive::achieve## the "
        "legendary Perfect Fusion of the Drambor Edlothiad.");
    addSpecification("use ability deactivate message", "The Perfect Fusion "
        "unravels as blade and magic separate once more.");
}
