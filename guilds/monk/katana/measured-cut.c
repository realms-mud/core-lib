//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":5 ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "student", "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c",
        ([ "type":"research" ]));
    addSpecification("name", "Measured Cut");
    addSpecification("description", "A controlled single cut using the "
        "katana in your primary wielded slot. Your offhand is unrestricted. "
        "The cut uses normal slashing damage resolution and scales with "
        "your primary weapon, sword skill, and strength.");
    addSpecification("source", "monk");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 8);
    addSpecification("command template", "kata measured cut at ##Target##");
    addSpecification("usage summary", "kata measured cut at <target>");
    addSpecification("use ability message",
        "##InitiatorName## cut##InitiatorReflexive## "
        "##TargetName## with a measured katana strike.");
    addSpecification("observation type", "combat.kata");
    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":8, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"weapon damage", "name":"katana",
            "types":({ "hand and a half sword" }),
            "formula":"additive", "rate":0.5 ]),
        ([ "type":"skill", "name":"hand and a half sword",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.1 ])
    }));
}
