//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private int isLevelAdvance = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void advanceLevel()
{
    isLevelAdvance = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if ((User->effectiveLevel() <= 1) &&
        !User->attributeValue("strength", 1) &&
        !User->attributeValue("intelligence", 1) &&
        !User->attributeValue("dexterity", 1) &&
        !User->attributeValue("wisdom", 1) &&
        !User->attributeValue("constitution", 1) &&
        !User->attributeValue("charisma", 1))
    {
        User->Str(2);
        User->Int(2);
        User->Wis(2);
        User->Dex(2);
        User->Con(2);
        User->Chr(2);
        User->addAttributePointsToSpend(18);
    }

    Description = isLevelAdvance ? "Advance your attributes" :
        "Choose your starting attributes";

    Data = ([
        "1":([
            "name": "Strength",
            "description": "The strength attribute represents how strong one is and their overall\nphysical prowess. It is used to determine:\n"
                "    - How much they can carry\n"
                "    - How easily they can bear a burden (encumberance)\n"
                "    - Damage inflicted by physical blows\n"
                "    - Ability to withstand physical blows\n"
                "    - Ability to learn certain skills - particularly combat skills\n"
                "    - Stamina\n"
                "    - Key abilities in many martial guilds\n"
        ]),
        "2":([
            "name": "Intelligence",
            "description": "The intelligence attribute represents one's mental aptitude.\nIt is used to determine:\n"
                "    - How many skill points they receive\n"
                "    - Damage inflicted by magical means\n"
                "    - Ability to land physical attacks in the most ideal locations\n"
                "    - Ability to learn certain skills - particularly magic, erudite,\n      crafting, and language skills\n"
                "    - Spell Points\n"
                "    - Key abilities in many thought and magic-based guilds\n"
        ]),
        "3":([
            "name": "Dexterity",
            "description": "The dexterity attribute represents one's stealth and nimbleness.\nIt is used to determine:\n"
                "    - Ability to land physical attacks\n"
                "    - Ability to avoid attacks\n"
                "    - Ability to learn certain skills - particularly combat and\n      subterfuge skills\n"
                "    - Key abilities in roguish guilds\n"
        ]),
        "4":([
            "name": "Wisdom",
            "description": "The wisdom attribute represents one's intuition, common sense,\nand decision-making. It is used to determine:\n"
                "    - Damage inflicted\n"
                "    - Ability to avoid attacks\n"
                "    - Ability to learn certain skills - particularly magic, general,\n      and crafting skills\n"
                "    - Spell Points\n"
                "    - Key abilities in many divine-based guilds\n"
        ]),
        "5":([
            "name": "Constitution",
            "description": "The constitution attribute represents one's physical toughness.\nIt is used to determine:\n"
                "    - Hit points\n"
                "    - Ability to withstand physical blows\n"
                "    - Many resistances, including magic, poison, and illness\n"
                "    - Ability to learn certain skills - particularly magic skills\n"
        ]),
        "6":([
            "name": "Charisma",
            "description": "The charisma attribute represents one's personality and ability to\nmanipulate others. It is used to determine:\n"
                "    - Other's default predisposition toward you\n"
                "    - Ability to manipulate conversations\n"
                "    - Faction and guild influence\n"
                "    - Ability to learn certain skills - particularly magic and\n      general skills\n"
                "    - Key abilities in many guilds\n"
        ])
    ]);

    if (isLevelAdvance)
    {
        Data["7"] = ([
            "name":"Exit Attribute Menu",
            "type": "exit",
            "description": "This option lets you exit the attribute advancement menu.\n"
        ]);
        Type = "Level up";
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return sprintf("You have %d point%s left to spend on attributes.\n",
        User ? User->attributePoints() : 0,
        (User && User->attributePoints() == 1) ? "" : "s");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    int attributeValue = User->attributeValue(lower_case(Data[choice]["name"]), 1);
    int max = 9 + User->effectiveLevel();

    return (Data[choice]["type"] == "exit") ? "" :
        configuration->decorate(sprintf("(current %s is %s%d)",
        Data[choice]["name"][0..2],
        ((attributeValue >= max) ? "at maximum of " : ""),
        attributeValue),
        ((attributeValue >= max) ? "blocked" : "selected"),
        "selector", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;

    if (User)
    {
        ret = (Data[selection]["type"] == "exit") ? 1 : -1;

        if ((ret < 1) && 
            User->spendAttributePoints(lower_case(Data[selection]["name"]), 1))
        {
            ret = User->attributePoints() == 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void undoSelection(string selection)
{
    if (User)
    {
        User->spendAttributePoints(lower_case(Data[selection]["name"]), -1);
    }
}
