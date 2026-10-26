//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rooted Anvil");
    addSpecification("source", "monk");
    addSpecification("description",
        "Sink your weight beneath the hammer and meet the "
        "exchange from a deeply settled stance. Like an "
        "anvil, the grounded body gives the falling head its purpose.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":26
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "disciple",
        "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/falling-head.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");

    addSpecification("bonus soak", 2);
    addSpecification("bonus attack", 1);

    addSpecification("stamina point cost", 12);

    addSpecification("per hit received cost", ([
        "stamina points":1
    ]));

    addSpecification("cooldown", 15);

    addSpecification("command template", "kata rooted anvil");
    addSpecification("use ability activate message",
        "##InitiatorName## assume##InitiatorReflexive## a rooted anvil "
        "stance.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## relax##InitiatorReflexive## the rooted anvil "
        "stance.");
}
