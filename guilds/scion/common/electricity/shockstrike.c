//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Shock Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the shock strike technique. By means of this, the "
            "Scion is able to emit a constant electrical current from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/electricity/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType),
                "name" : "sweeping shock",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.67
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType),
                "name" : "shock brand",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.4
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/energized-strike.c", WeaponType),
                "name" : "energized strike",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.4
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType),
                "name" : "shocking edge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.4
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/electricity/thunders-boon.c", WeaponType),
                "name" : "Thunder's Boon",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 2.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 30);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 50);
        addSpecification("command template", "shock strike");

        addSpecification("bonus electricity enchantment", 3);
        addSpecification("bonus resist electricity", 3);

        addSpecification("use ability activate message", "Thin tendrils of "
            "electricity wrap around ##InitiatorPossessive::Name## "
            "##InitiatorWeapon##.");
        addSpecification("use ability deactivate message", "The thin tendrils of "
            "electricity around ##InitiatorPossessive::Name## "
            "##InitiatorWeapon## subside.");
    }
}
