//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":10 ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/discipline/students-awareness.c",
        ([ "type":"research" ]));
    addSpecification("name", "Focused Pulse");
    addSpecification("description", "Project a focused pulse of internal "
        "energy at an opponent, spending spell points through the normal "
        "resource and energy-damage systems. No separate chi pool is used.");
    addSpecification("source", "monk");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 6);
    addSpecification("cooldown", 8);
    addSpecification("command template", "chi focused pulse at ##Target##");
    addSpecification("usage summary", "chi focused pulse at <target>");
    addSpecification("use ability message",
        "##InitiatorName## direct##InitiatorReflexive## a focused pulse "
        "of energy at ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":12, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.1 ])
    }));
}
