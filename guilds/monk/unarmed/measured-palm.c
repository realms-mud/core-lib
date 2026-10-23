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
    addSpecification("name", "Measured Palm");
    addSpecification("description", "A deliberate single palm strike using "
        "normal physical damage resolution. Both wielded slots must be "
        "empty; worn gloves and armor are allowed.");
    addSpecification("source", "monk");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 8);
    addSpecification("command template", "kata measured palm at ##Target##");
    addSpecification("usage summary", "kata measured palm at <target>");
    addSpecification("use ability message",
        "##InitiatorName## strike##InitiatorReflexive## "
        "##TargetName## with a measured palm.");
    addSpecification("observation type", "combat.kata");
    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));
    addSpecification("damage type", "physical");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":12, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"unarmed",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.1 ])
    }));
}
