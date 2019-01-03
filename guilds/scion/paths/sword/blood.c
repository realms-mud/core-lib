//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/soulspike.c");
    addResearchElement("lib/guilds/scion/paths/sword/blood/soulblade.c");

    addChild("lib/guilds/scion/paths/sword/blood/soulspike.c",
        "lib/guilds/scion/paths/sword/blood/root.c");
    addChild("lib/guilds/scion/paths/sword/blood/soulblade.c",
        "lib/guilds/scion/paths/sword/blood/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/sweeping-torment.c");

    addChild("lib/guilds/scion/paths/sword/blood/sweeping-torment.c",
        "lib/guilds/scion/paths/sword/blood/soulblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/soul-brand.c");

    addChild("lib/guilds/scion/paths/sword/blood/soul-brand.c",
        "lib/guilds/scion/paths/sword/blood/sweeping-torment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/scourge-blade.c");

    addChild("lib/guilds/scion/paths/sword/blood/scourge-blade.c",
        "lib/guilds/scion/paths/sword/blood/soul-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/wicked-edge.c");

    addChild("lib/guilds/scion/paths/sword/blood/wicked-edge.c",
        "lib/guilds/scion/paths/sword/blood/scourge-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/tortured-pommel.c");

    addChild("lib/guilds/scion/paths/sword/blood/tortured-pommel.c",
        "lib/guilds/scion/paths/sword/blood/wicked-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Blood");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as blood magic.");

        addResearchElement("lib/guilds/scion/paths/sword/blood/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/blood/root.c");

        FirstLevel();
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
