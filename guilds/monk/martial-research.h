//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/guilds/monk/research-support.h"

protected string martialSkill(string discipline)
{
    string skill = ([
        "unarmed":"unarmed",
        "katana":"hand and a half sword",
        "paired-swords":"hand and a half sword",
        "odachi":"two-handed sword",
        "archery":"bow",
        "kama":"short sword",
        "claw":"dagger"
    ])[discipline];
    if (!skill)
    {
        raise_error("Unsupported monk martial discipline: " + discipline +
            "\n");
    }
    return skill;
}

protected void martialResearch(string name, string description, int level,
    int cost, string parent, string discipline)
{
    martialSkill(discipline);
    mapping limiter;
    if (discipline == "unarmed")
    {
        limiter = ([
            "empty equipment slots":({ "wielded primary", "wielded offhand" })
        ]);
    }
    else if (discipline == "archery")
    {
        limiter = ([
            "equipment":([ "type":"bow",
                "slot":"wielded primary" ])
        ]);
    }
    else if (discipline == "paired-swords")
    {
        limiter = ([
            "equipment":({
                ([ "blueprint":"katana", "slot":"wielded primary" ]),
                ([ "blueprint":"wakisashi", "slot":"wielded offhand" ])
            })
        ]);
    }
    else
    {
        limiter = ([
            "equipment":([ "blueprint":discipline == "claw" ?
                "tiger claws" : discipline,
                "slot":"wielded primary" ])
        ]);
    }
    monkResearch(name, description, level, cost,
        "/guilds/monk/" + discipline + "/" + parent + ".c", limiter);
}

protected void martialAttack(string name, string description, int level,
    string parent, string discipline, string effect, int amount, int range,
    int stamina, int cooldown, string theory)
{
    martialResearch(name, description, level, 3, parent, discipline);
    string command = "kata " + lower_case(name);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", stamina);
    addSpecification("cooldown", cooldown);
    addSpecification("command template", command + " at ##Target##");
    addSpecification("usage summary", command + " at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## " +
        lower_case(name) + " against ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type",
        discipline == "unarmed" ? "physical" :
            discipline == "archery" ? "arrow" :
                discipline == "claw" ? "thrust" : "slash");
    if (discipline == "archery")
    {
        addSpecification("consumables", ([ "arrow":1 ]));
    }
    addSpecification(effect, ({
        ([ "probability":100, "base damage":amount, "range":range ])
    }));
    mapping *modifiers = ({
        ([
            "type":"skill",
            "name":martialSkill(discipline),
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":effect == "damage spell points" ? "wisdom" :
                member(({ "paired-swords", "archery", "kama", "claw" }),
                    discipline) >= 0 ?
                    "dexterity" : "strength",
            "formula":"additive",
            "rate":0.1
        ])
    });
    if (discipline != "unarmed")
    {
        modifiers += ({ ([
            "type":"weapon damage",
            "name":discipline,
            "types":({ martialSkill(discipline) }),
            "formula":"additive",
            "rate":discipline == "paired-swords" ? 0.35 : 0.5
        ]) });
    }
    if (discipline == "paired-swords")
    {
        modifiers += ({ ([
            "type":"offhand damage",
            "name":"wakisashi",
            "types":({ "short sword" }),
            "formula":"additive",
            "rate":0.2
        ]) });
    }
    if (theory)
    {
        modifiers += ({ ([
            "type":"research",
            "name":theory,
            "research item":"/guilds/monk/" + discipline + "/" +
                theory + ".c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]) });
    }
    addSpecification("modifiers", modifiers);
}

protected void martialTheory(string name, string description, int level,
    string parent, string discipline, string affected, string modifier,
    int amount)
{
    martialResearch(name, description, level, 2, parent, discipline);
    addSpecification("related research", ({
        "/guilds/monk/" + discipline + "/" + parent + ".c"
    }));
    addSpecification("affected research type", modifier);
    addSpecification("affected research", ([ affected:amount ]));
}
