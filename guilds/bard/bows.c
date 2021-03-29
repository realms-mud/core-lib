//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/bard/bow/rhyme-of-the-marksman.c");

    addChild("guilds/bard/bow/rhyme-of-the-marksman.c",
        "guilds/bard/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/bard/bow/marksmans-melody.c");

    addChild("guilds/bard/bow/marksmans-melody.c",
        "guilds/bard/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/bard/bow/the-archers-song.c");

    addChild("guilds/bard/bow/the-archers-song.c",
        "guilds/bard/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/bard/bow/dirge-of-the-deft.c");

    addChild("guilds/bard/bow/dirge-of-the-deft.c",
        "guilds/bard/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/bard/bow/archers-hand.c");

    addChild("guilds/bard/bow/archers-hand.c",
        "guilds/bard/bow/the-archers-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/bard/bow/enhanced-sonic-shaft.c");

    addChild("guilds/bard/bow/enhanced-sonic-shaft.c",
        "guilds/bard/bow/the-archers-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/bard/bow/rhythmic-release.c");

    addChild("guilds/bard/bow/rhythmic-release.c",
        "guilds/bard/bow/the-archers-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/bard/bow/song-of-the-swift.c");

    addChild("guilds/bard/bow/song-of-the-swift.c",
        "guilds/bard/bow/archers-hand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/bard/bow/arrows-anthem.c");

    addChild("guilds/bard/bow/arrows-anthem.c",
        "guilds/bard/bow/the-archers-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/bard/bow/ballad-of-the-bow.c");

    addChild("guilds/bard/bow/ballad-of-the-bow.c",
        "guilds/bard/bow/enhanced-sonic-shaft.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/bard/bow/bowmans-form.c");

    addChild("guilds/bard/bow/bowmans-form.c",
        "guilds/bard/bow/rhythmic-release.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/bard/bow/requiem-of-the-quick-draw.c");

    addChild("guilds/bard/bow/requiem-of-the-quick-draw.c",
        "guilds/bard/bow/song-of-the-swift.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/bard/bow/archers-elegy.c");

    addChild("guilds/bard/bow/archers-elegy.c",
        "guilds/bard/bow/ballad-of-the-bow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/bard/bow/bowmans-breath.c");

    addChild("guilds/bard/bow/bowmans-breath.c",
        "guilds/bard/bow/bowmans-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/bard/bow/arrowheads-lament.c");

    addChild("guilds/bard/bow/arrowheads-lament.c",
        "guilds/bard/bow/archers-elegy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/bard/bow/bowmans-pace.c");

    addChild("guilds/bard/bow/bowmans-pace.c",
        "guilds/bard/bow/requiem-of-the-quick-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/bard/bow/shafts-serenade.c");
    addResearchElement("guilds/bard/bow/sonic-volley.c");

    addChild("guilds/bard/bow/shafts-serenade.c",
        "guilds/bard/bow/arrowheads-lament.c");
    addChild("guilds/bard/bow/sonic-volley.c",
        "guilds/bard/bow/arrows-anthem.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/bard/bow/minstrels-aim.c");

    addChild("guilds/bard/bow/minstrels-aim.c",
        "guilds/bard/bow/bowmans-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("guilds/bard/bow/bowmans-tale.c");

    addChild("guilds/bard/bow/bowmans-tale.c",
        "guilds/bard/bow/shafts-serenade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/bard/bow/lay-of-the-archer.c");

    addChild("guilds/bard/bow/lay-of-the-archer.c",
        "guilds/bard/bow/bowmans-tale.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Archery");
        Description("");
        Source("bard");
        addResearchElement("guilds/bard/bow/root.c");
        TreeRoot("guilds/bard/bow/root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
        FifthLevel();
        SeventhLevel();
        NinthLevel();
        TenthLevel();
        EleventhLevel();
        ThirteenthLevel();
        FifteenthLevel();
        SixteenthLevel();
        NineteenthLevel();
        TwentyFirstLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtyFirstLevel();
        ThirtyThirdLevel();
        ThirtySeventhLevel();
    }
}
