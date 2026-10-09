//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Fortress");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "create an impenetrable fortress of arcane energy through blade "
        "movements, offering supreme magical and physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-riposte.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 130);
    addSpecification("stamina point cost", 65);
    addSpecification("cooldown", 90);
    addSpecification("bonus defense", 15);
    addSpecification("bonus parry", 10);
    addSpecification("bonus resist magical", 10);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist cold", 5);
    addSpecification("bonus resist electricity", 5);

    addSpecification("command template", "arcane fortress");
    addSpecification("use ability activate message", "Layers of interlocking "
        "arcane wards spring from ##InitiatorPossessive## blade movements, "
        "forming an impenetrable fortress of magical energy.");
    addSpecification("use ability deactivate message", "The arcane fortress "
        "crumbles away.");
}
