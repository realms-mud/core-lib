//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        addSpecification("name", "Lightning Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the lightning strike technique. By means of this, the "
            "Scion is able to emit a strong, constant electrical current from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/electricity/shockblade.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType),
                "name" : "sweeping shock",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType),
                "name" : "shock brand",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/electricity/energized-blade.c", WeaponType),
                "name" : "energized blade",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType),
                "name" : "shocking edge",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/electricity/thunders-pommel.c", WeaponType),
                "name" : "Thunder's Pommel",
                "formula" : "additive",
                "base value" : 6,
                "rate": 1.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 180);
        addSpecification("spell point cost", 50);
        addSpecification("stamina point cost", 200);
        addSpecification("command template", "lightning strike");
        addSpecification("bonus electricity enchantment", 10);
        addSpecification("bonus resist electricity", 25);

        addSpecification("use ability activate message", "Crawling tendrils of "
            "lightning wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
        addSpecification("use ability deactivate message", "The tendrils of "
            "lightning around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
    }
}
