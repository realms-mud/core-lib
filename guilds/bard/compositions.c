//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/compositions/aaa.c");

    addChild("guilds/bard/compositions/aaa.c",
        "guilds/bard/compositions/root.c");
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
private void NinthLevel()
{
    addResearchElement("guilds/bard/compositions/the-inner-muse.c");

    addChild("guilds/bard/compositions/the-inner-muse.c",
        "guilds/bard/compositions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/bard/compositions/ababcb.c");

    addChild("guilds/bard/compositions/ababcb.c",
        "guilds/bard/compositions/abab.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/bard/compositions/the-minstrel.c");

    addChild("guilds/bard/compositions/the-minstrel.c",
        "guilds/bard/compositions/the-inner-muse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/bard/compositions/abacbaa.c");

    addChild("guilds/bard/compositions/abacbaa.c",
        "guilds/bard/compositions/ababcb.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/bard/compositions/advanced-performances.c");

    addChild("guilds/bard/compositions/advanced-performances.c",
        "guilds/bard/compositions/the-inner-muse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/bard/compositions/the-troubador.c");

    addChild("guilds/bard/compositions/the-troubador.c",
        "guilds/bard/compositions/the-minstrel.c");
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
    addResearchElement("guilds/bard/compositions/rejuvinating-performances.c");

    addChild("guilds/bard/compositions/rejuvinating-performances.c",
        "guilds/bard/compositions/advanced-performances.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/bard/compositions/the-composer.c");

    addChild("guilds/bard/compositions/the-composer.c",
        "guilds/bard/compositions/the-troubador.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Musical Compositions");
    Description("");
    Source("bard");
    addResearchElement("guilds/bard/compositions/root.c");
    TreeRoot("guilds/bard/compositions/root.c");

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
}
