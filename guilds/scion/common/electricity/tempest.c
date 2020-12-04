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
        addSpecification("name", "Tempest");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the tempest technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a "
            "powerful storm that harries a foe.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/electricity/shocking-barrier.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 33
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType),
                "name" : "Static Charge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType),
                "name" : "Ionization",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/plasma-barrier.c", WeaponType),
                "name" : "Plasma Eruption",
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
        addSpecification("cooldown", 240);
        addSpecification("spell point cost", 175);
        addSpecification("duration", 90);
        addSpecification("event handler", "tempestEvent");
        addSpecification("command template", "tempest [at ##Target##]");
        addSpecification("penalty to resist electricity", 50);
        addSpecification("penalty to resist physical", 25);
        addSpecification("apply enfeebled", 1);
        addSpecification("apply slow", 1);

        addSpecification("use ability message", "A wave of plasma and electricity erupts "
            "from ##InitiatorPossessive::Name## ##InitiatorWeapon## and engulfs "
            "##TargetName##.");
    }
}
