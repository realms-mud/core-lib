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
    addResearchElement("guilds/bard/strings/elegy-of-energy.c");
    addResearchElement("guilds/bard/strings/enchanting-ostinato.c");

    addChild("guilds/bard/strings/elegy-of-energy.c",
        "guilds/bard/strings/root.c");
    addChild("guilds/bard/strings/enchanting-ostinato.c",
        "guilds/bard/strings/root.c");
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
    addResearchElement("guilds/bard/strings/tune-of-temerity.c");
    addResearchElement("guilds/bard/strings/sanguine-solo.c");

    addChild("guilds/bard/strings/tune-of-temerity.c",
        "guilds/bard/strings/elegy-of-energy.c");
    addChild("guilds/bard/strings/sanguine-solo.c",
        "guilds/bard/strings/enchanting-ostinato.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/bard/strings/vibrato.c");

    addChild("guilds/bard/strings/vibrato.c",
        "guilds/bard/strings/elegy-of-energy.c");
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
    addResearchElement("guilds/bard/strings/staccato.c");

    addChild("guilds/bard/strings/staccato.c",
        "guilds/bard/strings/vibrato.c");
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
    addResearchElement("guilds/bard/strings/legato.c");

    addChild("guilds/bard/strings/legato.c",
        "guilds/bard/strings/staccato.c");
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
    addResearchElement("guilds/bard/strings/ghost-notes.c");

    addChild("guilds/bard/strings/ghost-notes.c",
        "guilds/bard/strings/legato.c");
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
    addResearchElement("guilds/bard/strings/tremolo.c");

    addChild("guilds/bard/strings/tremolo.c",
        "guilds/bard/strings/ghost-notes.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("guilds/bard/strings/raenas-rhythm.c");

    addChild("guilds/bard/strings/raenas-rhythm.c",
        "guilds/bard/strings/requiem-of-release.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/bard/strings/octave-course.c");

    addChild("guilds/bard/strings/octave-course.c",
        "guilds/bard/strings/tremolo.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("guilds/bard/strings/poly-rhythms.c");

    addChild("guilds/bard/strings/poly-rhythms.c",
        "guilds/bard/strings/octave-course.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("guilds/bard/strings/raenas-lament.c");

    addChild("guilds/bard/strings/raenas-lament.c",
        "guilds/bard/strings/raenas-rhythm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("guilds/bard/strings/two-handed-tapping.c");

    addChild("guilds/bard/strings/two-handed-tapping.c",
        "guilds/bard/strings/poly-rhythms.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("guilds/bard/strings/fluid-arpeggios.c");

    addChild("guilds/bard/strings/fluid-arpeggios.c",
        "guilds/bard/strings/two-handed-tapping.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("guilds/bard/strings/palm-muting.c");

    addChild("guilds/bard/strings/palm-muting.c",
        "guilds/bard/strings/fluid-arpeggios.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("guilds/bard/strings/mixed-mode-playing.c");

    addChild("guilds/bard/strings/mixed-mode-playing.c",
        "guilds/bard/strings/palm-muting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyFirstLevel()
{
    addResearchElement("guilds/bard/strings/chromatic-movement.c");

    addChild("guilds/bard/strings/chromatic-movement.c",
        "guilds/bard/strings/mixed-mode-playing.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
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
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FiftyThirdLevel();
    FiftyNinthLevel();
    SixtyFifthLevel();
    SeventyFirstLevel();
}
