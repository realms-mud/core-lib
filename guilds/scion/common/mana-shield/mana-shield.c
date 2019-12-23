//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/scion/common/mana-shield/gift-of-dhuras.c");

    addChild("guilds/scion/common/mana-shield/gift-of-dhuras.c",
        "guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/scion/common/mana-shield/boon-of-dhuras.c");

    addChild("guilds/scion/common/mana-shield/boon-of-dhuras.c",
        "guilds/scion/common/mana-shield/gift-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/scion/common/mana-shield/mana-shroud.c");

    addChild("guilds/scion/common/mana-shield/mana-shroud.c",
        "guilds/scion/common/mana-shield/boon-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/scion/common/mana-shield/hopes-embrace.c");

    addChild("guilds/scion/common/mana-shield/hopes-embrace.c",
        "guilds/scion/common/mana-shield/mana-shroud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/scion/common/mana-shield/blessing-of-dhuras.c");

    addChild("guilds/scion/common/mana-shield/blessing-of-dhuras.c",
        "guilds/scion/common/mana-shield/hopes-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Mana Shield");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as a magical shield.");

        addResearchElement("guilds/scion/common/mana-shield/root.c");
        TreeRoot("guilds/scion/common/mana-shield/root.c");

        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
        TwentyFifthLevel();
    }
}
