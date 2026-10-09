//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Riposte");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "counter enemy attacks with a magical riposte, channeling arcane "
        "energy into a devastating counterattack.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-parry.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 45);
    addSpecification("bonus attack", 4);
    addSpecification("bonus defense", 2);

    addSpecification("command template", "spell riposte");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::adopt## a spell riposte stance, ready to counter "
        "with arcane-charged strikes.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::relax## from the spell riposte stance.");
}
