//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/bard/lyrics/inspiring-lyrics.c");
    addResearchElement("/guilds/bard/lyrics/demoralizing-lyrics.c");

    addChild("/guilds/bard/lyrics/inspiring-lyrics.c",
        "/guilds/bard/lyrics/root.c");
    addChild("/guilds/bard/lyrics/demoralizing-lyrics.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/bard/lyrics/muses-melody.c");

    addChild("/guilds/bard/lyrics/muses-melody.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/bard/lyrics/lay-of-landros.c");

    addChild("/guilds/bard/lyrics/lay-of-landros.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/bard/lyrics/daedruns-lament.c");
    addResearchElement("/guilds/bard/lyrics/daedruns-fury.c");

    addChild("/guilds/bard/lyrics/daedruns-lament.c",
        "/guilds/bard/lyrics/root.c");
    addChild("/guilds/bard/lyrics/daedruns-fury.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/bard/lyrics/silver-tongue.c");

    addChild("/guilds/bard/lyrics/silver-tongue.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/bard/lyrics/tune-of-the-muse.c");

    addChild("/guilds/bard/lyrics/tune-of-the-muse.c",
        "/guilds/bard/lyrics/muses-melody.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/bard/lyrics/duelers-dance.c");

    addChild("/guilds/bard/lyrics/duelers-dance.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/bard/lyrics/song-for-aelin.c");

    addChild("/guilds/bard/lyrics/song-for-aelin.c",
        "/guilds/bard/lyrics/lay-of-landros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/bard/lyrics/a-rhyme-of-the-deep.c");

    addChild("/guilds/bard/lyrics/a-rhyme-of-the-deep.c",
        "/guilds/bard/lyrics/lay-of-landros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/bard/lyrics/daedruns-might.c");

    addChild("/guilds/bard/lyrics/daedruns-might.c",
        "/guilds/bard/lyrics/daedruns-lament.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/bard/lyrics/archers-jig.c");
    addResearchElement("/guilds/bard/lyrics/axemans-song.c");
    addResearchElement("/guilds/bard/lyrics/macemans-melody.c");
    addResearchElement("/guilds/bard/lyrics/swordmasters-serenade.c");

    addChild("/guilds/bard/lyrics/archers-jig.c",
        "/guilds/bard/lyrics/duelers-dance.c");
    addChild("/guilds/bard/lyrics/axemans-song.c",
        "/guilds/bard/lyrics/duelers-dance.c");
    addChild("/guilds/bard/lyrics/macemans-melody.c",
        "/guilds/bard/lyrics/duelers-dance.c");
    addChild("/guilds/bard/lyrics/swordmasters-serenade.c",
        "/guilds/bard/lyrics/duelers-dance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/bard/lyrics/danse-macabre.c");

    addChild("/guilds/bard/lyrics/danse-macabre.c",
        "/guilds/bard/lyrics/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/bard/lyrics/boon-of-landros.c");

    addChild("/guilds/bard/lyrics/boon-of-landros.c",
        "/guilds/bard/lyrics/a-rhyme-of-the-deep.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/bard/lyrics/daedruns-sorrow.c");

    addChild("/guilds/bard/lyrics/daedruns-sorrow.c",
        "/guilds/bard/lyrics/daedruns-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/bard/lyrics/boneflower.c");

    addChild("/guilds/bard/lyrics/boneflower.c",
        "/guilds/bard/lyrics/danse-macabre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/bard/lyrics/day-is-coming.c");

    addChild("/guilds/bard/lyrics/day-is-coming.c",
        "/guilds/bard/lyrics/boon-of-landros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/bard/lyrics/daedruns-regret.c");

    addChild("/guilds/bard/lyrics/daedruns-regret.c",
        "/guilds/bard/lyrics/daedruns-sorrow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/bard/lyrics/ballad-of-the-bones.c");

    addChild("/guilds/bard/lyrics/ballad-of-the-bones.c",
        "/guilds/bard/lyrics/boneflower.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/bard/lyrics/bloods-depth.c");

    addChild("/guilds/bard/lyrics/bloods-depth.c",
        "/guilds/bard/lyrics/day-is-coming.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/bard/lyrics/daedruns-despair.c");

    addChild("/guilds/bard/lyrics/daedruns-despair.c",
        "/guilds/bard/lyrics/daedruns-regret.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/bard/lyrics/into-the-dream.c");

    addChild("/guilds/bard/lyrics/into-the-dream.c",
        "/guilds/bard/lyrics/bloods-depth.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Lyrical Components for Compositions");
    Description("");
    Source("bard");
    addResearchElement("/guilds/bard/lyrics/root.c");
    TreeRoot("/guilds/bard/lyrics/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    TenthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FiftyFifthLevel();
}
