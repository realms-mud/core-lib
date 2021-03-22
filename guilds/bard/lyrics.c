//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/lyrics/inspiring-lyrics.c");
    addResearchElement("guilds/bard/lyrics/demoralizing-lyrics.c");

    addChild("guilds/bard/lyrics/inspiring-lyrics.c",
        "guilds/bard/lyrics/root.c");
    addChild("guilds/bard/lyrics/demoralizing-lyrics.c",
        "guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/bard/lyrics/daedruns-lament.c");
    addResearchElement("guilds/bard/lyrics/daedruns-fury.c");

    addChild("guilds/bard/lyrics/daedruns-lament.c",
        "guilds/bard/lyrics/root.c");
    addChild("guilds/bard/lyrics/daedruns-fury.c",
        "guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/bard/lyrics/silver-tongue.c");

    addChild("guilds/bard/lyrics/silver-tongue.c",
        "guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/bard/lyrics/daedruns-might.c");

    addChild("guilds/bard/lyrics/daedruns-might.c",
        "guilds/bard/lyrics/daedruns-lament.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/bard/lyrics/daedruns-sorrow.c");

    addChild("guilds/bard/lyrics/daedruns-sorrow.c",
        "guilds/bard/lyrics/daedruns-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
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
    addResearchElement("guilds/bard/lyrics/daedruns-regret.c");

    addChild("guilds/bard/lyrics/daedruns-regret.c",
        "guilds/bard/lyrics/daedruns-sorrow.c");
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
    addResearchElement("guilds/bard/lyrics/daedruns-despair.c");

    addChild("guilds/bard/lyrics/daedruns-despair.c",
        "guilds/bard/lyrics/daedruns-regret.c");
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
        Name("Lyrical Components for Compositions");
        Description("");
        Source("bard");
        addResearchElement("guilds/bard/lyrics/root.c");
        TreeRoot("guilds/bard/lyrics/root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SeventhLevel();
        NinthLevel();
        TenthLevel();
        EleventhLevel();
        TwelfthLevel();
        ThirteenthLevel();
        FifteenthLevel();
        SixteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentyFirstLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtiethLevel();
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
