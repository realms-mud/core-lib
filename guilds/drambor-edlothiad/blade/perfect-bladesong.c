//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Bladesong");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the perfect "
        "bladesong,  a flawless synthesis of blade and magic that represents "
            "the highest "
        "achievement of spellblade martial art.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/advanced-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("stamina point cost", 60);
    addSpecification("cooldown", 90);
    addSpecification("bonus attack", 12);
    addSpecification("bonus defense", 12);
    addSpecification("bonus parry", 8);
    addSpecification("bonus damage", 6);
    addSpecification("bonus dodge", 4);

    addSpecification("command template", "perfect bladesong");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::achieve## the perfect bladesong, blade and magic "
        "merging into a flawless symphony of combat.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::release## the perfect bladesong, "
        "the flawless harmony dissolving into stillness.");
}
