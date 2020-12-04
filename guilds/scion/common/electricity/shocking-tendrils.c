//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        addSpecification("name", "Shocking Tendrils");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the shocking tendrils technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting electric "
            "energy that swarms around a foe.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 5
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType),
                "name" : "Static Barrier",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType),
                "name" : "Ionized multiplicative",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/plasma-barrier.c", WeaponType),
                "name" : "Plasma Barrier",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.5
            ]),
            ([
                "type":"skill",
                "name" : WeaponSkill,
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "elemental air",
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
        addSpecification("cooldown", 120);
        addSpecification("duration", 60);
        addSpecification("spell point cost", 35);
        addSpecification("event handler", "shockingTendrilsEvent");
        addSpecification("command template", "shocking tendrils [at ##Target##]");
        addSpecification("penalty to resist electricity", 10);
        addSpecification("penalty to resist physical", 5);

        addSpecification("use ability message", "Sinuous tendrils of "
            "electricity spray from ##InitiatorPossessive::Name## "
            "##InitiatorWeapon##, engulfing ##TargetName##.");
    }
}
