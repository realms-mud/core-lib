//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/sparks.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shockblade.c");

    addChild("lib/guilds/scion/paths/sword/electricity/sparks.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
    addChild("lib/guilds/scion/paths/sword/electricity/shockblade.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/sweeping-shock.c");

    addChild("lib/guilds/scion/paths/sword/electricity/sweeping-shock.c",
        "lib/guilds/scion/paths/sword/electricity/shockblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shock-brand.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shock-brand.c",
        "lib/guilds/scion/paths/sword/electricity/sweeping-shock.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/energized-blade.c");

    addChild("lib/guilds/scion/paths/sword/electricity/energized-blade.c",
        "lib/guilds/scion/paths/sword/electricity/shock-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shocking-edge.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shocking-edge.c",
        "lib/guilds/scion/paths/sword/electricity/energized-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/thunders-pommel.c");

    addChild("lib/guilds/scion/paths/sword/electricity/thunders-pommel.c",
        "lib/guilds/scion/paths/sword/electricity/shocking-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Bolt");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as electrical power.");

        addResearchElement("lib/guilds/scion/paths/sword/electricity/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/electricity/root.c");

        FirstLevel();
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
