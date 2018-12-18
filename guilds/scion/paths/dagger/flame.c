//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/flames.c");
    addResearchElement("lib/guilds/scion/paths/dagger/flame/flameblade.c");

    addChild("lib/guilds/scion/paths/dagger/flame/flames.c",
        "lib/guilds/scion/paths/dagger/flame/root.c");
    addChild("lib/guilds/scion/paths/dagger/flame/flameblade.c",
        "lib/guilds/scion/paths/dagger/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/sweeping-flames.c");

    addChild("lib/guilds/scion/paths/dagger/flame/sweeping-flames.c",
        "lib/guilds/scion/paths/dagger/flame/flameblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/flame-brand.c");

    addChild("lib/guilds/scion/paths/dagger/flame/flame-brand.c",
        "lib/guilds/scion/paths/dagger/flame/sweeping-flames.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/searing-blade.c");

    addChild("lib/guilds/scion/paths/dagger/flame/searing-blade.c",
        "lib/guilds/scion/paths/dagger/flame/flame-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/flaming-edge.c");

    addChild("lib/guilds/scion/paths/dagger/flame/flaming-edge.c",
        "lib/guilds/scion/paths/dagger/flame/searing-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/dagger/flame/ferianths-pommel.c");

    addChild("lib/guilds/scion/paths/dagger/flame/ferianths-pommel.c",
        "lib/guilds/scion/paths/dagger/flame/flaming-edge.c");
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

        addResearchElement("lib/guilds/scion/paths/dagger/flame/root.c");
        TreeRoot("lib/guilds/scion/paths/dagger/flame/root.c");

        FirstLevel();
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
