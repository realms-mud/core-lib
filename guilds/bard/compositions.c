//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/compositions/aaa.c");
    addResearchElement("guilds/bard/compositions/inspiring-lyrics.c");
    addResearchElement("guilds/bard/compositions/demoralizing-lyrics.c");
    addResearchElement("guilds/bard/compositions/a-rats-serenade.c");

    addChild("guilds/bard/compositions/aaa.c",
        "guilds/bard/compositions/root.c");
    addChild("guilds/bard/compositions/inspiring-lyrics.c",
        "guilds/bard/compositions/root.c");
    addChild("guilds/bard/compositions/demoralizing-lyrics.c",
        "guilds/bard/compositions/root.c");
    addChild("guilds/bard/compositions/a-rats-serenade.c",
        "guilds/bard/compositions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/bard/compositions/aaba.c");
    addResearchElement("guilds/bard/compositions/abab.c");
    addResearchElement("guilds/bard/compositions/abac.c");

    addChild("guilds/bard/compositions/aaba.c",
        "guilds/bard/compositions/aaa.c");
    addChild("guilds/bard/compositions/abab.c",
        "guilds/bard/compositions/aaa.c");
    addChild("guilds/bard/compositions/abac.c",
        "guilds/bard/compositions/aaa.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/bard/compositions/rous.c");

    addChild("guilds/bard/compositions/rous.c",
        "guilds/bard/compositions/a-rats-serenade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/bard/compositions/simple-ballad.c");
    addResearchElement("guilds/bard/compositions/verse-pre-chorus.c");

    addChild("guilds/bard/compositions/simple-ballad.c",
        "guilds/bard/compositions/aaa.c");
    addChild("guilds/bard/compositions/verse-pre-chorus.c",
        "guilds/bard/compositions/abab.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/bard/compositions/verse-chorus-bridge.c");

    addChild("guilds/bard/compositions/verse-chorus-bridge.c",
        "guilds/bard/compositions/abab.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/bard/compositions/silver-tongue.c");

    addChild("guilds/bard/compositions/silver-tongue.c",
        "guilds/bard/compositions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/bard/compositions/king-rodent.c");

    addChild("guilds/bard/compositions/king-rodent.c",
        "guilds/bard/compositions/rous.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/bard/compositions/ababcb.c");

    addChild("guilds/bard/compositions/ababcb.c",
        "guilds/bard/compositions/abab.c");
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
    addResearchElement("guilds/bard/compositions/abacbaa.c");

    addChild("guilds/bard/compositions/abacbaa.c",
        "guilds/bard/compositions/ababcb.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/bard/compositions/freeform.c");

    addChild("guilds/bard/compositions/freeform.c",
        "guilds/bard/compositions/abacbaa.c");
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
        addResearchElement("guilds/bard/compositions/root.c");
        TreeRoot("guilds/bard/compositions/root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SeventhLevel();
        EighthLevel();
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
