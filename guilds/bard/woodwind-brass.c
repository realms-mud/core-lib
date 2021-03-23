//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/a-rats-serenade.c");

    addChild("guilds/bard/woodwind-brass/a-rats-serenade.c",
        "guilds/bard/woodwind-brass/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/creatures-of-the-forest.c");
    addResearchElement("guilds/bard/woodwind-brass/the-wailing-cat.c");

    addChild("guilds/bard/woodwind-brass/creatures-of-the-forest.c",
        "guilds/bard/woodwind-brass/root.c");
    addChild("guilds/bard/woodwind-brass/the-wailing-cat.c",
        "guilds/bard/woodwind-brass/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/rous.c");

    addChild("guilds/bard/woodwind-brass/rous.c",
        "guilds/bard/woodwind-brass/a-rats-serenade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/pans-mephit.c");

    addChild("guilds/bard/woodwind-brass/pans-mephit.c",
        "guilds/bard/woodwind-brass/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/mephits-of-malice.c");
    addResearchElement("guilds/bard/woodwind-brass/serenade-to-a-mephit.c");

    addChild("guilds/bard/woodwind-brass/mephits-of-malice.c",
        "guilds/bard/woodwind-brass/pans-mephit.c");
    addChild("guilds/bard/woodwind-brass/serenade-to-a-mephit.c",
        "guilds/bard/woodwind-brass/pans-mephit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/mephit-minstrel.c");

    addChild("guilds/bard/woodwind-brass/mephit-minstrel.c",
        "guilds/bard/woodwind-brass/pans-mephit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/king-rodent.c");

    addChild("guilds/bard/woodwind-brass/king-rodent.c",
        "guilds/bard/woodwind-brass/rous.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/ballad-of-the-bear.c");

    addChild("guilds/bard/woodwind-brass/ballad-of-the-bear.c",
        "guilds/bard/woodwind-brass/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/creatures-of-might.c");

    addChild("guilds/bard/woodwind-brass/creatures-of-might.c",
        "guilds/bard/woodwind-brass/creatures-of-the-forest.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/menace-of-a-mephit.c");

    addChild("guilds/bard/woodwind-brass/menace-of-a-mephit.c",
        "guilds/bard/woodwind-brass/mephit-minstrel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/majestys-mephit.c");

    addChild("guilds/bard/woodwind-brass/majestys-mephit.c",
        "guilds/bard/woodwind-brass/pans-mephit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/lay-of-mephias.c");

    addChild("guilds/bard/woodwind-brass/lay-of-mephias.c",
        "guilds/bard/woodwind-brass/menace-of-a-mephit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/bard/woodwind-brass/denizens-dance.c");

    addChild("guilds/bard/woodwind-brass/denizens-dance.c",
        "guilds/bard/woodwind-brass/creatures-of-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Musical Compositions");
        Description("");
        Source("bard");
        addResearchElement("guilds/bard/woodwind-brass/root.c");
        TreeRoot("guilds/bard/woodwind-brass/root.c");

        FirstLevel();
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SeventhLevel();
        NinthLevel();
        TenthLevel();
        EleventhLevel();
        ThirteenthLevel();
        FifteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentyFirstLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtyFirstLevel();
        ThirtyThirdLevel();
        ThirtyFifthLevel();
        ThirtySeventhLevel();
        FortyThirdLevel();
        FortyFifthLevel();
        FortySeventhLevel();
        FiftyFifthLevel();
        SixtyFifthLevel();
    }
}
