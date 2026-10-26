//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Circling Talon");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hold the claw frame before you as though turning a small "
        "wheel. Your gaze follows the foe around its rim, keeping "
        "the body sheltered rather than reaching after an uncertain kill.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":51
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/claw-footwork.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);

    addSpecification("command template", "kata circling talon");

    addSpecification("bonus defense", 6);
    addSpecification("penalty to attack", 2);
}
