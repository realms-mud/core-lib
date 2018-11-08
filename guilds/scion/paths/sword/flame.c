//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/flames.c");
    addResearchElement("lib/guilds/scion/paths/sword/flame/flameblade.c");

    addChild("lib/guilds/scion/paths/sword/flame/flames.c",
        "lib/guilds/scion/paths/sword/flame/root.c");
    addChild("lib/guilds/scion/paths/sword/flame/flameblade.c",
        "lib/guilds/scion/paths/sword/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/sweeping-flames.c");

    addChild("lib/guilds/scion/paths/sword/flame/sweeping-flames.c",
        "lib/guilds/scion/paths/sword/flame/flameblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/flame-brand.c");

    addChild("lib/guilds/scion/paths/sword/flame/flame-brand.c",
        "lib/guilds/scion/paths/sword/flame/sweeping-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/searing-blade.c");

    addChild("lib/guilds/scion/paths/sword/flame/searing-blade.c",
        "lib/guilds/scion/paths/sword/flame/flame-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/flaming-edge.c");

    addChild("lib/guilds/scion/paths/sword/flame/flaming-edge.c",
        "lib/guilds/scion/paths/sword/flame/searing-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/ferianths-pommel.c");

    addChild("lib/guilds/scion/paths/sword/flame/ferianths-pommel.c",
        "lib/guilds/scion/paths/sword/flame/flaming-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Flame");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as flame.");

        addResearchElement("lib/guilds/scion/paths/sword/flame/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/flame/root.c");

        FirstLevel();
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
