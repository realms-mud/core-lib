//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Ice Storm");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the ice storm technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a "
            "powerful ice storm that harries a foe.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/ice/freezing-barrier.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 33
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/frost-barrier.c", WeaponType),
                "name" : "Frost Barrier",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/frozen-barrier.c", WeaponType),
                "name" : "Frozen Barrier",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/icy-barrier.c", WeaponType),
                "name" : "Icy Barrier",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"skill",
                "name" : WeaponSkill,
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "elemental water",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"skill",
                "name" : "spellcraft",
                "formula" : "logarithmic",
                "rate" : 1.10
            ]),
            ([
                "type":"level",
                "name" : "level",
                "formula" : "logarithmic",
                "rate" : 1.10
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 240);
        addSpecification("spell point cost", 175);
        addSpecification("duration", 90);
        addSpecification("event handler", "iceStormEvent");
        addSpecification("command template", "ice storm [at ##Target##]");
        addSpecification("penalty to resist cold", 50);
        addSpecification("penalty to resist physical", 25);
        addSpecification("apply enfeebled", 1);
        addSpecification("apply slow", 1);

        addSpecification("use ability message", "A whirlwind of frigid ice erupts "
            "from ##InitiatorPossessive::Name## ##InitiatorWeapon## and engulfs "
            "##TargetName##.");
    }
}