//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Refuge Posture");
    addSpecification("source", "monk");
    addSpecification("description",
        "Fold your stance around an unbroken line of breath. The shield "
        "draws close, its light gathering into overlapping folds through "
        "which hostile workings struggle to find a path.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":26
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/refuge-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 8);

    addSpecification("bonus resist magical", 8);
    addSpecification("bonus soak", 4);
    addSpecification("penalty to attack", 1);

    addSpecification("command template", "chi refuge posture");
    addSpecification("use ability activate message",
        "##InitiatorName## assume##InitiatorReflexive## a refuge posture.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## leave##InitiatorReflexive## the refuge posture.");
}
