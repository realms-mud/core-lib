//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/strings/riff-of-report.c");

    addChild("guilds/bard/strings/riff-of-report.c",
        "guilds/bard/strings/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/bard/strings/coronach-of-capitulation.c");

    addChild("guilds/bard/strings/coronach-of-capitulation.c",
        "guilds/bard/strings/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/bard/strings/hammer-ons-and-pull-offs.c");

    addChild("guilds/bard/strings/hammer-ons-and-pull-offs.c",
        "guilds/bard/strings/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/bard/strings/string-bending.c");

    addChild("guilds/bard/strings/string-bending.c",
        "guilds/bard/strings/hammer-ons-and-pull-offs.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/bard/strings/requiem-of-release.c");

    addChild("guilds/bard/strings/requiem-of-release.c",
        "guilds/bard/strings/riff-of-report.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/bard/strings/slide-techniques.c");

    addChild("guilds/bard/strings/slide-techniques.c",
        "guilds/bard/strings/string-bending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/bard/strings/dirge-of-the-damned.c");

    addChild("guilds/bard/strings/dirge-of-the-damned.c",
        "guilds/bard/strings/coronach-of-capitulation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/bard/strings/string-skipping.c");

    addChild("guilds/bard/strings/string-skipping.c",
        "guilds/bard/strings/slide-techniques.c");
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
    addResearchElement("guilds/bard/strings/finger-picking.c");

    addChild("guilds/bard/strings/finger-picking.c",
        "guilds/bard/strings/string-skipping.c");
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
        Name("Stringed Components for Compositions");
        Description("");
        Source("bard");
        addResearchElement("guilds/bard/strings/root.c");
        TreeRoot("guilds/bard/strings/root.c");

        FirstLevel();
        ThirdLevel();
        FifthLevel();
        SeventhLevel();
        NinthLevel();
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
