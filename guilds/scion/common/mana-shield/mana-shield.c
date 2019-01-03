//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/common/mana-shield/gift-of-dhuras.c");

    addChild("lib/guilds/scion/common/mana-shield/gift-of-dhuras.c",
        "lib/guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/common/mana-shield/boon-of-dhuras.c");

    addChild("lib/guilds/scion/common/mana-shield/boon-of-dhuras.c",
        "lib/guilds/scion/common/mana-shield/gift-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/common/mana-shield/mana-shroud.c");

    addChild("lib/guilds/scion/common/mana-shield/mana-shroud.c",
        "lib/guilds/scion/common/mana-shield/boon-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/common/mana-shield/hopes-embrace.c");

    addChild("lib/guilds/scion/common/mana-shield/hopes-embrace.c",
        "lib/guilds/scion/common/mana-shield/mana-shroud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/common/mana-shield/blessing-of-dhuras.c");

    addChild("lib/guilds/scion/common/mana-shield/blessing-of-dhuras.c",
        "lib/guilds/scion/common/mana-shield/hopes-embrace.c");
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

        addResearchElement("lib/guilds/scion/common/mana-shield/root.c");
        TreeRoot("lib/guilds/scion/common/mana-shield/root.c");

        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
        TwentyFifthLevel();
    }
}
